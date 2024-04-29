#include "PreCompile.h"

#include "Orb_Fire.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"


AOrb_Fire::AOrb_Fire()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Orb_Fire");

	Orb_Fire = CreateDefaultSubObject<USpriteRenderer>("Orb_Fire");

	Orb_Fire->SetupAttachment(Root);


	SetRoot(Root);
}

AOrb_Fire::~AOrb_Fire()
{
}

void AOrb_Fire::BeginPlay()
{

	Super::BeginPlay();
	Orb_Fire->SetOrder(ERenderOrder::skilleffect);
	Orb_Fire->SetSprite("tallfrog_slotman_coin_0001.png");
	Orb_Fire->SetSamplering(ETextureSampling::LINEAR);
	Orb_Fire->SetAutoSize(1.0f, true);
	
	Orb_Fire->CreateAnimation("Coin", "Coin", 0.1f);
	
	Orb_Fire->ChangeAnimation("Coin");
}

void AOrb_Fire::Tick(float _DeltaTime)
{

}

void AOrb_Fire::Collisiongather(float _DeltaTime)
{

}
