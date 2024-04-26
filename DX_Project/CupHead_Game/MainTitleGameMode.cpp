#include "PreCompile.h"
#include "ContentsHelper.h"
#include "MainTitleGameMode.h"


#include "MainTitleActor.h"
#include "ScreenEffect.h"
#include "ContentsENum.h"

#include "LoadingGameMode.h"
#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>
#include <EngineCore/BlurEffect.h>


AMainTitleGameMode::AMainTitleGameMode()
{
}

AMainTitleGameMode::~AMainTitleGameMode()
{
}

void AMainTitleGameMode::BeginPlay()
{
	Super::BeginPlay();


	{
		// ������ ���
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("Screen");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		LoadingCount1 = static_cast<int>(Files.size());
		for (UEngineFile& File : Files)
		{
			// CuttingTest.png texture�ε� ������ �ε尡 �ư�
			// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
			std::string FileName = File.GetFileName();

			GEngine->JobWorker.Work([=]()
			{

				UEngineSprite::ThreadSafeLoad(File.GetFullPath());

				--LoadingCount1;
			});
		}


		// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.


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

void AMainTitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == onecheck)
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("Screen");
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		LoadingCount2 = static_cast<int>(Directorys.size());
		onecheck = true;
	}

	if (LoadingCount1 == 0)
	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("Screen");
		LoadingCount1 = 100;
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();

			int a = LoadingCount2;
			GEngine->JobWorker.Work([=]()
			{
				UEngineSprite::ThreadSafeLoadFolder(Directorys[i].GetFullPath());

				--LoadingCount2;
			});
		}
	}

	if (0 == LoadingCount2)
	{
		CreateActor();
		GEngine->CreateLevel<ALoadingGameMode>("Loading");
		LoadingCount2 = 2000;
	}

	if (true == UEngineInput::IsDown('Z'))
	{
		UContentsHelper::StageCount = 1;
		//GEngine->ChangeLevel("Loading");
	}
}

void AMainTitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AMainTitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	//GEngine->CreateLevel<ALoadingGameMode>("Loading");
}

void AMainTitleGameMode::CreateActor()
{
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<AMainTitleActor>("TitleLogo");

	{
		// UI�� ����ڴ�.
		UImage* Image = CreateWidget<UImage>(GetWorld(), "OldFilter");

		// �𸮾� �����Ѱ�
		// �𸮾� �ȳ��ɴϴ�.
		Image->AddToViewPort(ERenderOrder::Filter);
		Image->SetSprite("cuphead_screen_fx_0000.png");
		Image->SetScale(FVector(1280.0f, 720.0f, 0.0f));
		//Image->SetAutoSize(1.0f, true);

		Image->CreateAnimation("OldFilmEffect", "OldFilmEffect", 0.05f);
		//Image->SetPosition({ -570.0f, -310.0f });
		Image->ChangeAnimation("OldFilmEffect");



		// Image->SetScale({200, 200});

		// ȭ�鿡 ���� �Ѵ�.
		// Image->SetSprite("HPBar");
		// Image->SetScale();
	}

	GetWorld()->GetLastTarget()->AddEffect<UBlurEffect>();
}
