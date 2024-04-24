#include "PreCompile.h"
#include "PokerChip.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
APokerChip::APokerChip()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("PokerChip");
	PokerChip = CreateDefaultSubObject<USpriteRenderer>("PokerChip");
	PokerChip->SetupAttachment(Root);

	PokerChip->SetOrder(ERenderOrder::ObjectFront);
	PokerChip->SetSprite("devil_ph3_falling_poker_chip_0001.png");
	PokerChip->SetSamplering(ETextureSampling::LINEAR);
	PokerChip->SetAutoSize(1.0f, true);

	PokerChipCollision = CreateDefaultSubObject<UCollision>("PokerChipCollision");
	PokerChipCollision->SetupAttachment(Root);
	PokerChipCollision->SetPosition(FVector(0.0f, 00.0f, 0.0f));
	PokerChipCollision->SetScale(FVector(70.0f, 70.0f, 100.0f));

	PokerChipCollision->SetCollisionGroup(ECollisionOrder::Chip);
	PokerChipCollision->SetCollisionType(ECollisionType::RotBox);

	SetRoot(Root);
}

APokerChip::~APokerChip()
{
}

void APokerChip::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, 500.0f, 5.0f));

	PokerChip->CreateAnimation("PokerChip", "PokerChip", 0.075f);
	
	PokerChip->ChangeAnimation("PokerChip");
}

void APokerChip::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	GroundCheck(_DeltaTime);
}

void APokerChip::GroundCheck(float _DeltaTime)
{
	GravityVector += FVector::Down * Speed * _DeltaTime;

	AddActorLocation(GravityVector*_DeltaTime);

	if (GetActorLocation().iY() <= -300)
	{
		Destroy();
	}
}
