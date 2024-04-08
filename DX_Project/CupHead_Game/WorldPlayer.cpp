#include "PreCompile.h"
#include "WorldPlayer.h"

AWorldPlayer::AWorldPlayer()
{
	WorldPlayerRenderer = CreateDefaultSubObject<USpriteRenderer>("WorldPlayer");
}

AWorldPlayer::~AWorldPlayer()
{
}

void AWorldPlayer::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
	SetActorLocation(FVector(0.0f, 0.0f, -50.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	WorldPlayerRenderer->SetSprite("WorldDiagonalIdle_01.png");
	WorldPlayerRenderer->SetSamplering(ETextureSampling::LINEAR);

	WorldPlayerRenderer->CreateAnimation("DiagonalDownIdle", "DiagonalDownIdle", 0.05f);

	WorldPlayerRenderer->ChangeAnimation("DiagonalDownIdle");
}

void AWorldPlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
