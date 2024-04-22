#include "PreCompile.h"
#include "BossBackMap1.h"
#include "ContentsENum.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

ABossBackMap1::ABossBackMap1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("BossBackMap1");
	BossBackMap1 = CreateDefaultSubObject<USpriteRenderer>("BossBackMap1");

	BossBackMap1->SetupAttachment(Root);

	SetRoot(Root);

	BossBackMap1->SetOrder(ERenderOrder::Boss1_back1);
	BossBackMap1->SetSprite("BossDevil_Phase1Background2.png");
	BossBackMap1->SetSamplering(ETextureSampling::LINEAR);
	BossBackMap1->SetAutoSize(1.0f, true);
}

ABossBackMap1::~ABossBackMap1()
{
}

void ABossBackMap1::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(0.0f, 0.0f, 200.0f));
}


void ABossBackMap1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
