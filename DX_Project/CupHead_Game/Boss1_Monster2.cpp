#include "PreCompile.h"
#include "Boss1_Monster2.h"
#include "ContentsENum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ABoss1_Monster2::ABoss1_Monster2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1_1");
	BigBoss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1_1");

	BigBoss1->SetupAttachment(Root);
	BigBoss1->SetPivot(EPivot::BOT);
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
	BigBoss1->SetOrder(ERenderOrder::Monster1);
	BigBoss1->SetSprite("tallfrog_idle_0001.png");
	BigBoss1->SetSamplering(ETextureSampling::LINEAR);
	BigBoss1->CreateAnimation("bigIdle", "bigIdle", 0.1f);

	BigBoss1->ChangeAnimation("bigIdle");

	BigBoss1->SetAutoSize(1.0f, true);
}

void ABoss1_Monster2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ABoss1_Monster2::Phase1StateInit()
{

}
