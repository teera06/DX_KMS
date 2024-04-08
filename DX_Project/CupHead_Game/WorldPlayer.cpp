#include "PreCompile.h"
#include "WorldPlayer.h"

AWorldPlayer::AWorldPlayer()
{
	WorldPlayerRenderer = CreateDefaultSubObject<USpriteRenderer>("WorldPlayer");
	InputOn();
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
	float Speed = 100.0f;

	if (true == IsPress('A'))
	{
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == IsPress('D'))
	{
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}

	if (true == IsPress('W'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}

	if (true == IsPress('S'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_NUMPAD1))
	{
		// AddActorRotation(float4{0.0f, 0.0f, 1.0f} * 360.0f * _DeltaTime);
		// Color.X += _DeltaTime;
	}
}
