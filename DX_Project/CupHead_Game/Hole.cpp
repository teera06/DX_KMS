#include "PreCompile.h"
#include "Hole.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "ContentsHelper.h"


AHole::AHole()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("HoleBack");
	HoleBack = CreateDefaultSubObject<USpriteRenderer>("HoleBack");
	HoleBack->SetupAttachment(Root);

	HoleBack->SetOrder(ERenderOrder::backSkill);
	HoleBack->SetSprite("devil_ph1_floor_hole_back_0001.png");
	HoleBack->SetSamplering(ETextureSampling::LINEAR);
	HoleBack->SetAutoSize(1.0f, true);

	HoleFront = CreateDefaultSubObject<USpriteRenderer>("HoleBack");
	HoleFront->SetupAttachment(Root);

	HoleFront->SetOrder(ERenderOrder::FrontSkill);
	HoleFront->SetSprite("devil_ph1_floor_hole_front_0001.png");
	HoleFront->SetSamplering(ETextureSampling::LINEAR);
	HoleFront->SetAutoSize(1.0f, true);

	HoleSign = CreateDefaultSubObject<USpriteRenderer>("HoleSign");
	HoleSign->SetupAttachment(Root);
	
	HoleSign->SetOrder(ERenderOrder::backSkill);
	HoleSign->SetSprite("devil_ph1_sign_0001.png");
	HoleSign->SetSamplering(ETextureSampling::LINEAR);
	HoleSign->SetAutoSize(1.0f, true);

	HoleSign->SetPosition(FVector(0.0f, 130.0f, 0.0f));

	HoleCollision = CreateDefaultSubObject<UCollision>("HoleCollision");
	HoleCollision->SetupAttachment(Root);
	//HoleCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));
	HoleCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	
	HoleCollision->SetCollisionGroup(ECollisionOrder::Hole);
	HoleCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

AHole::~AHole()
{
}

void AHole::BeginPlay()
{
	Super::BeginPlay();

	HoleBack->CreateAnimation("HoleBack", "HoleBack",0.075f);
	HoleFront->CreateAnimation("HoleFront", "HoleFront", 0.075f);
	HoleSign->CreateAnimation("HoleSign", "HoleSign", 0.075f);

	HoleBack->ChangeAnimation("HoleBack");
	HoleFront->ChangeAnimation("HoleFront");
	HoleSign->ChangeAnimation("HoleSign");

	SetActorLocation(FVector(0.0f, -300.0f, 10.0f));
}

void AHole::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UContentsHelper::DelMapCheck)
	{
		Destroy();
	}
}
