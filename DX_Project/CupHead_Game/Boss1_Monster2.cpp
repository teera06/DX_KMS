#include "PreCompile.h"
#include "Boss1_Monster2.h"

#include <EngineBase\EngineRandom.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/DefaultSceneComponent.h>


#include "ContentsENum.h"
#include "Firefly.h"
#include "Boss1_Monster1.h"

ABoss1_Monster2::ABoss1_Monster2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1_1");
	BigBoss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1_1");

	BigBoss1->SetupAttachment(Root);
	BigBoss1->SetPivot(EPivot::BOT);

	WindSkill = CreateDefaultSubObject<USpriteRenderer>("WindSkill");

	WindSkill->SetupAttachment(Root);
	WindSkill->AddPosition(FVector(-350.0f, 300.0f, 0.0f));

	WindSkill->SetActive(false);

	BigBossCollision = CreateDefaultSubObject<UCollision>("BigBossCollision");
	BigBossCollision->SetupAttachment(Root);
	BigBossCollision->SetPosition(FVector(0.0f, 150.0f, 100.0f));
	BigBossCollision->SetScale(FVector(200.0f, 200.0f, 100.0f));
	BigBossCollision->SetCollisionGroup(ECollisionOrder::Boss1Monster2);
	BigBossCollision->SetCollisionType(ECollisionType::RotRect);

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
	BigBoss1->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	BigBoss1->CreateAnimation("bigintro", "bigintro", 0.12f);
	BigBoss1->CreateAnimation("bigIdle", "bigIdle", 0.1f);
	BigBoss1->CreateAnimation("bigatt", "bigatt", 0.1f);

	BigBoss1->CreateAnimation("bigatt2Ready", "bigatt2Ready", 0.1f);
	BigBoss1->CreateAnimation("bigatt2Ready2", "bigatt2Ready2", 0.1f);
	BigBoss1->CreateAnimation("bigatt2", "bigatt2", 0.1f);
	BigBoss1->CreateAnimation("bigatt2end", "bigatt2end", 0.1f);
	BigBoss1->CreateAnimation("phase3changeReady1", "phase3changeReady1", 0.1f);
	BigBoss1->CreateAnimation("phase3changeReady2", "phase3changeReady2", 0.1f);


	WindSkill->SetOrder(ERenderOrder::Monster1);
	WindSkill->SetSprite("tallfrog_fan_wind_0001.png");
	WindSkill->SetSamplering(ETextureSampling::LINEAR);
	WindSkill->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	WindSkill->CreateAnimation("Wind", "Wind", 0.12f);

	Phase1StateInit();

	BigBoss1->SetAutoSize(1.0f, true);
	WindSkill->SetAutoSize(1.0f, true);

	WindSkill->ChangeAnimation("Wind");
}

void ABoss1_Monster2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	coolDownTime -= _DeltaTime;
	if (1 == phasecheck || 2 == phasecheck)
	{
		Phase1.Update(_DeltaTime);
	}
}

void ABoss1_Monster2::Phase1StateInit()
{

	Phase1.CreateState("bigintro");
	Phase1.CreateState("bigIdle");
	Phase1.CreateState("bigatt");
	Phase1.CreateState("bigatt2Ready");
	Phase1.CreateState("bigatt2Ready2");
	Phase1.CreateState("bigatt2");
	Phase1.CreateState("bigatt2end");

	Phase1.CreateState("phase3changeReady1");
	Phase1.CreateState("phase3changeReady2");
	

	Phase1.SetUpdateFunction("bigintro", std::bind(&ABoss1_Monster2::bigintro, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigintro", [=] {BigBoss1->ChangeAnimation("bigintro"); });

	Phase1.SetUpdateFunction("bigIdle", std::bind(&ABoss1_Monster2::bigIdle, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigIdle", [=] {BigBoss1->ChangeAnimation("bigIdle"); });

	Phase1.SetUpdateFunction("bigatt", std::bind(&ABoss1_Monster2::bigatt, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigatt", [=] {BigBoss1->ChangeAnimation("bigatt"); });

	Phase1.SetUpdateFunction("bigatt2Ready", std::bind(&ABoss1_Monster2::bigatt2Ready, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigatt2Ready", [=] {BigBoss1->ChangeAnimation("bigatt2Ready"); });

	Phase1.SetUpdateFunction("bigatt2Ready2", std::bind(&ABoss1_Monster2::bigatt2Ready2, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigatt2Ready2", [=] {BigBoss1->ChangeAnimation("bigatt2Ready2"); });

	Phase1.SetUpdateFunction("bigatt2", std::bind(&ABoss1_Monster2::bigatt2, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigatt2", [=] {BigBoss1->ChangeAnimation("bigatt2"); });

	Phase1.SetUpdateFunction("bigatt2end", std::bind(&ABoss1_Monster2::bigatt2end, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigatt2end", [=] {BigBoss1->ChangeAnimation("bigatt2end"); });

	Phase1.SetUpdateFunction("phase3changeReady1", std::bind(&ABoss1_Monster2::phase3changeReady1, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase3changeReady1", [=] {BigBoss1->ChangeAnimation("phase3changeReady1"); });

	Phase1.SetUpdateFunction("phase3changeReady2", std::bind(&ABoss1_Monster2::phase3changeReady2, this, std::placeholders::_1));
	Phase1.SetStartFunction("phase3changeReady2", [=] {BigBoss1->ChangeAnimation("phase3changeReady2"); });

	
	Phase1.ChangeState("bigintro");
}

void ABoss1_Monster2::Phase2StateInit()
{
	Phase2.CreateState("SlotIntro");

	Phase1.SetUpdateFunction("bigintro", std::bind(&ABoss1_Monster2::bigintro, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigintro", [=] {BigBoss1->ChangeAnimation("bigintro"); });
}



void ABoss1_Monster2::createSkill()
{
	RandomSkillDelay = UEngineRandom::MainRandom.RandomFloat(0.3f, 1.5f);


	NewFirefly = GetWorld()->SpawnActor<AFirefly>("Firefly");

	NewFirefly->SetDelay(RandomSkillDelay);
	//NewFirefly->SetSmallSkillDir(FVector::Left);
	//NewFirefly->SetActorLocation({ GetActorLocation().X-10.0f,270.0f,0.0f });
	//SkillYMove();
}

void ABoss1_Monster2::Collisioncheck()
{
	BigBossCollision->CollisionEnter(ECollisionOrder::Boss1Monster1, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster1* Monster = dynamic_cast<ABoss1_Monster1*>(Ptr);
		Monster->Destroy();

		Change3 = true;
		//_Collison->GetActor()->Destroy();
	});
}

void ABoss1_Monster2::bigintro(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("bigIdle");
		return;
	}
}

void ABoss1_Monster2::bigIdle(float _DeltaTime)
{
	if (GetHp() <= 50 && 2 == phasecheck)
	{
		attOrder = true;
		Phase1.ChangeState("phase3changeReady1");
		return;
	}

	if (coolDownTime < 0 && 1 == phasecheck && true == attOrder)
	{
		Phase1.ChangeState("bigatt");
		return;
	}

	if (coolDownTime < 0 && 2 == phasecheck && false == attOrder)
	{
		Phase1.ChangeState("bigatt2Ready");
		return;
	}

}

void ABoss1_Monster2::bigatt(float _DeltaTime)
{

	BigBoss1->SetFrameCallback("bigatt", 14, [=] {createSkill(); });
	BigBoss1->SetFrameCallback("bigatt", 22, [=] {createSkill(); });
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		//createSkill();
		Bigattcount++;
	}

	if (Bigattcount > 2)
	{
		Phase1.ChangeState("BigIdle");
		coolDownTime = 6.0f;
		attOrder = false;
		Bigattcount = 0;
		return;
	}
}

void ABoss1_Monster2::bigatt2Ready(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("bigatt2Ready2");
		return;
	}
}

void ABoss1_Monster2::bigatt2Ready2(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		WindSkill->SetActive(true);
		Phase1.ChangeState("bigatt2");
		return;
	}
}

void ABoss1_Monster2::bigatt2(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		//createSkill();
		Bigattcount++;
	}

	if (Bigattcount > 20)
	{
		WindSkill->SetActive(false);
		Phase1.ChangeState("bigatt2end");
		return;
	}
}

void ABoss1_Monster2::bigatt2end(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("BigIdle");
		coolDownTime = 6.0f;
		attOrder = false;
		Bigattcount = 0;
		return;
	}
}

void ABoss1_Monster2::phase3changeReady1(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("phase3changeReady2");
		return;
	}
}

void ABoss1_Monster2::phase3changeReady2(float _DeltaTime)
{
	Collisioncheck();
	
	if (true == Change3)
	{

	}
}

void ABoss1_Monster2::SlotIntro(float _DeltaTime)
{
}

void ABoss1_Monster2::SlotIdle(float _DeltaTime)
{

}
