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


	CreateActor();
	GEngine->CreateLevel<ALoadingGameMode>("Loading");
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
	ScreenBGM = UEngineSound::SoundPlay("OpticalLoop.wav");
	ScreenBGM.Loop();
	titleBGM = UEngineSound::SoundPlay("MUS_Intro_DontDealWithDevil_Vocal.wav");
	titleBGM.Loop();
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
