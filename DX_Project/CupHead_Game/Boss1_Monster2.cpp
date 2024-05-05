#include "PreCompile.h"
#include "Boss1_Monster2.h"

#include <EngineBase\EngineRandom.h>

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/DefaultSceneComponent.h>


#include "ContentsENum.h"
#include "Firefly.h"
#include "Coin.h"
#include "MoveObject3.h"
#include "MoveObject2.h"
#include "MoveObject1.h"

#include "Boss1_Monster1.h"

#include "Play_Cuphead.h"
#include "ScreenEffect.h"

ABoss1_Monster2::ABoss1_Monster2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1_1");
	BigBoss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1_1");

	BigBoss1->SetupAttachment(Root);
	BigBoss1->SetPivot(EPivot::RIGHTBOTTOM);

	BigBoss1->AddPosition(FVector(270.0f, 0.0f, 0.0f));

	SlotMouse = CreateDefaultSubObject<USpriteRenderer>("SlotMouse");

	SlotMouse->SetupAttachment(Root);
	SlotMouse->SetPivot(EPivot::BOT);
	SlotMouse->AddPosition(FVector(-250.0f, 285.0f, 0.0f));

	SlotMouse->SetActive(false);

	FrontSlot = CreateDefaultSubObject<USpriteRenderer>("FrontSlot");
	
	FrontSlot->SetupAttachment(Root);
	FrontSlot->SetPivot(EPivot::BOT);
	FrontSlot->AddPosition(FVector(122.0f, 100.0f, 0.0f));

	FrontSlot->SetActive(false);

	SlotImage1 = CreateDefaultSubObject<USpriteRenderer>("SlotImage1");
	SlotImage1->SetupAttachment(Root);
	SlotImage1->SetPivot(EPivot::BOT);
	SlotImage1->AddPosition(FVector(-125.0f, 135.0f, 0.0f));
	SlotImage1->AddRotationDeg(FVector(0.0f, 35.0f, 0.0f));
	//SlotImage1->SetPlusColor(FVector(0.0f, 0.5f, 0.0f));

	SlotImage2 = CreateDefaultSubObject<USpriteRenderer>("SlotImage2");
	SlotImage2->SetupAttachment(Root);
	SlotImage2->SetPivot(EPivot::BOT);
	SlotImage2->AddPosition(FVector(-70.0f, 135.0f, 0.0f));
	SlotImage2->AddRotationDeg(FVector(0.0f, 35.0f, 0.0f));

	SlotImage3 = CreateDefaultSubObject<USpriteRenderer>("SlotImage3");
	SlotImage3->SetupAttachment(Root);
	SlotImage3->SetPivot(EPivot::BOT);
	SlotImage3->AddPosition(FVector(-15.0f, 135.0f, 0.0f));
	SlotImage3->AddRotationDeg(FVector(0.0f, 35.0f, 0.0f));
	
	SlotImage1->SetActive(false);
	SlotImage2->SetActive(false);
	SlotImage3->SetActive(false);

	WindSkill = CreateDefaultSubObject<USpriteRenderer>("WindSkill");

	WindSkill->SetupAttachment(Root);
	WindSkill->AddPosition(FVector(-450.0f, 350.0f, 0.0f));

	WindSkill->SetActive(false);

	BigBossCollision = CreateDefaultSubObject<UCollision>("BigBossCollision");
	BigBossCollision->SetupAttachment(Root);
	BigBossCollision->SetPosition(FVector(50.0f, 240.0f, 0.0f));
	BigBossCollision->SetScale(FVector(200.0f, 450.0f, 100.0f));
	BigBossCollision->SetCollisionGroup(ECollisionOrder::Boss1Monster2);
	BigBossCollision->SetCollisionType(ECollisionType::RotRect);

	WindCollision = CreateDefaultSubObject<UCollision>("WindCollision");
	WindCollision->SetupAttachment(Root);
	WindCollision->SetPosition(FVector( -300.0f,220.0f, 0.0f));
	WindCollision->SetScale(FVector(1100.0f, 500.0f, 100.0f));
	WindCollision->SetCollisionGroup(ECollisionOrder::Wind);
	WindCollision->SetCollisionType(ECollisionType::RotRect);

	HandCollision = CreateDefaultSubObject<UCollision>("HandCollision");
	HandCollision->SetupAttachment(Root);
	HandCollision->SetPosition(FVector(-395.0f, 290.0f, 100.0f));
	HandCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	HandCollision->SetCollisionGroup(ECollisionOrder::Boss1Monster2Hand);
	HandCollision->SetCollisionType(ECollisionType::RotRect);

	WindCollision->SetActive(false);
	HandCollision->SetActive(false);
	SetRoot(Root);

	
}

ABoss1_Monster2::~ABoss1_Monster2()
{
}

void ABoss1_Monster2::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(324.0f, 350.0f, 0.0f));
	SetActorLocation(FVector(380.0f, -270.0f, 0.0f));
	BigBoss1->SetOrder(ERenderOrder::Monster1);
	BigBoss1->SetSprite("tallfrog_idle_0001.png");
	BigBoss1->SetSamplering(ETextureSampling::LINEAR);
	BigBoss1->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	SlotMouse->SetOrder(ERenderOrder::SlotMouse);
	SlotMouse->SetSprite("tallfrog_slotman_spit_0001.png");
	SlotMouse->SetSamplering(ETextureSampling::LINEAR);
	SlotMouse->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	SlotImage1->SetOrder(ERenderOrder::SlotImage);
	SlotImage1->SetSprite("TEMP1.png");
	SlotImage1->SetSamplering(ETextureSampling::LINEAR);

	SlotImage2->SetOrder(ERenderOrder::SlotImage);
	SlotImage2->SetSprite("TEMP1.png");
	SlotImage2->SetSamplering(ETextureSampling::LINEAR);

	SlotImage3->SetOrder(ERenderOrder::SlotImage);
	SlotImage3->SetSprite("TEMP1.png");
	SlotImage3->SetSamplering(ETextureSampling::LINEAR);

	FrontSlot->SetOrder(ERenderOrder::ObjectFront2);
	FrontSlot->SetSprite("tallfrog_slotman_attack_top_0001.png");
	FrontSlot->SetSamplering(ETextureSampling::LINEAR);
	FrontSlot->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));


	

	WindSkill->SetOrder(ERenderOrder::Monster1);
	WindSkill->SetSprite("tallfrog_fan_wind_0001.png");
	WindSkill->SetSamplering(ETextureSampling::LINEAR);
	WindSkill->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));


	AniCreate();
	Phase1StateInit();

	BigBoss1->SetAutoSize(1.0f, true);
	SlotMouse->SetAutoSize(1.0f, true);
	SlotImage1->SetAutoSize(1.0f, true);
	SlotImage2->SetAutoSize(1.0f, true);
	SlotImage3->SetAutoSize(1.0f, true);
	WindSkill->SetAutoSize(1.0f, true);
	FrontSlot->SetAutoSize(1.0f, true);

	WindSkill->ChangeAnimation("Wind");
	FrontSlot->ChangeAnimation("SlotFront");
}

void ABoss1_Monster2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	DamgeColorDelay -= _DeltaTime;

	if (DamgeColorDelay < 0)
	{
		BigBoss1->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
		FrontSlot->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
		SlotMouse->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
		DamgeColorDelay = 0.35f;
	}

	coolDownTime -= _DeltaTime;
	if (1 == phasecheck || 2 == phasecheck)
	{
		Phase1.Update(_DeltaTime);
	}
	else if (3 == phasecheck)
	{
		Phase2.Update(_DeltaTime);
	}
}

void ABoss1_Monster2::Phase1StateInit()
{

	Phase1.CreateState("bigintro");
	Phase1.CreateState("bigIdle");
	Phase1.CreateState("bigattReady1");
	Phase1.CreateState("bigattReady2");
	Phase1.CreateState("bigatt");
	Phase1.CreateState("bigattEnd");
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

	Phase1.SetUpdateFunction("bigattReady1", std::bind(&ABoss1_Monster2::bigattReady1, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigattReady1", [=] {BigBoss1->ChangeAnimation("bigattReady1"); });

	Phase1.SetUpdateFunction("bigattReady2", std::bind(&ABoss1_Monster2::bigattReady2, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigattReady2", [=] {BigBoss1->ChangeAnimation("bigattReady2"); });

	Phase1.SetUpdateFunction("bigatt", std::bind(&ABoss1_Monster2::bigatt, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigatt", [=] {BigBoss1->ChangeAnimation("bigatt"); });

	Phase1.SetUpdateFunction("bigattEnd", std::bind(&ABoss1_Monster2::bigattEnd, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigattEnd", [=] {BigBoss1->ChangeAnimation("bigattEnd"); });

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
	Phase2.CreateState("phase3Intro");
	Phase2.CreateState("phase3Intro2");
	Phase2.CreateState("phase3Idle");
	Phase2.CreateState("CoinAtt");
	Phase2.CreateState("Phase3SlotReady");
	Phase2.CreateState("Phase3Slot");
	Phase2.CreateState("Phase3SlotCoinAtt");
	Phase2.CreateState("Phase3SlotStart");
	Phase2.CreateState("Phase3AttReady");
	Phase2.CreateState("Phase3Att");
	Phase2.CreateState("Phase3AttEnd");
	Phase2.CreateState("DieTransition");
	Phase2.CreateState("LastDie");


	Phase2.SetUpdateFunction("phase3Intro", std::bind(&ABoss1_Monster2::phase3Intro, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase3Intro", [=] {BigBoss1->ChangeAnimation("phase3Intro"); });

	Phase2.SetUpdateFunction("phase3Intro2", std::bind(&ABoss1_Monster2::phase3Intro2, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase3Intro2", [=] {BigBoss1->ChangeAnimation("phase3Intro2"); });

	Phase2.SetUpdateFunction("phase3Idle", std::bind(&ABoss1_Monster2::phase3Idle, this, std::placeholders::_1));
	Phase2.SetStartFunction("phase3Idle", [=] {BigBoss1->ChangeAnimation("phase3Idle"); });

	Phase2.SetUpdateFunction("CoinAtt", std::bind(&ABoss1_Monster2::CoinAtt, this, std::placeholders::_1));
	Phase2.SetStartFunction("CoinAtt", [=] {SlotMouse->ChangeAnimation("CoinAtt"); });

	Phase2.SetUpdateFunction("Phase3SlotReady", std::bind(&ABoss1_Monster2::Phase3SlotReady, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3SlotReady", [=] {BigBoss1->ChangeAnimation("Phase3SlotReady"); });
	
	Phase2.SetUpdateFunction("Phase3Slot", std::bind(&ABoss1_Monster2::Phase3Slot, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3Slot", [=] {BigBoss1->ChangeAnimation("Phase3Slot"); });

	Phase2.SetUpdateFunction("Phase3SlotCoinAtt", std::bind(&ABoss1_Monster2::Phase3SlotCoinAtt, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3SlotCoinAtt", [=] {SlotMouse->ChangeAnimation("CoinAtt"); });

	Phase2.SetUpdateFunction("Phase3SlotStart", std::bind(&ABoss1_Monster2::Phase3SlotStart, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3SlotStart", [=] {BigBoss1->ChangeAnimation("Phase3SlotStart"); });

	Phase2.SetUpdateFunction("Phase3AttReady", std::bind(&ABoss1_Monster2::Phase3AttReady, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3AttReady", [=] {BigBoss1->ChangeAnimation("Phase3AttReady"); });

	Phase2.SetUpdateFunction("Phase3Att", std::bind(&ABoss1_Monster2::Phase3Att, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3Att", [=] {BigBoss1->ChangeAnimation("Phase3Att"); });

	Phase2.SetUpdateFunction("Phase3AttEnd", std::bind(&ABoss1_Monster2::Phase3AttEnd, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3AttEnd", [=] {BigBoss1->ChangeAnimation("Phase3AttEnd"); });

	Phase2.SetUpdateFunction("DieTransition", std::bind(&ABoss1_Monster2::DieTransition, this, std::placeholders::_1));
	Phase2.SetStartFunction("DieTransition", [=] {BigBoss1->ChangeAnimation("DieTransition"); });

	Phase2.SetUpdateFunction("LastDie", std::bind(&ABoss1_Monster2::LastDie, this, std::placeholders::_1));
	Phase2.SetStartFunction("LastDie", [=] {BigBoss1->ChangeAnimation("LastDie"); });

	Phase2.ChangeState("phase3Intro");
}

void ABoss1_Monster2::AniCreate()
{
	BigBoss1->CreateAnimation("bigintro", "bigintro", 0.12f);
	BigBoss1->CreateAnimation("bigIdle", "bigIdle", 0.075f);
	BigBoss1->CreateAnimation("bigattReady1", "bigattReady1", 0.075f);
	BigBoss1->CreateAnimation("bigattReady2", "bigattReady1", 0.1f,true,9,10);
	BigBoss1->CreateAnimation("bigatt", "bigatt", 0.065f);
	BigBoss1->CreateAnimation("bigattEnd", "bigattEnd", 0.035f);

	BigBoss1->CreateAnimation("bigatt2Ready", "bigatt2Ready", 0.1f);
	BigBoss1->CreateAnimation("bigatt2Ready2", "bigatt2Ready2", 0.1f);
	BigBoss1->CreateAnimation("bigatt2", "bigatt2", 0.1f);
	BigBoss1->CreateAnimation("bigatt2end", "bigatt2end", 0.1f);
	BigBoss1->CreateAnimation("phase3changeReady1", "phase3changeReady1", 0.1f);
	BigBoss1->CreateAnimation("phase3changeReady2", "phase3changeReady2", 0.1f);

	BigBoss1->CreateAnimation("phase3Intro", "phase3Intro", 0.075f);
	BigBoss1->CreateAnimation("phase3Intro2", "phase3Intro2", 0.075f);
	BigBoss1->CreateAnimation("phase3Idle", "phase3SlotIdle", 0.1f);
	BigBoss1->CreateAnimation("Phase3SlotReady", "Phase3SlotReady", 0.1f, false);
	BigBoss1->CreateAnimation("Phase3Slot", "Phase3Slot", 0.075f);

	BigBoss1->CreateAnimation("Phase3SlotStart", "Phase3SlotReady", 0.1f, false, 8, 0);

	BigBoss1->CreateAnimation("Phase3AttReady", "Phase3AttReady", 0.075f);
	BigBoss1->CreateAnimation("Phase3Att", "Phase3Att", 0.075f);
	BigBoss1->CreateAnimation("Phase3AttEnd", "Phase3AttReady", 0.075f,false,6,0);

	BigBoss1->CreateAnimation("DieTransition", "DieTransition", 0.075f);
	BigBoss1->CreateAnimation("LastDie", "LastDie", 0.075f);

	SlotMouse->CreateAnimation("CoinAtt", "CoinAtt", 0.1f);

	
	SlotImage1->CreateAnimation("slotObject1", "TEMP2.png", 0.1f, false, 0, 0);
	SlotImage1->CreateAnimation("slotObject2", "TEMP2.png", 0.1f, false, 0, 1);
	SlotImage1->CreateAnimation("slotObject3", "TEMP2.png", 0.1f, false, 1, 2);

	SlotImage2->CreateAnimation("slotObject1", "TEMP2.png", 0.1f, false, 0, 0);
	SlotImage2->CreateAnimation("slotObject2", "TEMP2.png", 0.1f, false, 0, 1);
	SlotImage2->CreateAnimation("slotObject3", "TEMP2.png", 0.1f, false, 1, 2);

	SlotImage3->CreateAnimation("slotObject1", "TEMP2.png", 0.1f, false, 0, 0);
	SlotImage3->CreateAnimation("slotObject2", "TEMP2.png", 0.1f, false, 0, 1);
	SlotImage3->CreateAnimation("slotObject3", "TEMP2.png", 0.1f, false, 1, 2);

	WindSkill->CreateAnimation("Wind", "Wind", 0.12f);

	FrontSlot->CreateAnimation("SlotFront", "SlotFront", 0.07f);

}



void ABoss1_Monster2::createSkill()
{
	RandomSkillDelay = UEngineRandom::MainRandom.RandomFloat(0.3f, 1.5f);


	NewFirefly = GetWorld()->SpawnActor<AFirefly>("Firefly");

	NewFirefly->SetDelay(RandomSkillDelay);

	if (Bigattcount == 1 || Bigattcount == 4 || Bigattcount == 6)
	{
		NewFirefly->SetMove(FVector::Left + (FVector::Up*0.2f));
		return;
	}

	NewFirefly->SetMove(FVector::Left);
}

void ABoss1_Monster2::createCoinAtt()
{
	NewCoin = GetWorld()->SpawnActor<ACoin>("Coin");
}

void ABoss1_Monster2::createObject()
{
	if (SlotAttCount == 0)
	{
		NewMoveObject1 = GetWorld()->SpawnActor<AMoveObject1>("MoveObject1");

		if (0 == Bigattcount % 5)
		{
			NewMoveObject1->SetUpDownSet(FVector::Down);
		}
		else {
			NewMoveObject1->SetUpDownSet(FVector::Up);
		}

	}else if (SlotAttCount == 1)
	{
		NewMoveObject3 = GetWorld()->SpawnActor<AMoveObject3>("MoveObject3");
	}
	else if (SlotAttCount == 2)
	{
		NewMoveObject2 = GetWorld()->SpawnActor<AMoveObject2>("MoveObject2");
	}
}

void ABoss1_Monster2::WindCollisioncheck(float _DeltaTime)
{
	WindCollision->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);
		Player->AddCollisionMove(FVector::Left * WindSpeed*_DeltaTime);
	});
}

void ABoss1_Monster2::Phase3Collisioncheck()
{
	BigBossCollision->CollisionEnter(ECollisionOrder::Boss1Monster1, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster1* Monster = dynamic_cast<ABoss1_Monster1*>(Ptr);
		Monster->Destroy();

		Change3 = true;
	});
}

void ABoss1_Monster2::SlotStartImage(float _DeltaTime)
{

	if (true==ISSlotSpeed)
	{
		SlotSpeed = 2.89f;
	}

	if (false==ISSlotSpeed)
	{
		SlotSpeed = 3.0f;
	}

	VertexY.Y -= (_DeltaTime* SlotSpeed);

	SlotImage1->SetVertexUVPlus(VertexY);
	SlotImage2->SetVertexUVPlus(VertexY);
	SlotImage3->SetVertexUVPlus(VertexY);
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
		attOrder = false;
		Phase1.ChangeState("phase3changeReady1");
		return;
	}

	if (coolDownTime < 0 && 1 == phasecheck && true == attOrder)
	{
		Phase1.ChangeState("bigattReady1");
		return;
	}

	if (coolDownTime < 1.0f && 2 == phasecheck && false == attOrder)
	{
		Phase1.ChangeState("bigatt2Ready");
		return;
	}

}

void ABoss1_Monster2::bigattReady1(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("bigattReady2");
		return;
	}
}

void ABoss1_Monster2::bigattReady2(float _DeltaTime)
{
	att1Delay -= _DeltaTime;
	if (att1Delay<0)
	{
		att1Delay = 0.4f;
		Phase1.ChangeState("bigatt");
		return;
	}
}

void ABoss1_Monster2::bigatt(float _DeltaTime)
{

	BigBoss1->SetFrameCallback("bigatt", 4, [=] {createSkill(); });
	
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Bigattcount++;
		if (Bigattcount == 2 || Bigattcount == 3 || Bigattcount == 5)
		{
			Phase1.ChangeState("bigattReady1");
			return;
		}
	}

	if (Bigattcount > 6)
	{
		Phase1.ChangeState("bigattEnd");
		return;
	}
}

void ABoss1_Monster2::bigattEnd(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		coolDownTime = 6.0f;
		attOrder = false;
		Bigattcount = 0;
		Phase1.ChangeState("BigIdle");
		return;
	}
}

void ABoss1_Monster2::bigatt2Ready(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		attOrder = true;
		Phase1.ChangeState("bigatt2Ready2");
		return;
	}
}

void ABoss1_Monster2::bigatt2Ready2(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		WindSkill->SetActive(true);
		WindCollision->SetActive(true);
		Phase1.ChangeState("bigatt2");
		return;
	}
}

void ABoss1_Monster2::bigatt2(float _DeltaTime)
{

	WindCollisioncheck(_DeltaTime);
	if (GetActorLocation().iX() <= 430) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		AddActorLocation((FVector::Right*2.0f + FVector::Down) * 500.0f * _DeltaTime);
	}

	if (true == BigBoss1->IsCurAnimationEnd())
	{
		//createSkill();
		Bigattcount++;
	}

	if (Bigattcount > 24)
	{
		WindSkill->SetActive(false);
		WindCollision->SetActive(false);
		Phase1.ChangeState("bigatt2end");
		return;
	}
}

void ABoss1_Monster2::bigatt2end(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("BigIdle");
		coolDownTime = 7.0f;
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
	Phase3Collisioncheck();
	
	if (true == Change3)
	{
		phasecheck = 3;
		coolDownTime = 6.0f;
		Phase2StateInit();
		return;
	}
}

void ABoss1_Monster2::phase3Intro(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase2.ChangeState("phase3Intro2");
		return;
	}
}

void ABoss1_Monster2::phase3Intro2(float _DeltaTime)
{
	SlotImage1->SetActive(true);
	SlotImage2->SetActive(true);
	SlotImage3->SetActive(true);
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		coolDownTime = 6.0f;
		attOrder = false;
		Bigattcount = 0;
		Phase2.ChangeState("phase3Idle");
		return;
	}
}

void ABoss1_Monster2::phase3Idle(float _DeltaTime)
{
	if (GetHp() <= 0)
	{
		Phase2.ChangeState("DieTransition");
		return;
	}

	if (SlotAttCount == 3)
	{
		ISSlotSpeed = false;
		SlotAttCount = 0;
	}

	if (SlotAttCount == 2)
	{
		ISSlotSpeed = true;
	}

	if (coolDownTime < 0 && 3 == phasecheck && true == SlotTouch)
	{
		Phase2.ChangeState("Phase3AttReady");
		SlotMouse->SetActive(false);
		return;
	}

	if (coolDownTime < 0 && 3 == phasecheck && false == SlotTouch)
	{
		Phase2.ChangeState("CoinAtt");
		SlotMouse->SetActive(true);
		return;
	}
}

void ABoss1_Monster2::CoinAtt(float _DeltaTime)
{
	if (GetHp() <= 0)
	{
		Phase2.ChangeState("DieTransition");
		return;
	}

	if (Bigattcount == 1)
	{
		coolDownTime = 1.0f;
		SlotMouse->SetActive(false);
		Bigattcount++;
		Phase2.ChangeState("phase3Idle");
		return;
	}

	if (Bigattcount == 3)
	{
		SlotMouse->SetActive(false);
		Phase2.ChangeState("Phase3SlotReady");
		return;
	}

	if (true == SlotMouse->IsCurAnimationEnd())
	{
		createCoinAtt();
		Bigattcount++;
	}
}

void ABoss1_Monster2::Phase3SlotReady(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		coolDownTime = 3.0f;
		Bigattcount = 0;
		Phase2.ChangeState("Phase3Slot");
		return;
	}

}

void ABoss1_Monster2::Phase3Slot(float _DeltaTime)
{
	HandCollision->SetActive(true);
	if (GetHp() <= 0)
	{
		Phase2.ChangeState("DieTransition");
		return;
	}

	if (true == SlotTouch)
	{
		HandCollision->SetActive(false);
		Bigattcount = 0;
		coolDownTime = 4.0f;
		Phase2.ChangeState("Phase3SlotStart");
		SlotMouse->SetActive(false);
		return;
	}

	if (coolDownTime < 0 && 3 == phasecheck && false == SlotTouch)
	{
		Phase2.ChangeState("Phase3SlotCoinAtt");
		SlotMouse->SetActive(true);
		return;
	}
}

void ABoss1_Monster2::Phase3SlotCoinAtt(float _DeltaTime)
{
	if (GetHp() <= 0)
	{
		Phase2.ChangeState("DieTransition");
		return;
	}

	if (true == SlotTouch)
	{
		HandCollision->SetActive(false);
		SlotStartImage(_DeltaTime);
		Bigattcount = 0;
		coolDownTime = 3.0f;
		SlotMouse->SetActive(false);
		Phase2.ChangeState("Phase3SlotStart");
		return;
	}

	if (Bigattcount == 1)
	{
		coolDownTime = 1.0f;
		SlotMouse->SetActive(false);
		Bigattcount++;
		Phase2.ChangeState("Phase3Slot");
		return;
	}

	if (Bigattcount == 3)
	{
		coolDownTime = 3.0f;
		SlotMouse->SetActive(false);
		Bigattcount = 0;
		Phase2.ChangeState("Phase3Slot");
		return;
	}

	if (true == SlotMouse->IsCurAnimationEnd())
	{
		createCoinAtt();
		Bigattcount++;
	}
}

void ABoss1_Monster2::Phase3SlotStart(float _DeltaTime)
{
	if (GetHp() <= 0)
	{
		Phase2.ChangeState("DieTransition");
		return;
	}

	SlotStartImage(_DeltaTime);
	FrontSlot->ChangeAnimation("SlotFront");

	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Bigattcount = 0;
		Phase2.ChangeState("phase3Idle");
		return;
	}
}

void ABoss1_Monster2::Phase3AttReady(float _DeltaTime)
{
	if (GetHp() <= 0)
	{
		Phase2.ChangeState("DieTransition");
		return;
	}

	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Bigattcount = 0;
		FrontSlot->SetActive(true);
		Phase2.ChangeState("Phase3Att");
		return;
	}
}

void ABoss1_Monster2::Phase3Att(float _DeltaTime)
{
	if (GetHp() <= 0)
	{
		Phase2.ChangeState("DieTransition");
		return;
	}

	if (true == BigBoss1->IsCurAnimationEnd())
	{
		int n = 2;

		if (SlotAttCount == 0)
		{
			n = 3;
		}
		
		if (0 == Bigattcount % n)
		{
			createObject();
		}
		Bigattcount++;
		return;
	}

	if (SlotAttCount == 0)
	{
		if (Bigattcount == 39)
		{
			Phase2.ChangeState("Phase3AttEnd");
			return;
		}
	}
	else
	{
		if (Bigattcount == 26)
		{
			Phase2.ChangeState("Phase3AttEnd");
			return;
		}
	}
}

void ABoss1_Monster2::Phase3AttEnd(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		SlotAttCount++;
		coolDownTime = 4.0f;
		Bigattcount = 0;
		SlotTouch = false;
		FrontSlot->SetActive(false);
		Phase2.ChangeState("phase3Idle");
		return;
	}
}

void ABoss1_Monster2::DieTransition(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		GetWorld()->SpawnActor<AScreenEffect>("Knockout")->SetScreenEffect(EScreenEffect::Knockout);
		Phase2.ChangeState("LastDie");
		return;
	}
}

void ABoss1_Monster2::LastDie(float _DeltaTime)
{

}
