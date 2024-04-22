#include "PreCompile.h"
#include "BossBackMap2.h"
#include "ContentsENum.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

ABossBackMap2::ABossBackMap2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("BossBackMap2");
	BossBackMap2 = CreateDefaultSubObject<USpriteRenderer>("BossBackMap2");

	BossBackMap2->SetupAttachment(Root);

	SetRoot(Root);

	BossBackMap2->SetOrder(ERenderOrder2::Boss2_Front1);
	BossBackMap2->SetSprite("HallFront.png");
	BossBackMap2->SetSamplering(ETextureSampling::LINEAR);
	BossBackMap2->SetAutoSize(1.0f, true);
}

ABossBackMap2::~ABossBackMap2()
{
}

void ABossBackMap2::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(0.0f, -50.0f, 100.0f));
}

void ABossBackMap2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
