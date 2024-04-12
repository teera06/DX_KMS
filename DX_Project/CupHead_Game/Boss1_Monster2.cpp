#include "PreCompile.h"
#include "Boss1_Monster2.h"
#include "ContentsENum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ABoss1_Monster2::ABoss1_Monster2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1_1");
	Boss1_1 = CreateDefaultSubObject<USpriteRenderer>("Boss1_1");

	Boss1_1->SetupAttachment(Root);
	Boss1_1->SetPivot(EPivot::BOT);
	SetRoot(Root);
}

ABoss1_Monster2::~ABoss1_Monster2()
{
}

void ABoss1_Monster2::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(324.0f, 350.0f, 0.0f));
	SetActorLocation(FVector(450.0f, -250.0f, 0.0f));
	Boss1_1->SetOrder(ERenderOrder::Monster1);
	Boss1_1->SetSprite("tallfrog_idle_0001.png");
	Boss1_1->SetSamplering(ETextureSampling::LINEAR);
	Boss1_1->CreateAnimation("Boss1Idle1", "Boss1Idle1", 0.1f);

	Boss1_1->ChangeAnimation("Boss1Idle1");

	Boss1_1->SetAutoSize(1.0f, true);
}

void ABoss1_Monster2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
