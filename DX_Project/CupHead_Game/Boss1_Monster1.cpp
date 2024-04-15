#include "PreCompile.h"
#include "Boss1_Monster1.h"
#include "ContentsENum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ABoss1_Monster1::ABoss1_Monster1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1");
	SmallBoss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1");

	SmallBoss1->SetupAttachment(Root);
	SmallBoss1->SetPivot(EPivot::BOT);
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
	SmallBoss1->SetOrder(ERenderOrder::Monster2);
	SmallBoss1->SetSprite("shortFrog_idle_0001.png");
	SmallBoss1->SetSamplering(ETextureSampling::LINEAR);
	AniCreate();

	Phase1StateInit();

	SmallBoss1->SetAutoSize(1.0f, true);
}

void ABoss1_Monster1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	coolDownTime -= _DeltaTime;

	if (1 == phasecheck)
	{
		Phase1.Update(_DeltaTime);
	}
	else {
		Phase2.Update(_DeltaTime);
	}

}

void ABoss1_Monster1::Phase1StateInit()
{
	Phase1.CreateState("smallIdle");
	Phase1.CreateState("smallattready");
	Phase1.CreateState("smallatt");
	Phase1.CreateState("phase2changeReady");
	Phase1.CreateState("phase2changeReady2");
	Phase1.CreateState("phase2change1");
	Phase1.CreateState("phase2change2");

	Phase1.SetUpdateFunction("smallIdle", std::bind(&ABoss1_Monster1::smallIdle, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallIdle", [=] {SmallBoss1->ChangeAnimation("smallIdle"); });

	Phase1.SetUpdateFunction("smallattready", std::bind(&ABoss1_Monster1::smallattready, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallattready", [=] {SmallBoss1->ChangeAnimation("smallattready"); });

	Phase1.SetUpdateFunction("smallatt", std::bind(&ABoss1_Monster1::smallatt, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallatt", [=] {SmallBoss1->ChangeAnimation("smallatt"); });

	Phase1.SetUpdateFunction("phase2changeReady", std::bind(&ABoss1_Monster1::phase2changeReady, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2changeReady", [=] {SmallBoss1->ChangeAnimation("phase2changeReady"); });

	Phase1.SetUpdateFunction("phase2changeReady2", std::bind(&ABoss1_Monster1::phase2changeReady2, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2changeReady2", [=] {SmallBoss1->ChangeAnimation("phase2changeReady2"); });

	Phase1.SetUpdateFunction("phase2change1", std::bind(&ABoss1_Monster1::phase2change1, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2change1", [=] {SmallBoss1->ChangeAnimation("phase2change1"); });

	Phase1.SetUpdateFunction("phase2change2", std::bind(&ABoss1_Monster1::phase2change2, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2change2", [=] {SmallBoss1->ChangeAnimation("phase2change2"); });

	Phase1.ChangeState("smallIdle");
}

void ABoss1_Monster1::Phase2StateInit()
{
	Phase2.CreateState("phase2intro");
	Phase2.CreateState("smallIdle");
	Phase2.CreateState("smallatt2");

	Phase2.SetUpdateFunction("phase2intro", std::bind(&ABoss1_Monster1::phase2intro, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase2intro", [=] {SmallBoss1->ChangeAnimation("phase2intro"); });

	Phase2.SetUpdateFunction("smallIdle", std::bind(&ABoss1_Monster1::smallIdle, this, std::placeholders::_1));
	Phase2.SetStartFunction("smallIdle", [=] {SmallBoss1->ChangeAnimation("smallIdle"); });

	Phase2.SetUpdateFunction("smallatt2", std::bind(&ABoss1_Monster1::smallatt2, this, std::placeholders::_1));
	Phase2.SetStartFunction("smallatt2", [=] {SmallBoss1->ChangeAnimation("smallatt2"); });

	Phase2.ChangeState("phase2intro");
}

void ABoss1_Monster1::AniCreate()
{
	SmallBoss1->CreateAnimation("smallIdle", "smallIdle", 0.1f);
	SmallBoss1->CreateAnimation("smallattready", "smallattready", 0.1f);
	SmallBoss1->CreateAnimation("smallatt", "smallatt", 0.1f);
	SmallBoss1->CreateAnimation("phase2changeReady", "phase2changeReady", 0.1f);
	SmallBoss1->CreateAnimation("phase2changeReady2", "phase2changeReady2", 0.1f);
	SmallBoss1->CreateAnimation("phase2change1", "phase2change1", 0.1f);
	SmallBoss1->CreateAnimation("phase2change2", "phase2change2", 0.1f);

	SmallBoss1->CreateAnimation("phase2intro", "phase2intro", 0.1f);
	SmallBoss1->CreateAnimation("smallatt2", "smallatt2", 0.1f);
}

void ABoss1_Monster1::smallIdle(float _DeltaTime)
{

	if (GetHp() <= 80 && 1 == phasecheck)
	{
		Phase1.ChangeState("phase2changeReady");
		return;
	}

	if (coolDownTime < 0 && 1 == phasecheck)
	{
		Phase1.ChangeState("smallattready");
		return;
	}

	if (coolDownTime < 0 && 2 == phasecheck)
	{
		Phase2.ChangeState("smallatt2");
		return;
	}
}

void ABoss1_Monster1::smallattready(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{

		Phase1.ChangeState("smallatt");
		return;
	}
}

void ABoss1_Monster1::smallatt(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{

		smallattcount++;
	}

	if (smallattcount > 3)
	{
		Phase1.ChangeState("smallIdle");
		coolDownTime = 6.0f;
		smallattcount = 0;
		return;
	}
}

void ABoss1_Monster1::phase2changeReady(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{

		Phase1.ChangeState("phase2changeReady2");
		return;
	}
}

void ABoss1_Monster1::phase2changeReady2(float _DeltaTime)
{

	if (true == SmallBoss1->IsCurAnimationEnd())
	{

		phase2changecount++;
	}

	if (phase2changecount > 3)
	{
		Phase1.ChangeState("phase2change1");
		//coolDownTime = 6.0f;
		//count = 0;
		return;
	}
}

void ABoss1_Monster1::phase2change1(float _DeltaTime)
{

	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("phase2change2");
		return;
	}
}

void ABoss1_Monster1::phase2change2(float _DeltaTime)
{
	AddActorLocation(FVector::Left * 500.0f * _DeltaTime);

	if (GetActorLocation().iX() <= -580)
	{
		Phase2StateInit();
		phasecheck = 2;
		return;
	}
}

void ABoss1_Monster1::phase2intro(float _DeltaTime)
{
	SmallBoss1->SetDir(EEngineDir::Left);

	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		Phase2.ChangeState("smallIdle");
		return;
	}
}


void ABoss1_Monster1::smallatt2(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		Phase2.ChangeState("smallIdle");
		coolDownTime = 6.0f;
		return;
	}
}
