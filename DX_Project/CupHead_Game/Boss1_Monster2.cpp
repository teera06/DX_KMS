#include "PreCompile.h"
#include "Boss1_Monster2.h"

#include <EngineBase\EngineRandom.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

#include "ContentsENum.h"
#include "Firefly.h"

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
	BigBoss1->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	BigBoss1->CreateAnimation("bigintro", "bigintro", 0.12f);
	BigBoss1->CreateAnimation("bigIdle", "bigIdle", 0.1f);
	BigBoss1->CreateAnimation("bigatt", "bigatt", 0.1f);

	BigBoss1->CreateAnimation("bigatt2Ready", "bigatt2Ready", 0.1f);
	BigBoss1->CreateAnimation("bigatt2Ready2", "bigatt2Ready2", 0.1f);
	BigBoss1->CreateAnimation("bigatt2", "bigatt2", 0.1f);


	Phase1StateInit();

	BigBoss1->SetAutoSize(1.0f, true);
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

	
	Phase1.ChangeState("bigintro");
}

void ABoss1_Monster2::Phase2StateInit()
{

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

	if (Bigattcount > 5)
	{
		Phase1.ChangeState("BigIdle");
		coolDownTime = 6.0f;
		attOrder = false;
		Bigattcount = 0;
		return;
	}
}
