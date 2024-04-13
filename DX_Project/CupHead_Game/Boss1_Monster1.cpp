#include "PreCompile.h"
#include "Boss1_Monster1.h"
#include "ContentsENum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ABoss1_Monster1::ABoss1_Monster1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1");
	Boss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1");

	Boss1->SetupAttachment(Root);
	Boss1->SetPivot(EPivot::BOT);
	SetRoot(Root);
}

ABoss1_Monster1::~ABoss1_Monster1()
{
}

void ABoss1_Monster1::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(324.0f, 350.0f, 0.0f));
	SetActorLocation(FVector(380.0f, -280.0f, 0.0f));
	Boss1->SetOrder(ERenderOrder::Monster2);
	Boss1->SetSprite("shortFrog_idle_0001.png");
	Boss1->SetSamplering(ETextureSampling::LINEAR);
	Boss1->CreateAnimation("smallIdle", "smallIdle", 0.1f);
	Boss1->CreateAnimation("smallatt", "smallatt", 0.1f);

	StateInit();
	Boss1->SetAutoSize(1.0f, true);
}

void ABoss1_Monster1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	coolDownTime -= _DeltaTime;
	State.Update(_DeltaTime);

}

void ABoss1_Monster1::StateInit()
{
	State.CreateState("smallIdle");
	State.CreateState("smallattready");
	State.CreateState("smallatt");

	State.SetUpdateFunction("smallIdle", std::bind(&ABoss1_Monster1::smallIdle, this, std::placeholders::_1));
	State.SetStartFunction("smallIdle", [=] {Boss1->ChangeAnimation("smallIdle"); });

	State.SetUpdateFunction("smallatt", std::bind(&ABoss1_Monster1::smallatt, this, std::placeholders::_1));
	State.SetStartFunction("smallatt", [=] {Boss1->ChangeAnimation("smallatt"); });

	State.ChangeState("smallIdle");
}

void ABoss1_Monster1::smallIdle(float _DeltaTime)
{
	if (coolDownTime < 0)
	{
		State.ChangeState("smallatt");
		return;
	}
}

void ABoss1_Monster1::smallatt(float _DeltaTime)
{
	if (true == Boss1->IsCurAnimationEnd())
	{
		State.ChangeState("smallIdle");
		coolDownTime = 6.0f;
		return;
	}
}
