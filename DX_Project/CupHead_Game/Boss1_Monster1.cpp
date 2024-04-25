#include "PreCompile.h"
#include "Boss1_Monster1.h"
#include "ContentsENum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "smallskill.h"
#include "ball.h"

ABoss1_Monster1::ABoss1_Monster1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1");
	SmallBoss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1");

	SmallBoss1->SetupAttachment(Root);
	SmallBoss1->SetPivot(EPivot::BOT);
	//SmallBoss1->AddPosition(FVector(200.0f, -10.0f, 0.0f));

	smallBossCollision = CreateDefaultSubObject<UCollision>("SmallBoss");
	smallBossCollision->SetupAttachment(Root);
	smallBossCollision->SetPosition(FVector(0.0f, 150.0f, 100.0f));
	smallBossCollision->SetScale(FVector(200.0f, 200.0f, 100.0f));
	smallBossCollision->SetCollisionGroup(ECollisionOrder::Boss1Monster1);
	smallBossCollision->SetCollisionType(ECollisionType::RotRect);
	SetRoot(Root);
}

ABoss1_Monster1::~ABoss1_Monster1()
{
}

void ABoss1_Monster1::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(324.0f, 350.0f, 0.0f));
	SetActorLocation(FVector(330.0f, -295.0f, 0.0f));
	SmallBoss1->SetOrder(ERenderOrder::Monster2);
	SmallBoss1->SetSprite("shortFrog_idle_0001.png");
	SmallBoss1->SetSamplering(ETextureSampling::LINEAR);
	SmallBoss1->SetPlusColor(FVector(0.2f, 0.2f, 0.2f));
	AniCreate();

	Phase1StateInit();

	SmallBoss1->SetAutoSize(1.0f, true);
}

void ABoss1_Monster1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

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
	Phase1.CreateState("smallintro");
	Phase1.CreateState("smallIdle");
	Phase1.CreateState("smallattready");
	Phase1.CreateState("smallatt");
	Phase1.CreateState("smallattEnd");
	Phase1.CreateState("phase2changeReady");
	Phase1.CreateState("phase2changeReady2");
	Phase1.CreateState("phase2change1");
	Phase1.CreateState("phase2change2");

	Phase1.SetUpdateFunction("smallintro", std::bind(&ABoss1_Monster1::smallintro, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallintro", [=] {SmallBoss1->ChangeAnimation("smallintro"); });

	Phase1.SetUpdateFunction("smallIdle", std::bind(&ABoss1_Monster1::smallIdle, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallIdle", [=] {SmallBoss1->ChangeAnimation("smallIdle"); });

	Phase1.SetUpdateFunction("smallattready", std::bind(&ABoss1_Monster1::smallattready, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallattready", [=] {SmallBoss1->ChangeAnimation("smallattready"); });

	Phase1.SetUpdateFunction("smallatt", std::bind(&ABoss1_Monster1::smallatt, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallatt", [=] {SmallBoss1->ChangeAnimation("smallatt"); });

	Phase1.SetUpdateFunction("smallattEnd", std::bind(&ABoss1_Monster1::smallattEnd, this, std::placeholders::_1));
	Phase1.SetStartFunction("smallattEnd", [=] {SmallBoss1->ChangeAnimation("smallattEnd"); });

	Phase1.SetUpdateFunction("phase2changeReady", std::bind(&ABoss1_Monster1::phase2changeReady, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2changeReady", [=] {SmallBoss1->ChangeAnimation("phase2changeReady"); });

	Phase1.SetUpdateFunction("phase2changeReady2", std::bind(&ABoss1_Monster1::phase2changeReady2, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2changeReady2", [=] {SmallBoss1->ChangeAnimation("phase2changeReady2"); });

	Phase1.SetUpdateFunction("phase2change1", std::bind(&ABoss1_Monster1::phase2change1, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2change1", [=] {SmallBoss1->ChangeAnimation("phase2change1"); });

	Phase1.SetUpdateFunction("phase2change2", std::bind(&ABoss1_Monster1::phase2change2, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase2change2", [=] {SmallBoss1->ChangeAnimation("phase2change2"); });

	Phase1.ChangeState("smallintro");
}

void ABoss1_Monster1::Phase2StateInit()
{
	Phase2.CreateState("phase2intro");
	Phase2.CreateState("smallIdle");
	Phase2.CreateState("smallatt2Ready1");
	Phase2.CreateState("smallatt2");
	Phase2.CreateState("phase3changeReady");
	Phase2.CreateState("phase3changeReady2");
	Phase2.CreateState("phase3change1");
	Phase2.CreateState("phase3change2");

	Phase2.SetUpdateFunction("phase2intro", std::bind(&ABoss1_Monster1::phase2intro, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase2intro", [=] {SmallBoss1->ChangeAnimation("phase2intro"); });

	Phase2.SetUpdateFunction("smallIdle", std::bind(&ABoss1_Monster1::smallIdle, this, std::placeholders::_1));
	Phase2.SetStartFunction("smallIdle", [=] {SmallBoss1->ChangeAnimation("smallIdle"); });

	Phase2.SetUpdateFunction("smallatt2Ready1", std::bind(&ABoss1_Monster1::smallatt2Ready1, this, std::placeholders::_1));
	Phase2.SetStartFunction("smallatt2Ready1", [=] {SmallBoss1->ChangeAnimation("smallatt2Ready1"); });

	Phase2.SetUpdateFunction("smallatt2", std::bind(&ABoss1_Monster1::smallatt2, this, std::placeholders::_1));
	Phase2.SetStartFunction("smallatt2", [=] {SmallBoss1->ChangeAnimation("smallatt2"); });

	Phase2.SetUpdateFunction("phase3changeReady", std::bind(&ABoss1_Monster1::phase3changeReady, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase3changeReady", [=] {SmallBoss1->ChangeAnimation("phase2changeReady"); });

	Phase2.SetUpdateFunction("phase3changeReady2", std::bind(&ABoss1_Monster1::phase3changeReady2, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase3changeReady2", [=] {SmallBoss1->ChangeAnimation("phase2changeReady2"); });

	Phase2.SetUpdateFunction("phase3change1", std::bind(&ABoss1_Monster1::phase3change1, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase3change1", [=] {SmallBoss1->ChangeAnimation("phase2change1"); });

	Phase2.SetUpdateFunction("phase3change2", std::bind(&ABoss1_Monster1::phase3change2, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase3change2", [=] {SmallBoss1->ChangeAnimation("phase2change2"); });

	Phase2.ChangeState("phase2intro");
}

void ABoss1_Monster1::AniCreate()
{
	SmallBoss1->CreateAnimation("smallintro", "smallintro", 0.15f);
	SmallBoss1->CreateAnimation("smallIdle", "smallIdle", 0.075f);
	SmallBoss1->CreateAnimation("smallattready", "smallattready", 0.12f);
	SmallBoss1->CreateAnimation("smallatt", "smallatt", 0.065f);
	SmallBoss1->CreateAnimation("smallattEnd", "smallattEnd", 0.075f);
	SmallBoss1->CreateAnimation("phase2changeReady", "phase2changeReady", 0.1f);
	SmallBoss1->CreateAnimation("phase2changeReady2", "phase2changeReady2", 0.1f);
	SmallBoss1->CreateAnimation("phase2change1", "phase2change1", 0.1f);
	SmallBoss1->CreateAnimation("phase2change2", "phase2change2", 0.1f);

	SmallBoss1->CreateAnimation("phase2intro", "phase2intro", 0.1f);
	SmallBoss1->CreateAnimation("smallatt2Ready1", "smallatt2Ready1", 0.075f,false);
	SmallBoss1->CreateAnimation("smallatt2", "smallatt2", 0.075f);
}


void ABoss1_Monster1::createSkill()
{
	NewSkill = GetWorld()->SpawnActor<Asmallskill>("BaseBullet");
	NewSkill->SetSmallSkillDir(FVector::Left);
	SkillYMove();
}

void ABoss1_Monster1::SkillYMove()
{
	if (smallattcount==0 || smallattcount == 4 || smallattcount == 8)
	{
		if (smallattcount == 8)
		{
			NewSkill->SetParryCheck(true);
		}
		NewSkill->SetActorLocation({ GetActorLocation().X-35.0f,-20.0f,0.0f });
		
	}
	else if(smallattcount == 1 || smallattcount == 3 || smallattcount == 5 || smallattcount == 7){

		if (smallattcount == 5)
		{
			NewSkill->SetParryCheck(true);
		}
		NewSkill->SetActorLocation({ GetActorLocation().X- 35.0f,-110.0f,0.0f });
	}
	else if (smallattcount == 2 || smallattcount == 6)
	{
		if (smallattcount == 2)
		{
			NewSkill->SetParryCheck(true);
		}
		NewSkill->SetActorLocation({ GetActorLocation().X- 35.0f,-210.0f,0.0f });
	}
}

void ABoss1_Monster1::createSkill2()
{
	NewBall = GetWorld()->SpawnActor<Aball>("ball");
	
	if (false == ballatt)
	{
		NewBall->SetStartPos(FVector::Right + (FVector::Up * 2.0f));
	}
	else
	{
		NewBall->SetStartPos(FVector::Right + (FVector::Down * 2.0f));
	}
	//NewBall->SetSmallSkillDir(FVector::Left);
}


void ABoss1_Monster1::smallintro(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("smallIdle");
		return;
	}
}

void ABoss1_Monster1::smallIdle(float _DeltaTime)
{

	if (GetHp() <= 80 && 1 == phasecheck)
	{
		attOrder = false;
		Phase1.ChangeState("phase2changeReady");
		return;
	}

	if (GetHp() <= 50 && 2 == phasecheck)
	{
		Phase2.ChangeState("phase3changeReady");
		return;
	}

	if (coolDownTime < 0 && 1 == phasecheck && false==attOrder)
	{
		Phase1.ChangeState("smallattready");
		return;
	}

	if (coolDownTime < 0 && 2 == phasecheck && true == attOrder)
	{
		if (false == ballatt)
		{
			ballatt = true;
		}
		else
		{
			ballatt = false;
		}
		Phase2.ChangeState("smallatt2ready1");
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

	SmallBoss1->SetFrameCallback("smallatt", 8, [=] {createSkill(); });

	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		smallattcount++;
	}

	if (smallattcount > 8)
	{
		Phase1.ChangeState("smallattEnd");
		return;
	}
}

void ABoss1_Monster1::smallattEnd(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("smallIdle");
		coolDownTime = 6.0f;
		attOrder = true;
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
		phase2changecount = 0;
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

void ABoss1_Monster1::phase3changeReady(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{

		Phase2.ChangeState("phase3changeReady2");
		return;
	}
}

void ABoss1_Monster1::phase3changeReady2(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{

		phase2changecount++;
	}

	if (phase2changecount > 3)
	{
		Phase2.ChangeState("phase3change1");
		return;
	}
}

void ABoss1_Monster1::phase3change1(float _DeltaTime)
{
	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		Phase2.ChangeState("phase3change2");
		return;
	}
}

void ABoss1_Monster1::phase3change2(float _DeltaTime)
{
	AddActorLocation(FVector::Right * 500.0f * _DeltaTime);
}


void ABoss1_Monster1::smallatt2Ready1(float _DeltaTime)
{
	if (ballattcount == 3)
	{
		ballattcount = 0;
		attOrder = false;
		coolDownTime = 6.0f;
		Phase2.ChangeState("smallIdle");
		return;
	}

	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		Delay++;
	}

	if (Delay == 9)
	{
		Delay = 0;
		Phase2.ChangeState("smallatt2");
		return;
	}
}


void ABoss1_Monster1::smallatt2(float _DeltaTime)
{

	if (ballattcount == 3)
	{
		ballattcount = 0;
		attOrder = false;
		Phase2.ChangeState("smallIdle");
		return;
	}
	
	if (true == SmallBoss1->IsCurAnimationEnd())
	{
		createSkill2();
		ballattcount++;
		Phase2.ChangeState("smallatt2Ready1");
		return;
	}
}
