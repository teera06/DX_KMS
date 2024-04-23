#include "PreCompile.h"
#include "BombBat.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ABombBat::ABombBat()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("BombBat");
	BombBat = CreateDefaultSubObject<USpriteRenderer>("BombBat");
	BombBat->SetupAttachment(Root);

	BombBat->SetOrder(ERenderOrder::FrontSkillMonster);
	BombBat->SetSprite("devil_ph3_attack_bomb_bat_0001.png");
	BombBat->SetSamplering(ETextureSampling::LINEAR);
	BombBat->SetAutoSize(1.0f, true);

	SetRoot(Root);
}

ABombBat::~ABombBat()
{
}

void ABombBat::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(200.0f, 200.0f, 5.0f));

	BombBat->CreateAnimation("BombBat", "BombBat", 0.075f);

	BombBat->ChangeAnimation("BombBat");
}

void ABombBat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
