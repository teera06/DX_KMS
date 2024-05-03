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
	
	if (false == CreateLevelCheck3)
	{
		LastBoss2Load();
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
	else if (true == CreateLevelCheck3 && 3 == UContentsHelper::StageCount)
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
		MainBoss2Load();
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

	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Sound\\Player");
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
			for (UEngineFile& File : Files)
			{
				File.Open(EIOOpenMode::Read, EIODataType::Binary);

				char Arr[100];
				File.Read(Arr, 100);

				UEngineSound::Load(File.GetFullPath());
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

		UEngineSprite::CreateCutting("Boss1Zone.png", 3, 1);
		UEngineSprite::CreateCutting("DevilZone.png", 3, 1);
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


	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Sound\\Boss1Sound");
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".mp3" });
			for (UEngineFile& File : Files)
			{
				File.Open(EIOOpenMode::Read, EIODataType::Binary);

				char Arr[100];
				File.Read(Arr, 100);

				UEngineSound::Load(File.GetFullPath());
			}
		}
	}

	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Sound\\Boss1Sound");
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
			for (UEngineFile& File : Files)
			{
				File.Open(EIOOpenMode::Read, EIODataType::Binary);

				char Arr[100];
				File.Read(Arr, 100);

				UEngineSound::Load(File.GetFullPath());
			}
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



void ALoadingGameMode::MainBoss2Load()
{
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("boss2");

		if (false == LoadMap.contains("boss2"))
		{
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
			MainLoadCount3 = static_cast<int>(Files.size());
			for (UEngineFile& File : Files)
			{
				GEngine->JobWorker.Work([=]()
					{

						UEngineSprite::ThreadSafeLoad(File.GetFullPath());

						--MainLoadCount3;
					});
			}

			LoadMap["boss2"] = true;
		}
	}

	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Sound\\Boss2Sound");
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
			for (UEngineFile& File : Files)
			{
				File.Open(EIOOpenMode::Read, EIODataType::Binary);

				char Arr[100];
				File.Read(Arr, 100);

				UEngineSound::Load(File.GetFullPath());
			}
		}
	}
}

void ALoadingGameMode::FolderBoss2Load()
{
	UEngineDirectory Dir;
	Dir.MoveToSearchChild("GameResource");
	Dir.Move("Image");
	Dir.Move("boss2");


	{
		Dir.Move("2phase1");

		if (false == LoadMap.contains("2phase1"))
		{
			// 로드폴더는 이렇게 한다고 칩시다.
			std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
			SubFolder2Count = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--SubFolder2Count;
					});
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
			SubFolder2Count2 = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--SubFolder2Count2;
					});
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
			SubFolder2Count3 = static_cast<int>(Directorys.size());
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				GEngine->JobWorker.Work([=]()
					{
						UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

						--SubFolder2Count3;
					});
			}

			LoadMap["2phase3"] = true;
		}
	}

	UEngineSprite::CreateCutting("BossDevil_Phase1Background.png", 1, 6);
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

void ALoadingGameMode::LastBoss2Load()
{
	if (0 == MainLoadCount3 && false == CreateLevelCheck3)
	{
		MainLoadCount3 = -1;
		FolderBoss2Load();
	}

	if (SubFolder2Count == 0 && SubFolder2Count2 == 0 && SubFolder2Count3 == 0 && false == CreateLevelCheck3)
	{
		SubFolder2Count = -1;
		SubFolder2Count2 = -1;
		SubFolder2Count3 = -1;
		GEngine->CreateLevel<ABossStage2GameMode>("BossStage2GameMode");
		CreateLevelCheck3 = true;
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
