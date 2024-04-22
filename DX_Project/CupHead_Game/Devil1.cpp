#include "PreCompile.h"
#include "Devil1.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
ADevil1::ADevil1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");
	Boss2 = CreateDefaultSubObject<USpriteRenderer>("Boss2");

	Boss2->SetupAttachment(Root);

	SetRoot(Root);

	Boss2->SetOrder(ERenderOrder::Monster1);
	Boss2->SetSprite("devil_ph1_intro_0004.png");
	Boss2->SetSamplering(ETextureSampling::LINEAR);
	Boss2->SetAutoSize(1.0f, true);
}

ADevil1::~ADevil1()
{
}

void ADevil1::BeginPlay()
{
	Super::BeginPlay();
}

void ADevil1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
