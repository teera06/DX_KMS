#include "PreCompile.h"
#include "LoadingGameMode.h"
#include "ContentsHelper.h"

#include "LoadActor.h"
#include "ScreenEffect.h"

#include "WorldGameMode.h"
#include "BossStage1GameMode.h"
#include <EngineCore/Camera.h>
ALoadingGameMode::ALoadingGameMode()
{
}

ALoadingGameMode::~ALoadingGameMode()
{
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
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
			for (UEngineFile& File : Files)
			{
				// CuttingTest.png texture로도 한장이 로드가 됐고
				// 스프라이트로도 1장짜리로 로드가 된 상황이야.
				UEngineSprite::Load(File.GetFullPath());
			}

			Dir.Move("Cuphead");
			// 로드폴더는 이렇게 한다고 칩시다.
			std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				std::string Name = Directorys[i].GetFolderName();
				UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
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
		GEngine->CreateLevel<AWorldGameMode>("WorldLevel");
	}else if (1 == UContentsHelper::StageCount)
	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Image");
			Dir.Move("PlayCuphead");

			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
			for (UEngineFile& File : Files)
			{
				// CuttingTest.png texture로도 한장이 로드가 됐고
				// 스프라이트로도 1장짜리로 로드가 된 상황이야.
				UEngineSprite::Load(File.GetFullPath());
			}
			// 로드폴더는 이렇게 한다고 칩시다.
			std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				std::string Name = Directorys[i].GetFolderName();
				UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
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

			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
			for (UEngineFile& File : Files)
			{
				// CuttingTest.png texture로도 한장이 로드가 됐고
				// 스프라이트로도 1장짜리로 로드가 된 상황이야.
				UEngineSprite::Load(File.GetFullPath());
			}

			{
				Dir.Move("Crowd");
				// 로드폴더는 이렇게 한다고 칩시다.
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}
			}

			Dir.MoveParent();

			{
				Dir.Move("phase1");
				// 로드폴더는 이렇게 한다고 칩시다.
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}
			}

			Dir.MoveParent();

			{
				Dir.Move("phase2");
				// 로드폴더는 이렇게 한다고 칩시다.
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
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
		GEngine->CreateLevel<ABossStage1GameMode>("BossStage1GameMode");
	}


}
