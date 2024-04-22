#include "PreCompile.h"
#include "LoadingGameMode.h"
#include "ContentsHelper.h"

#include "LoadActor.h"
#include "ScreenEffect.h"

#include "WorldGameMode.h"
#include "BossStage1GameMode.h"
#include "BossStage2GameMode.h"

#include <EngineCore/Camera.h>

std::map<std::string, bool> ALoadingGameMode::LoadMap;

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
	
}

void ALoadingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	coolDowntime -= _DeltaTime;
	if (0 > coolDowntime && 1 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("WorldLevel");
		coolDowntime = 4.0f;
		UContentsHelper::StageCount = 2;
	}else if (0 > coolDowntime && 2 == UContentsHelper::StageCount)
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


	if (1 == UContentsHelper::StageCount)
	{
		WorldLoad();

		if (false == CreateLevelCheck1)
		{
			GEngine->CreateLevel<AWorldGameMode>("WorldLevel");
			CreateLevelCheck1 = true;
		}

	}else if (2 == UContentsHelper::StageCount)
	{
		Boss1Load();

		if (false == CreateLevelCheck2)
		{
			GEngine->CreateLevel<ABossStage1GameMode>("BossStage1GameMode");
			CreateLevelCheck2 = true;
		}

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

void ALoadingGameMode::WorldLoad()
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
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
				UEngineSprite::Load(File.GetFullPath());
			}

			LoadMap["World"] = true;
		}



		Dir.Move("Cuphead");
		// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.

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

		// Ư�� ��������Ʈ�� 
		// Ư�� �ؽ�ó�� ã�Ƽ�
		// ���� ��������Ʈ�� �������� �ʴ´ٸ�
		// �̰� ����ϴ� ���� ������ �ڸ���.
		// �̹� �� �̸��� ���� ��������Ʈ�� �����Ѵ�.
		// �׷��� ������ ��������Ʈ �����ʹ� ����������
		// �ڸ� ��������Ʈ ������ �����Ѵ�.
		//UEngineSprite::
		//UEngineSprite::CreateCutting("CharRun0.png", 0, 6);
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
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
				UEngineSprite::Load(File.GetFullPath());
			}
			// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
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
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
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
		// Ư�� ��������Ʈ�� 
		// Ư�� �ؽ�ó�� ã�Ƽ�
		// ���� ��������Ʈ�� �������� �ʴ´ٸ�
		// �̰� ����ϴ� ���� ������ �ڸ���.
		// �̹� �� �̸��� ���� ��������Ʈ�� �����Ѵ�.
		// �׷��� ������ ��������Ʈ �����ʹ� ����������
		// �ڸ� ��������Ʈ ������ �����Ѵ�.
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
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
				UEngineSprite::Load(File.GetFullPath());
			}

			LoadMap["boss1"] = true;
		}

		{
			Dir.Move("Crowd");

			if (false == LoadMap.contains("Crowd"))
			{
				// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
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
				// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
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
			// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
			if (false == LoadMap.contains("phase2"))
			{
				// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
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
			// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
			if (false == LoadMap.contains("phase3"))
			{
				// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
				std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
				for (size_t i = 0; i < Directorys.size(); i++)
				{
					std::string Name = Directorys[i].GetFolderName();
					UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
				}
				int a = 0;
				LoadMap["phase3"] = true;
			}

			UEngineSprite::CreateCutting("TEMP1.png", 1, 3);
			UEngineSprite::CreateCutting("TEMP2.png", 1, 5);
			//UEngineSprite::CreateCutting("tallfrog_slotman_slot_flash_TEMP.png", 1, 3);
		}
		// Ư�� ��������Ʈ�� 
		// Ư�� �ؽ�ó�� ã�Ƽ�
		// ���� ��������Ʈ�� �������� �ʴ´ٸ�
		// �̰� ����ϴ� ���� ������ �ڸ���.
		// �̹� �� �̸��� ���� ��������Ʈ�� �����Ѵ�.
		// �׷��� ������ ��������Ʈ �����ʹ� ����������
		// �ڸ� ��������Ʈ ������ �����Ѵ�.
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
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
				UEngineSprite::Load(File.GetFullPath());
			}
			// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
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
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
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
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
				UEngineSprite::Load(File.GetFullPath());
			}

			LoadMap["boss2"] = true;
		}

	}
}
