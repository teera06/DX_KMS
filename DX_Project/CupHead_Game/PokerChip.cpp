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


	picec1 = CreateDefaultSubObject<USpriteRenderer>("picec1");
	picec1->SetupAttachment(Root);
	
	picec1->SetOrder(ERenderOrder::FrontSkill);
	picec1->SetSprite("devil_ph3_poker_chip_piece_a_0001.png");
	picec1->SetSamplering(ETextureSampling::LINEAR);
	picec1->SetAutoSize(1.0f, true);


	picec2 = CreateDefaultSubObject<USpriteRenderer>("picec2");
	picec2->SetupAttachment(Root);
	
	picec2->SetOrder(ERenderOrder::FrontSkill);
	picec2->SetSprite("devil_ph3_poker_chip_piece_b_0001.png");
	picec2->SetSamplering(ETextureSampling::LINEAR);
	picec2->SetAutoSize(1.0f, true);

	picec3 = CreateDefaultSubObject<USpriteRenderer>("picec3");
	picec3->SetupAttachment(Root);

	picec3->SetOrder(ERenderOrder::FrontSkill);
	picec3->SetSprite("devil_ph3_poker_chip_piece_c_0001.png");
	picec3->SetSamplering(ETextureSampling::LINEAR);
	picec3->SetAutoSize(1.0f, true);

	picec4 = CreateDefaultSubObject<USpriteRenderer>("picec4");
	picec4->SetupAttachment(Root);
	
	picec4->SetOrder(ERenderOrder::FrontSkill);
	picec4->SetSprite("devil_ph3_poker_chip_piece_d_0001.png");
	picec4->SetSamplering(ETextureSampling::LINEAR);
	picec4->SetAutoSize(1.0f, true);

	PokerChipCollision = CreateDefaultSubObject<UCollision>("PokerChipCollision");
	PokerChipCollision->SetupAttachment(Root);
	//PokerChipCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));
	PokerChipCollision->SetScale(FVector(100.0f, 60.0f, 100.0f));

	PokerChipCollision->SetCollisionGroup(ECollisionOrder::Chip);
	PokerChipCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);


	picec1->SetActive(false);
	picec2->SetActive(false);
	picec3->SetActive(false);
	picec4->SetActive(false);
}

APokerChip::~APokerChip()
{
}

void APokerChip::BeginPlay()
{
	Super::BeginPlay();

	PokerChip->CreateAnimation("PokerChip", "PokerChip", 0.075f);
	Effect->CreateAnimation("BurningChip", "BurningChip", 0.075f);
	
	picec1->CreateAnimation("ChipPiece0", "ChipPiece0", 0.075f);
	picec2->CreateAnimation("ChipPiece1", "ChipPiece1", 0.075f);
	picec3->CreateAnimation("ChipPiece2", "ChipPiece2", 0.075f);
	picec4->CreateAnimation("ChipPiece3", "ChipPiece3", 0.075f);

	Effect->ChangeAnimation("BurningChip");
	PokerChip->ChangeAnimation("PokerChip");
	picec1->ChangeAnimation("ChipPiece0");
	picec2->ChangeAnimation("ChipPiece1");
	picec3->ChangeAnimation("ChipPiece2");
	picec4->ChangeAnimation("ChipPiece3");
}

void APokerChip::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CollisionCheck();
	GroundCheck(_DeltaTime);
}

void APokerChip::GroundCheck(float _DeltaTime)
{
	GravityVector += FVector::Down * Speed * _DeltaTime;

	AddActorLocation(GravityVector*_DeltaTime);

	if (GetActorLocation().iY() <= -500)
	{
		Destroy();
	}

}

void APokerChip::CollisionCheck()
{
	PokerChipCollision->CollisionEnter(ECollisionOrder::Boss2Object1, [=](std::shared_ptr<UCollision> _Collison)
	{
		Effect->SetActive(false);
		PokerChip->SetActive(false);
		
		picec1->SetActive(true);
		picec2->SetActive(true);
		picec3->SetActive(true);
		picec4->SetActive(true);
	});
}
