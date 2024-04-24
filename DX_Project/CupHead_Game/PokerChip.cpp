#include "PreCompile.h"
#include "PokerChip.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "DevilPlatform.h"

APokerChip::APokerChip()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("PokerChip");
	PokerChip = CreateDefaultSubObject<USpriteRenderer>("PokerChip");
	PokerChip->SetupAttachment(Root);

	PokerChip->SetOrder(ERenderOrder::FrontSkill);
	PokerChip->SetSprite("devil_ph3_falling_poker_chip_0001.png");
	PokerChip->SetSamplering(ETextureSampling::LINEAR);
	PokerChip->SetAutoSize(1.0f, true);

	Effect = CreateDefaultSubObject<USpriteRenderer>("Effect");
	Effect->SetupAttachment(Root);

	Effect->SetOrder(ERenderOrder::ObjectFront);
	Effect->SetSprite("devil_ph3_falling_poker_chip_fire_0002.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
	Effect->SetAutoSize(1.0f, true);
	Effect->SetPosition(FVector(0.0f, 60.0f, 0.0f));

	PokerChipCollision = CreateDefaultSubObject<UCollision>("PokerChipCollision");
	PokerChipCollision->SetupAttachment(Root);
	PokerChipCollision->SetPosition(FVector(0.0f, 00.0f, 0.0f));
	PokerChipCollision->SetScale(FVector(100.0f, 60.0f, 100.0f));

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

	PokerChip->CreateAnimation("PokerChip", "PokerChip", 0.075f);
	Effect->CreateAnimation("BurningChip", "BurningChip", 0.075f);
	
	Effect->ChangeAnimation("BurningChip");
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

	//PokerChipCollision->CollisionStay(ECollisionOrder::Boss2Object1, [=](std::shared_ptr<UCollision> _Collison)
	//{
		//Destroy();
	//});

}
