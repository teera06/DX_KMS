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
#include <EnginePlatform/EngineSound.h>


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
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("Screen");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			// CuttingTest.png texture로도 한장이 로드가 됐고
			// 스프라이트로도 1장짜리로 로드가 된 상황이야.
			std::string FileName = File.GetFileName();

			UEngineSprite::Load(File.GetFullPath());
		}

		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();

			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}
		// 로드폴더는 이렇게 한다고 칩시다.


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

	CreateActor();
}

void AMainTitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('Z'))
	{
		UContentsHelper::StageCount = 1;
		GEngine->ChangeLevel("Loading");
	}

	UEngineSound::Update();
}

void AMainTitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	titleBGM.Off();
}

void AMainTitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	titleBGM = UEngineSound::SoundPlay("MUS_Intro_DontDealWithDevil_Vocal.wav");
	GEngine->CreateLevel<ALoadingGameMode>("Loading");
}

void AMainTitleGameMode::CreateActor()
{
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<AMainTitleActor>("TitleLogo");

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
