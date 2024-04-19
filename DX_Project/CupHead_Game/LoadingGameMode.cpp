#include "PreCompile.h"
#include "LoadingGameMode.h"
#include "ContentsHelper.h"

#include "LoadActor.h"
#include "ScreenEffect.h"

#include "WorldGameMode.h"
#include "BossStage1GameMode.h"
#include <EngineCore/Camera.h>

std::map<std::string, bool> ALoadingGameMode::LoadMap;

bool ALoadingGameMode::CreateLevelCheck1=false;
bool ALoadingGameMode::CreateLevelCheck2=false;

ALoadingGameMode::ALoadingGameMode()
{
}

ALoadingGameMode::~ALoadingGameMode()
{
	LoadMap.clear();
}

void ALoadingGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ALoadActor>("timmer");
	GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");
	
}

void ALoadingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	coolDowntime -= _DeltaTime;
	if (0 > coolDowntime && 1 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("BossStage1GameMode");
		coolDowntime = 6.0f;
		UContentsHelper::StageCount = 2;
	}else if (0 > coolDowntime && 2 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("WorldLevel");
		//coolDowntime = 6.0f;
		//UPlayerCommon::StageCount = 2;
	}
}

void ALoadingGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ALoadingGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);


	if (2 == UContentsHelper::StageCount)
	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Image");
			Dir.Move("World");

			if (false == LoadMap.contains("World"))
			{
				std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
				for (UEngineFile& File : Files)
				{
					// CuttingTest.png texture로도 한장이 로드가 됐고
					// 스프라이트로도 1장짜리로 로드가 된 상황이야.
					UEngineSprite::Load(File.GetFullPath());
				}

				LoadMap["World"] = true;
			}



			Dir.Move("Cuphead");
			// 로드폴더는 이렇게 한다고 칩시다.

			if (false == LoadMap.contains("Cuphead"))
			{
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}

				LoadMap["Cuphead"] = true;
			}

			// 특정 스프라이트나 
			// 특정 텍스처를 찾아서
			// 만약 스프라이트가 존재하지 않는다면
			// 이걸 사용하는 순간 만들어내고 자른다.
			// 이미 이 이름을 가진 스프라이트가 존재한다.
			// 그러면 기존의 스프라이트 데이터는 날려버리고
			// 자른 스프라이트 데이터 변경한다.
			//UEngineSprite::
			//UEngineSprite::CreateCutting("CharRun0.png", 0, 6);
		}

		if (false == CreateLevelCheck1)
		{
			GEngine->CreateLevel<AWorldGameMode>("WorldLevel");
			CreateLevelCheck1 = true;
		}

	}else if (1 == UContentsHelper::StageCount)
	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Image");
			Dir.Move("PlayCuphead");

			if (false == LoadMap.contains("PlayCuphead"))
			{
				std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
				for (UEngineFile& File : Files)
				{
					// CuttingTest.png texture로도 한장이 로드가 됐고
					// 스프라이트로도 1장짜리로 로드가 된 상황이야.
					UEngineSprite::Load(File.GetFullPath());
				}
				// 로드폴더는 이렇게 한다고 칩시다.
				{
					std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
					for (size_t i = 0; i < Directorys.size(); i++)
					{
						std::string Name = Directorys[i].GetFolderName();
						UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
					}
				}

				LoadMap["PlayCuphead"] = true;
			}
			

			Dir.MoveParent();
			Dir.Move("Bullet");

			if (false == LoadMap.contains("Bullet"))
			{
				std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
				for (UEngineFile& File : Files)
				{
					// CuttingTest.png texture로도 한장이 로드가 됐고
					// 스프라이트로도 1장짜리로 로드가 된 상황이야.
					UEngineSprite::Load(File.GetFullPath());
				}

				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}

				LoadMap["Bullet"] = true;
			}
			// 특정 스프라이트나 
			// 특정 텍스처를 찾아서
			// 만약 스프라이트가 존재하지 않는다면
			// 이걸 사용하는 순간 만들어내고 자른다.
			// 이미 이 이름을 가진 스프라이트가 존재한다.
			// 그러면 기존의 스프라이트 데이터는 날려버리고
			// 자른 스프라이트 데이터 변경한다.
			//UEngineSprite::
			//UEngineSprite::CreateCutting("CharRun0.png", 0, 6);
		}

		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Image");
			Dir.Move("boss1");

			if (false == LoadMap.contains("boss1"))
			{
				std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
				for (UEngineFile& File : Files)
				{
					// CuttingTest.png texture로도 한장이 로드가 됐고
					// 스프라이트로도 1장짜리로 로드가 된 상황이야.
					UEngineSprite::Load(File.GetFullPath());
				}

				LoadMap["boss1"] = true;
			}
		
			{
				Dir.Move("Crowd");

				if (false == LoadMap.contains("Crowd"))
				{
					// 로드폴더는 이렇게 한다고 칩시다.
					std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
					for (size_t i = 0; i < Directorys.size(); i++)
					{
						std::string Name = Directorys[i].GetFolderName();
						UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
					}

					LoadMap["Crowd"] = true;
				}
			}

			Dir.MoveParent();

			{
				Dir.Move("phase1");

				if (false == LoadMap.contains("phase1"))
				{
					// 로드폴더는 이렇게 한다고 칩시다.
					std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
					for (size_t i = 0; i < Directorys.size(); i++)
					{
						std::string Name = Directorys[i].GetFolderName();
						UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
					}

					LoadMap["phase1"] = true;
				}
			}

			Dir.MoveParent();

			{
				Dir.Move("phase2");
				// 로드폴더는 이렇게 한다고 칩시다.
				if (false == LoadMap.contains("phase2"))
				{
					// 로드폴더는 이렇게 한다고 칩시다.
					std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
					for (size_t i = 0; i < Directorys.size(); i++)
					{
						std::string Name = Directorys[i].GetFolderName();
						UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
					}

					LoadMap["phase2"] = true;
				}
			}

			Dir.MoveParent();

			{
				Dir.Move("phase3");
				// 로드폴더는 이렇게 한다고 칩시다.
				if (false == LoadMap.contains("phase3"))
				{
					// 로드폴더는 이렇게 한다고 칩시다.
					std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
					for (size_t i = 0; i < Directorys.size(); i++)
					{
						std::string Name = Directorys[i].GetFolderName();
						UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
					}
					int a = 0;
					LoadMap["phase3"] = true;
				}
			}
			// 특정 스프라이트나 
			// 특정 텍스처를 찾아서
			// 만약 스프라이트가 존재하지 않는다면
			// 이걸 사용하는 순간 만들어내고 자른다.
			// 이미 이 이름을 가진 스프라이트가 존재한다.
			// 그러면 기존의 스프라이트 데이터는 날려버리고
			// 자른 스프라이트 데이터 변경한다.
			//UEngineSprite::
			//UEngineSprite::CreateCutting("CharRun0.png", 0, 6);
		}

		if (false == CreateLevelCheck2)
		{
			GEngine->CreateLevel<ABossStage1GameMode>("BossStage1GameMode");
			CreateLevelCheck2 = true;
		}

	}


}
