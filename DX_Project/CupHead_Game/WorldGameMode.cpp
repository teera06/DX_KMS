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
#include <EngineCore/BlurEffect.h>

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
	GetWorld()->GetLastTarget()->AddEffect<UBlurEffect>();

	{
		std::shared_ptr<AWorldMap> Front = GetWorld()->SpawnActor<AWorldMap>("WorldMap");

		float4 TexScale = UContentsHelper::MapTexScale;
		float4 ImageScale = { TexScale.X, TexScale.Y, 0.0f };

		Front->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 100.0f});
		//GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect")->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 0.0f });
	}

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
}

void AWorldGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == OneCheck)
	{
		std::shared_ptr<AScreenEffect> NewScreen = GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");
		NewScreen->SetActorLocation(AWorldPlayer::GetPlayerPos());
		NewScreen->SetScreenEffect(EScreenEffect::Iris2);
		OneCheck = true;
	}
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
	std::shared_ptr<AScreenEffect> NewScreen = GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");
	NewScreen->SetActorLocation(AWorldPlayer::GetPlayerPos());
	NewScreen->SetScreenEffect(EScreenEffect::Iris2);

	WorldBGM = UEngineSound::SoundPlay("MUS_InkwellIsleOne.wav");
	WorldBGM.Loop();
}
