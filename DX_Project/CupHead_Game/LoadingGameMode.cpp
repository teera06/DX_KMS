#include "PreCompile.h"
#include "LoadingGameMode.h"
#include "PlayerCommon.h"

#include "LoadActor.h"

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
	
}

void ALoadingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	coolDowntime -= _DeltaTime;
	if (0 > coolDowntime && 1 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("WorldLevel");
		coolDowntime = 6.0f;
		UContentsHelper::StageCount = 2;
	}else if (0 > coolDowntime && 2 == UContentsHelper::StageCount)
	{
		GEngine->ChangeLevel("BossStage1GameMode");
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

	if (1 == UContentsHelper::StageCount)
	{
		{
			UEngineDirectory Dir;
			Dir.MoveToSearchChild("GameResource");
			Dir.Move("Image");
			Dir.Move("World");
			std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
			for (UEngineFile& File : Files)
			{
				// CuttingTest.png texture�ε� ������ �ε尡 �ư�
				// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
				UEngineSprite::Load(File.GetFullPath());
			}

			Dir.Move("Cuphead");
			// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
			std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
			for (size_t i = 0; i < Directorys.size(); i++)
			{
				std::string Name = Directorys[i].GetFolderName();
				UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
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
		GEngine->CreateLevel<AWorldGameMode>("WorldLevel");
	}else if (2 == UContentsHelper::StageCount)
	{
		GEngine->CreateLevel<ABossStage1GameMode>("BossStage1GameMode");
	}


}
