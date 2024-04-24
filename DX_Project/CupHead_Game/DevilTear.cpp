#include "PreCompile.h"
#include "DevilTear.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"


ADevilTear::ADevilTear()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Tear");
	Tear = CreateDefaultSubObject<USpriteRenderer>("Tear");
	Tear->SetupAttachment(Root);

	Tear->SetOrder(ERenderOrder::backSkill);
	Tear->SetSprite("devil_ph3_tear_drop_bb_0001.png");
	Tear->SetSamplering(ETextureSampling::LINEAR);
	Tear->SetAutoSize(0.85f, true);
	Tear->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	SetRoot(Root);
}

ADevilTear::~ADevilTear()
{
}

void ADevilTear::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(-400.0f, 200.0f, 5.0f));

	//FatDemon->CreateAnimation("FatDemonIdle", "FatDemonIdle", 0.075f);
	//FatDemon->CreateAnimation("FatDemonAttack", "FatDemonAttack", 0.075f);
}

void ADevilTear::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
