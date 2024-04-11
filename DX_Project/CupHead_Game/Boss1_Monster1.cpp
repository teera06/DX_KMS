#include "PreCompile.h"
#include "Boss1_Monster1.h"
#include "ContentsENum.h"
#include <EngineCore/SpriteRenderer.h>

ABoss1_Monster1::ABoss1_Monster1()
{
	Boss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1");
}

ABoss1_Monster1::~ABoss1_Monster1()
{
}

void ABoss1_Monster1::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(324.0f, 350.0f, 0.0f));
	//SetActorLocation(FVector(0.0f, 0.0f, -50.0f));
	Boss1->SetOrder(ERenderOrder::Monster);
	Boss1->SetSprite("shortFrog_idle_0001.png");
	Boss1->SetSamplering(ETextureSampling::LINEAR);
	Boss1->CreateAnimation("Boss1Idle", "Boss1Idle", 0.1f);

	Boss1->ChangeAnimation("Boss1Idle");

	Boss1->SetAutoSize(1.0f, true);
}

void ABoss1_Monster1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}
