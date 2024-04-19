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

		if (false == CreateLevelCheck2)
		{
			GEngine->CreateLevel<ABossStage1GameMode>("BossStage1GameMode");
			CreateLevelCheck2 = true;
		}

	}


}
