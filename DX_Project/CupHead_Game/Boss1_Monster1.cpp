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
	Boss1->CreateAnimation("Boss1Idle", "Boss1Idle", 0.1f);
	Boss1->CreateAnimation("Boss1ClapAttack", "Boss1ClapAttack", 0.1f);

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
	State.CreateState("Boss1Idle");
	State.CreateState("Boss1ClapAttack");

	State.SetUpdateFunction("Boss1Idle", std::bind(&ABoss1_Monster1::Boss1Idle, this, std::placeholders::_1));
	State.SetStartFunction("Boss1Idle", [=] {Boss1->ChangeAnimation("Boss1Idle"); });

	State.SetUpdateFunction("Boss1ClapAttack", std::bind(&ABoss1_Monster1::Boss1ClapAttack, this, std::placeholders::_1));
	State.SetStartFunction("Boss1ClapAttack", [=] {Boss1->ChangeAnimation("Boss1ClapAttack"); });

	State.ChangeState("Boss1ClapAttack");
}

void ABoss1_Monster1::Boss1Idle(float _DeltaTime)
{
	if (coolDownTime < 0)
	{
		State.ChangeState("Boss1ClapAttack");
		return;
	}
}

void ABoss1_Monster1::Boss1ClapAttack(float _DeltaTime)
{
	if (true == Boss1->IsCurAnimationEnd())
	{
		State.ChangeState("Boss1Idle");
		coolDownTime = 6.0f;
		return;
	}
}
