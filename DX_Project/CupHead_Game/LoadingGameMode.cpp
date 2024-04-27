#include "PreCompile.h"
#include "LoadingGameMode.h"

#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>
#include <EngineCore/BlurEffect.h>

#include "ContentsHelper.h"
#include "ContentsENum.h"

#include "LoadActor.h"
#include "ScreenEffect.h"

#include "WorldGameMode.h"
#include "BossStage1GameMode.h"
#include "BossStage2GameMode.h"

std::map<std::string, bool> ALoadingGameMode::LoadMap;

bool ALoadingGameMode::CreatePlayer = false;
bool ALoadingGameMode::CreateLevelCheck1=false;
bool ALoadingGameMode::CreateLevelCheck2=false;
bool ALoadingGameMode::CreateLevelCheck3 = false;

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
	//GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");

	{
		// UI를 만들겠다.
		UImage* Image = CreateWidget<UImage>(GetWorld(), "OldFilter");

		// 언리얼 따라한것
		// 언리얼 안나옵니다.
		Image->AddToViewPort(ERenderOrder::Filter);
		Image->SetSprite("cuphead_screen_fx_0000.png");
		Image->SetScale(FVector(1280.0f, 720.0f, 0.0f));
		//Image->SetAutoSize(1.0f, true);

		Image->CreateAnimation("OldFilmEffect", "OldFilmEffect", 0.05f);
		//Image->SetPosition({ -570.0f, -310.0f });
		Image->ChangeAnimation("OldFilmEffect");



		// Image->SetScale({200, 200});

		// 화면에 떠야 한다.
		// Image->SetSprite("HPBar");
		// Image->SetScale();
	}
	GetWorld()->GetLastTarget()->AddEffect<UBlurEffect>();
}

void ALoadingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	LastPlayerLoad();

	if (false == CreateLevelCheck1)
	{
		LastWorldLoad();
	}

	if (false == CreateLevelCheck2)
	{
		LastBoss1Load();
	}
	

	coolDowntime -= _DeltaTime;
	if (true== CreateLevelCheck1 && 1 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("WorldLevel");
		coolDowntime = 4.0f;
		//UContentsHelper::StageCount = 2;
	}else if (true == CreateLevelCheck2 && 2 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("BossStage1GameMode");
		coolDowntime = 4.0f;
		//UPlayerCommon::StageCount = 2;
	}
	else if (0 > coolDowntime && 3 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("BossStage2GameMode");
		coolDowntime = 4.0f;
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

	if (false == CreatePlayer)
	{
		MainPlayerLoad();
	}

	if (1 == UContentsHelper::StageCount && false == CreateLevelCheck1)
	{
		MainWorldLoad();

	}else if (2 == UContentsHelper::StageCount && false == CreateLevelCheck2)
	{
		MainBoss1Load();
	}
	else if (3 == UContentsHelper::StageCount)
	{
		Boss2Load();

		if (false == CreateLevelCheck3)
		{
			GEngine->CreateLevel<ABossStage2GameMode>("BossStage2GameMode");
			CreateLevelCheck3 = true;
		}
	}


}

void ALoadingGameMode::MainPlayerLoad()
{
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("PlayCuphead");
		{
			if (false == LoadMap.contains("PlayCuphead"))
			{
				std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
				CommonCount1 = static_cast<int>(Files.size());
				for (UEngineFile& File : Files)
				{
					GEngine->JobWorker.Work([=]()
						{

							UEngineSprite::ThreadSafeLoad(File.GetFullPath());

							--CommonCount1;
						});
				}

				LoadMap["PlayCuphead"] = true;
			}
		}

		Dir.MoveParent();
		Dir.Move("Bullet");

		{
			if (false == LoadMap.contains("Bullet"))
			{
				std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
				CommonCount2 = static_cast<int>(Files.size());
				for (UEngineFile& File : Files)
				{
					GEngine->JobWorker.Work([=]()
						{

							UEngineSprite::ThreadSafeLoad(File.GetFullPath());

							--CommonCount2;
						});
				}
				LoadMap["Bullet"] = true;
			}
		}
	}
}

void ALoadingGameMode::PlayerFolderLoad()
{
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("GameResource");
	Dir.Move("Image");
	Dir.Move("PlayCuphead");
	{
		if (true == LoadMap.contains("PlayCuphead"))
		{
			std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
			CommonSubLoad1 = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--CommonSubLoad1;
					});
			}
		}
	}

	Dir.MoveParent();
	Dir.Move("Bullet");

	{
		if (true == LoadMap.contains("Bullet"))
		{
			std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
			CommonSubLoad2 = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--CommonSubLoad2;
					});
			}
		}
	}
}

void ALoadingGameMode::MainWorldLoad()
{
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("GameResource");
	Dir.Move("Image");
	Dir.Move("World");

	if (false == LoadMap.contains("World"))
	{
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		MainLoadCount2= static_cast<int>(Files.size());
		for (UEngineFile& File : Files)
		{
			// CuttingTest.png texture로도 한장이 로드가 됐고
			// 스프라이트로도 1장짜리로 로드가 된 상황이야.
			GEngine->JobWorker.Work([=]()
				{

					UEngineSprite::ThreadSafeLoad(File.GetFullPath());

					--MainLoadCount2;
				});
		}

		LoadMap["World"] = true;
	}
}

void ALoadingGameMode::FolderWorldLoad()
{
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("GameResource");
	Dir.Move("Image");
	Dir.Move("World");
	Dir.Move("Cuphead");

	// 로드폴더는 이렇게 한다고 칩시다.

	if (false == LoadMap.contains("Cuphead"))
	{
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		SubWorldCount= static_cast<int>(Directorys.size());
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GEngine->JobWorker.Work([=]()
				{
					UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

					--SubWorldCount;
				});
		}

		LoadMap["Cuphead"] = true;
	}

}

void ALoadingGameMode::MainBoss1Load()
{

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("boss1");

		if (false == LoadMap.contains("boss1"))
		{
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
			MainLoadCount = static_cast<int>(Files.size());
			for (UEngineFile& File : Files)
			{
				GEngine->JobWorker.Work([=]()
					{

						UEngineSprite::ThreadSafeLoad(File.GetFullPath());

						--MainLoadCount;
					});
			}

			LoadMap["boss1"] = true;
		}
	}


}

void ALoadingGameMode::FolderBoss1Load()
{
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("GameResource");
	Dir.Move("Image");
	Dir.Move("boss1");

	{
		Dir.Move("Crowd");

		if (false == LoadMap.contains("Crowd"))
		{
			// 로드폴더는 이렇게 한다고 칩시다.
			std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
			SubFolderCount = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--SubFolderCount;
					});
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
			SubFolderCount2 = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--SubFolderCount2;
					});
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
			SubFolderCount3 = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--SubFolderCount3;
					});
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
			SubFolderCount4 = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--SubFolderCount4;
					});
			}
			LoadMap["phase3"] = true;
		}

		//UEngineSprite::CreateCutting("TEMP1.png", 1, 3);
		UEngineSprite::CreateCutting("TEMP2.png", 1, 5);
		//UEngineSprite::CreateCutting("tallfrog_slotman_slot_flash_TEMP.png", 1, 3);
	}
}



void ALoadingGameMode::Folder1Help2()
{

}


void ALoadingGameMode::LastWorldLoad()
{
	if (0 == MainLoadCount2 && false == CreateLevelCheck1)
	{
		MainLoadCount2 = -1;
		FolderWorldLoad();
	}

	if (0==SubWorldCount && false == CreateLevelCheck1)
	{
		SubWorldCount = -1;
		GEngine->CreateLevel<AWorldGameMode>("WorldLevel");
		CreateLevelCheck1 = true;
	}
}

void ALoadingGameMode::LastBoss1Load()
{
	if (0 == MainLoadCount && false == CreateLevelCheck2)
	{
		MainLoadCount = -1;
		FolderBoss1Load();
	}

	if (SubFolderCount == 0 && SubFolderCount2 == 0 && SubFolderCount3 == 0 && SubFolderCount4 == 0 && false == CreateLevelCheck2)
	{
		SubFolderCount = -1;
		SubFolderCount2 = -1;
		SubFolderCount3 = -1;
		SubFolderCount4 = -1;
		GEngine->CreateLevel<ABossStage1GameMode>("BossStage1GameMode");
		CreateLevelCheck2 = true;
	}
}

void ALoadingGameMode::LastPlayerLoad()
{
	if (0 == CommonCount1 && 0 == CommonCount2 && false == CreatePlayer)
	{
		CommonCount1 = -1;
		CommonCount2 = -1;
		PlayerFolderLoad();
	}

	if (CommonSubLoad1 == 0 && CommonSubLoad2==0 && false == CreatePlayer)
	{
		CommonSubLoad1 = -1;
		CommonSubLoad2 = -1;
		CreatePlayer = true;
	}
}

void ALoadingGameMode::Boss1Load()
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

			//UEngineSprite::CreateCutting("TEMP1.png", 1, 3);
			UEngineSprite::CreateCutting("TEMP2.png", 1, 5);
			//UEngineSprite::CreateCutting("tallfrog_slotman_slot_flash_TEMP.png", 1, 3);
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
}

void ALoadingGameMode::Boss2Load()
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
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("boss2");

		if (false == LoadMap.contains("boss2"))
		{
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
			for (UEngineFile& File : Files)
			{
				// CuttingTest.png texture로도 한장이 로드가 됐고
				// 스프라이트로도 1장짜리로 로드가 된 상황이야.
				UEngineSprite::Load(File.GetFullPath());
			}

			LoadMap["boss2"] = true;
		}

		UEngineSprite::CreateCutting("BossDevil_Phase1Background.png", 1, 6);

		{
			Dir.Move("2phase1");

			if (false == LoadMap.contains("2phase1"))
			{
				// 로드폴더는 이렇게 한다고 칩시다.
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}

				LoadMap["2phase1"] = true;
			}
		}

		Dir.MoveParent();

		{
			Dir.Move("2phase2");

			if (false == LoadMap.contains("2phase2"))
			{
				// 로드폴더는 이렇게 한다고 칩시다.
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}

				LoadMap["2phase2"] = true;
			}
		}

		Dir.MoveParent();

		{
			Dir.Move("2phase3");

			if (false == LoadMap.contains("2phase3"))
			{
				// 로드폴더는 이렇게 한다고 칩시다.
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}

				LoadMap["2phase3"] = true;
			}
		}
	}
}
