#include "PreCompile.h"
#include "WorldGameMode.h"

#include "ScreenEffect.h"
#include "WorldMap.h"
#include "WorldPlayer.h"
#include "Boss1Start.h"
#include "Boss2Start.h"

#include "ContentsHelper.h"
#include "ContentsENum.h"

#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>

AWorldGameMode::AWorldGameMode()
{
}

AWorldGameMode::~AWorldGameMode()
{
}

void AWorldGameMode::BeginPlay()
{
	Super::BeginPlay();

	UContentsHelper::MapTex = UEngineTexture::FindRes("WorldMap_PixelCheck.png");
	UContentsHelper::MapTexScale = UContentsHelper::MapTex->GetScale();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(1500.0f / 2.0f, -1700.0f / 2.0f, -100.0f));
	GetWorld()->SpawnActor<AWorldPlayer>("WorldPlayer");
	GetWorld()->SpawnActor<ABoss1Start>("Boss1Start");
	GetWorld()->SpawnActor<ABoss2Start>("Boss2Start");
	{
		std::shared_ptr<AWorldMap> Front = GetWorld()->SpawnActor<AWorldMap>("WorldMap");

		float4 TexScale = UContentsHelper::MapTexScale;
		float4 ImageScale = { TexScale.X, TexScale.Y, 0.0f };

		Front->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 100.0f});
		//GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect")->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 0.0f });
	}

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

	{
		// UI를 만들겠다.
		UImage* Image = CreateWidget<UImage>(GetWorld(), "Iris");

		// 언리얼 따라한것
		// 언리얼 안나옵니다.
		Image->AddToViewPort(ERenderOrder::FilterEffect);
		Image->SetSprite("irisA_0000.png");
		Image->SetScale(FVector(1280.0f, 720.0f, 0.0f));
		//Image->SetAutoSize(1.0f, true);

		Image->CreateAnimation("Iris", "Iris", 0.05f,false);
		//Image->SetPosition({ -570.0f, -310.0f });
		Image->ChangeAnimation("Iris");


		// Image->SetScale({200, 200});

		// 화면에 떠야 한다.
		// Image->SetSprite("HPBar");
		// Image->SetScale();
	}
}

void AWorldGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UEngineSound::Update();
}

void AWorldGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	WorldBGM.Off();
}

void AWorldGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	WorldBGM = UEngineSound::SoundPlay("MUS_InkwellIsleOne.wav");
	WorldBGM.Loop();
}
