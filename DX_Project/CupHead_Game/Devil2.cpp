#include "PreCompile.h"
#include "Devil2.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ADevil2::ADevil2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");
	Boss2 = CreateDefaultSubObject<USpriteRenderer>("Boss2");

	Boss2->SetupAttachment(Root);

	Boss2->SetOrder(ERenderOrder::Monster1);
	Boss2->SetSprite("devil_ph1_intro_0004.png");
	Boss2->SetSamplering(ETextureSampling::LINEAR);
	Boss2->SetAutoSize(1.0f, true);

	SetRoot(Root);
}

ADevil2::~ADevil2()
{
}

void ADevil2::BeginPlay()
{
}

void ADevil2::Tick(float _DeltaTime)
{
}

void ADevil2::Phase1StateInit()
{
}

void ADevil2::AniCreate()
{
}
