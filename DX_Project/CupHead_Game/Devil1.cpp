#include "PreCompile.h"
#include "Devil1.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "ContentsHelper.h"
#include "ScreenEffect.h"
#include "HeadAtt.h"
#include "RamArms.h"
#include "SpiderHead.h"
#include "DevilBall.h"
#include "Hole.h"
#include "Orb_Fire.h"
#include "Orb_Fire2.h"


ADevil1::ADevil1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");

	IntroAni = CreateDefaultSubObject<USpriteRenderer>("IntroAni");
	
	IntroAni->SetupAttachment(Root);

	IntroAni->SetOrder(ERenderOrder::Monster2);
	IntroAni->SetSprite("devil_intro_pupil_0002.png");
	IntroAni->SetSamplering(ETextureSampling::LINEAR);
	IntroAni->SetAutoSize(0.8f, true);
	IntroAni->SetPosition(FVector(-130.0f, -150.0f, 0.0f));

	PhaseChange2 = CreateDefaultSubObject<USpriteRenderer>("PhaseChange2");
	
	PhaseChange2->SetupAttachment(Root);

	PhaseChange2->SetOrder(ERenderOrder::BossSkillMonster);
	PhaseChange2->SetSprite("devil_intro_pupil_0002.png");
	PhaseChange2->SetSamplering(ETextureSampling::LINEAR);
	PhaseChange2->SetAutoSize(1.0f, true);

	Boss2 = CreateDefaultSubObject<USpriteRenderer>("Boss2");

	Boss2->SetupAttachment(Root);
	
	Boss2->SetOrder(ERenderOrder::Monster1);
	Boss2->SetSprite("devil_ph1_intro_0004.png");
	Boss2->SetSamplering(ETextureSampling::LINEAR);
	Boss2->SetAutoSize(1.0f, true);

	BossHead= CreateDefaultSubObject<USpriteRenderer>("BossHead");

	BossHead->SetupAttachment(Root);

	BossHead->SetOrder(ERenderOrder::Monster2);
	BossHead->SetSprite("devil_ph1_trident_spin_head_0001.png");
	BossHead->SetSamplering(ETextureSampling::LINEAR);
	BossHead->SetAutoSize(1.0f, true);

	BossHead->AddPosition(FVector(-50.0f, 230.0f, 0.0f));

	BossBody = CreateDefaultSubObject<USpriteRenderer>("BossBody");
	
	BossBody->SetupAttachment(Root);
	
	BossBody->SetOrder(ERenderOrder::Monster2);
	BossBody->SetSprite("devil_ph1_trident_spin_body_0001.png");
	BossBody->SetSamplering(ETextureSampling::LINEAR);
	BossBody->SetAutoSize(1.0f, true);

	BossBody->AddPosition(FVector(-50.0f, -75.0f, 0.0f));

	spear = CreateDefaultSubObject<USpriteRenderer>("spear");
	
	spear->SetupAttachment(Root);

	spear->SetOrder(ERenderOrder::backSkill);
	spear->SetSprite("devil_ph1_trident_spin_attack_0001.png");
	spear->SetSamplering(ETextureSampling::LINEAR);
	spear->SetAutoSize(1.0f, true);
	
	spear->AddPosition(FVector(-40.0f, -22.0f, 0.0f));


	Boss2Phase2 = CreateDefaultSubObject<UCollision>("Boss2Phase2");
	Boss2Phase2->SetupAttachment(Root);
	Boss2Phase2->SetPosition(FVector(-30.0f, -350.0f, 0.0f));
	Boss2Phase2->SetScale(FVector(5.0f, 100.0f, 100.0f));
	Boss2Phase2->SetCollisionGroup(ECollisionOrder::Devil1Change);
	Boss2Phase2->SetCollisionType(ECollisionType::RotRect);

	Devil1 = CreateDefaultSubObject<UCollision>("Devil1");
	Devil1->SetupAttachment(Root);
	Devil1->AddPosition(FVector(-30.0f, 50.0f, 0.0f));
	Devil1->SetScale(FVector(200.0f, 250.0f, 100.0f));
	Devil1->SetCollisionGroup(ECollisionOrder::Devil1);
	Devil1->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);

	

}

ADevil1::~ADevil1()
{
	NewFireS.clear();
	NewDevilBalls.clear();
}

void ADevil1::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(30.0f, 50.0f, 10.0f));
	AniCreate();
	BossHead->SetActive(false);
	BossBody->SetActive(false);
	spear->SetActive(false);
	Phase1StateInit();

	PhaseChange2->SetActive(false);
	Boss2Phase2->SetActive(false);
	//IntroAni->ChangeAnimation("PupilIntro");

	NewFireS.resize(6);
	NewDevilBalls.resize(4);

	UContentsHelper::DelMapCheck = false;
	phasecheck = 1;
	SetHp(100);
}

void ADevil1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	DamgeColorDelay -= _DeltaTime;

	if (DamgeColorDelay < 0)
	{
		Boss2->SetPlusColor(FVector(0.0f, 0.0f, 0.0f));
		DamgeColorDelay = 0.35f;
	}

	coolDownTime -= _DeltaTime;
	Phase1.Update(_DeltaTime);
}

void ADevil1::Phase1StateInit()
{
	Phase1.CreateState("Phase1Intro");
	Phase1.CreateState("Phase1Idle");
	Phase1.CreateState("DragonTransform");
	Phase1.CreateState("DragonIdle");
	Phase1.CreateState("DragonReverse");
	Phase1.CreateState("RamTransform");
	Phase1.CreateState("RamIdle");
	Phase1.CreateState("RamReverse");
	Phase1.CreateState("SpiderTransform");
	Phase1.CreateState("SpiderIdle");
	Phase1.CreateState("SpiderReverse");
	Phase1.CreateState("CreateOrbsIntro");
	Phase1.CreateState("CreateOrbsIntro2");
	Phase1.CreateState("CreateOrbsReverse");
	Phase1.CreateState("Phase1Death");
	Phase1.CreateState("Phase2Change");

	Phase1.SetUpdateFunction("Phase1Intro", std::bind(&ADevil1::Phase1Intro, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase1Intro", [=] {IntroAni->ChangeAnimation("PupilIntro"); });

	Phase1.SetUpdateFunction("Phase1Idle", std::bind(&ADevil1::Phase1Idle, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase1Idle", [=] {Boss2->ChangeAnimation("Phase1Idle"); });

	Phase1.SetUpdateFunction("DragonTransform", std::bind(&ADevil1::DragonTransform, this, std::placeholders::_1));
	Phase1.SetStartFunction("DragonTransform", [=] {Boss2->ChangeAnimation("DragonTransform"); });

	Phase1.SetUpdateFunction("DragonIdle", std::bind(&ADevil1::DragonIdle, this, std::placeholders::_1));
	Phase1.SetStartFunction("DragonIdle", [=] {Boss2->ChangeAnimation("DragonIdle"); });
	
	Phase1.SetUpdateFunction("DragonReverse", std::bind(&ADevil1::DragonReverse, this, std::placeholders::_1));
	Phase1.SetStartFunction("DragonReverse", [=] {Boss2->ChangeAnimation("DragonReverse"); });

	Phase1.SetUpdateFunction("RamTransform", std::bind(&ADevil1::RamTransform, this, std::placeholders::_1));
	Phase1.SetStartFunction("RamTransform", [=] {Boss2->ChangeAnimation("RamTransform"); });

	Phase1.SetUpdateFunction("RamIdle", std::bind(&ADevil1::RamIdle, this, std::placeholders::_1));
	Phase1.SetStartFunction("RamIdle", [=] {Boss2->ChangeAnimation("RamIdle"); });

	Phase1.SetUpdateFunction("RamReverse", std::bind(&ADevil1::RamReverse, this, std::placeholders::_1));
	Phase1.SetStartFunction("RamReverse", [=] {Boss2->ChangeAnimation("RamReverse"); });

	Phase1.SetUpdateFunction("SpiderTransform", std::bind(&ADevil1::SpiderTransform, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderTransform", [=] {Boss2->ChangeAnimation("SpiderTransform"); });

	Phase1.SetUpdateFunction("SpiderIdle", std::bind(&ADevil1::SpiderIdle, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderIdle", [=] {Boss2->ChangeAnimation("SpiderIdle"); });

	Phase1.SetUpdateFunction("SpiderReverse", std::bind(&ADevil1::SpiderReverse, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderReverse", [=] {Boss2->ChangeAnimation("SpiderReverse"); });

	Phase1.SetUpdateFunction("CreateOrbsIntro", std::bind(&ADevil1::CreateOrbsIntro, this, std::placeholders::_1));
	Phase1.SetStartFunction("CreateOrbsIntro", [=] {Boss2->ChangeAnimation("CreateOrbsIntro"); });

	Phase1.SetUpdateFunction("CreateOrbsIntro2", std::bind(&ADevil1::CreateOrbsIntro2, this, std::placeholders::_1));

	Phase1.SetUpdateFunction("CreateOrbsReverse", std::bind(&ADevil1::CreateOrbsReverse, this, std::placeholders::_1));
	Phase1.SetStartFunction("CreateOrbsReverse", [=] {Boss2->ChangeAnimation("CreateOrbsReverse"); });

	Phase1.SetUpdateFunction("Phase1Death", std::bind(&ADevil1::Phase1Death, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase1Death", [=] {Boss2->ChangeAnimation("Phase1Death"); });

	Phase1.SetUpdateFunction("Phase2Change", std::bind(&ADevil1::Phase2Change, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase2Change", [=] {Boss2->ChangeAnimation("Phase2Change"); });

	Phase1.ChangeState("Phase1Intro");
}

void ADevil1::AniCreate()
{
	Boss2->CreateAnimation("Phase1Intro", "DevilIntro", 0.1f);
	Boss2->CreateAnimation("Phase1Idle", "DevilIdle", 0.075f);
	Boss2->CreateAnimation("DragonTransform", "DragonTransform", 0.075f);
	Boss2->CreateAnimation("DragonIdle", "DragonIdle", 0.075f);
	Boss2->CreateAnimation("DragonReverse", "DragonTransform", 0.055f,false,31,2);

	Boss2->CreateAnimation("RamTransform", "RamTransform", 0.075f);
	Boss2->CreateAnimation("RamIdle", "RamIdle", 0.075f);
	Boss2->CreateAnimation("RamReverse", "RamTransform", 0.055f, true, 27, 2);

	Boss2->CreateAnimation("SpiderTransform", "SpiderTransform", 0.075f);
	Boss2->CreateAnimation("SpiderIdle", "SpiderIdle", 0.075f);
	Boss2->CreateAnimation("SpiderReverse", "SpiderTransform", 0.055f, false, 53, 2);

	Boss2->CreateAnimation("CreateOrbsIntro", "CreateOrbsIntro", 0.075f);
	Boss2->CreateAnimation("CreateOrbsReverse", "CreateOrbsIntro", 0.055f,false,7,0);

	BossHead->CreateAnimation("CreateOrbsHead", "CreateOrbsHead", 0.075f);
	BossBody->CreateAnimation("CreateOrbsBody", "CreateOrbsBody", 0.075f);
	spear->CreateAnimation("CreateOrbsTrident", "CreateOrbsTrident", 0.075f);
	IntroAni->CreateAnimation("PupilIntro", "PupilIntro", 0.055f);
	PhaseChange2->CreateAnimation("Phase1Death", "Phase1Death", 0.075f,false);

	Boss2->CreateAnimation("Phase1Death", "Phase1Death", 0.075f);
	Boss2->CreateAnimation("Phase2Change", "Phase2Change", 0.075f);

}

void ADevil1::CreateHeadAtt()
{
	NewHeadAtt = GetWorld()->SpawnActor<AHeadAtt>("HeadAtt");
}

void ADevil1::CreateRamArms()
{
	NewRamArmsL = GetWorld()->SpawnActor<ARamArms>("RamArmsL");

	NewRamArmsL->SetActorLocation(FVector(-900.0f, -180.0f, 0.0f));
	NewRamArmsL->GetRamArms()->SetDir(EEngineDir::Right);
	NewRamArmsL->SetSmallSkillDir(FVector::Right);
	
	NewRamArmsR = GetWorld()->SpawnActor<ARamArms>("RamArmsR");
	NewRamArmsR->SetActorLocation(FVector(900.0f, -180.0f, 0.0f));
	NewRamArmsR->GetRamArms()->SetDir(EEngineDir::Left);
	NewRamArmsR->SetSmallSkillDir(FVector::Left);
	//SkillYMove();
}

void ADevil1::CreateSpider()
{
	NewSpiderHead = GetWorld()->SpawnActor<ASpiderHead>("SpiderHead");
}

void ADevil1::CreateBall()
{
	
	for (int i = 0; i < NewDevilBalls.size(); i++)
	{
		NewDevilBalls[i]= GetWorld()->SpawnActor<ADevilBall>("DevilBall1");
	}


	NewDevilBalls[0]->SetParryCheck(true);

	NewDevilBalls[0]->SetActorLocation(FVector(200.0f, 150.0f, 10.0f));
	NewDevilBalls[1]->SetActorLocation(FVector(-200.0f, 200.0f, 10.0f));
	NewDevilBalls[2]->SetActorLocation(FVector(-200.0f, -150.0f, 10.0f));
	NewDevilBalls[3]->SetActorLocation(FVector(200.0f, -200.0f, 10.0f));

	NewDevilBalls[0]->SetStartPos(FVector::Up*0.2f + FVector::Right);
	NewDevilBalls[1]->SetStartPos(FVector::Up + FVector::Left);
	NewDevilBalls[2]->SetStartPos(FVector::Down*0.2f + FVector::Left);
	NewDevilBalls[3]->SetStartPos(FVector::Down + FVector::Right);

	NewDevilBalls[0]->SetWallHitCount(7);
	NewDevilBalls[1]->SetWallHitCount(8);
	NewDevilBalls[2]->SetWallHitCount(7);
	NewDevilBalls[3]->SetWallHitCount(8);
}

void ADevil1::CreateFire()
{
	
	for (int i = 0; i < NewFireS.size(); i++)
	{
		NewFireS[i] = GetWorld()->SpawnActor<AOrb_Fire>("Orb_Fire");
		NewFireS[i]->SetDelay(static_cast<float>(i + 1));
	}

	NewFireS[1]->SetParryCheck(true);

	NewFireS[0]->SetActorLocation(FVector(-250.0f, 150.0f, 10.0f));
	NewFireS[1]->SetActorLocation(FVector(0.0f, 250.0f, 10.0f));
	NewFireS[2]->SetActorLocation(FVector(250.0f, 150.0f, 10.0f));
	NewFireS[3]->SetActorLocation(FVector(250.0f, -150.0f, 10.0f));
	NewFireS[4]->SetActorLocation(FVector(0.0f, -250.0f, 10.0f));
	NewFireS[5]->SetActorLocation(FVector(-250.0f, -150.0f, 10.0f));

}

void ADevil1::CreateFire2()
{

	
	NewFire2 = GetWorld()->SpawnActor<AOrb_Fire2>("Orb_Fire2");
	
}

void ADevil1::Phase1Intro(float _DeltaTime)
{

	Boss2->SetPosition(FVector(-60.0f, 0.0f, 0.0f));

	if (true == IntroAni->IsCurAnimationEnd())
	{
		Boss2->ChangeAnimation("Phase1Intro");
		IntroAni->SetActive(false);
	}

	if (false == IntroAni->IsActive())
	{
		if (false == OneCheck)
		{
			OneCheck = true;
			GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect")->SetScreenEffect(EScreenEffect::ReadyWALLOP);
		}

		if (true == Boss2->IsCurAnimationEnd())
		{
			Boss2->SetPosition(FVector(0.0f, 0.0f, 0.0f));
			Phase1.ChangeState("Phase1Idle");
			return;
		}
	}
}

void ADevil1::Phase1Idle(float _DeltaTime)
{
	if (phasecheck == 1 && GetHp() <= 75)
	{
		AddActorLocation(FVector(45.0f, 20.0f, 0.0f));
		Boss2Phase2->AddPosition(FVector(-45.0f, -20.0f, 0.0f));
		phasecheck = 2;
		PhaseChange2->SetActive(true);
		PhaseChange2->ChangeAnimation("Phase1Death");
		Phase1.ChangeState("Phase1Death");
		return;
	}

	if (coolDownTime < 0 && 1 == attOrder)
	{
		Phase1.ChangeState("CreateOrbsIntro");
		return;
	}

	if (coolDownTime < 0 && 2 == attOrder)
	{
		Boss2->SetPosition(FVector(-60.0f, 0.0f, 0.0f));
		Phase1.ChangeState("SpiderTransform");
		return;
	}

	if (coolDownTime < 0 && 3 == attOrder)
	{
		Phase1.ChangeState("DragonTransform");
		return;
	}

	if (coolDownTime < 0 && 4== attOrder)
	{
		Boss2->SetPosition(FVector(-45.0f, 0.0f, 0.0f));
		Phase1.ChangeState("RamTransform");
		return;
	}
}

void ADevil1::DragonTransform(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		CreateHeadAtt();
		Phase1.ChangeState("DragonIdle");
		return;
	}
}

void ADevil1::DragonIdle(float _DeltaTime)
{
	if (true == SkillDestory)
	{
		Phase1.ChangeState("DragonReverse");
		return;
	}
}

void ADevil1::DragonReverse(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		coolDownTime = 6.0f;
		attOrder = 4;
		SkillDestory = false;
		Phase1.ChangeState("Phase1Idle");
		return;
	}
}

void ADevil1::RamTransform(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		CreateRamArms();
		Phase1.ChangeState("RamIdle");
		return;
	}
}

void ADevil1::RamIdle(float _DeltaTime)
{
	if (true == SkillDestory)
	{
		Phase1.ChangeState("RamReverse");
		return;
	}
}

void ADevil1::RamReverse(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		coolDownTime = 6.0f;
		attOrder = 1;
		SkillDestory = false;
		Boss2->SetPosition(FVector(0.0f, 0.0f, 0.0f));
		Phase1.ChangeState("Phase1Idle");
		return;
	}
}

void ADevil1::SpiderTransform(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		CreateSpider();
		Phase1.ChangeState("SpiderIdle");
		return;
	}
}

void ADevil1::SpiderIdle(float _DeltaTime)
{
	if (true == SkillDestory)
	{
		Phase1.ChangeState("SpiderReverse");
		return;
	}
}

void ADevil1::SpiderReverse(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		coolDownTime = 6.0f;
		attOrder = 3;
		SkillDestory = false;
		Boss2->SetPosition(FVector(0.0f, 0.0f, 0.0f));
		Phase1.ChangeState("Phase1Idle");
		return;
	}
}

void ADevil1::CreateOrbsIntro(float _DeltaTime)
{
	Boss2->SetPosition(FVector(-50.0f, 20.0f, 0.0f));
	if (true == Boss2->IsCurAnimationEnd())
	{
		Boss2->SetActive(false);
		BossHead->SetActive(true);
		BossBody->SetActive(true);
		spear->SetActive(true);
		
		BossHead->ChangeAnimation("CreateOrbsHead");
		BossBody->ChangeAnimation("CreateOrbsBody");
		spear->ChangeAnimation("CreateOrbsTrident");
		Phase1.ChangeState("CreateOrbsIntro2");
		return;
	}
}

void ADevil1::CreateOrbsIntro2(float _DeltaTime)
{

	if (true == spear->IsCurAnimationEnd())
	{
		if (2 == OrbOrder)
		{
			CreateFire();
			OrbOrder++;
		}
		else if (1 == OrbOrder)
		{
			CreateFire2();
			OrbOrder++;
		}
		else if (3 == OrbOrder)
		{
			CreateBall();
			OrbOrder++;
		}
		Phase1.ChangeState("CreateOrbsReverse");
		Boss2->SetActive(true);
		BossHead->SetActive(false);
		BossBody->SetActive(false);
		spear->SetActive(false);

		return;
	}
}

void ADevil1::CreateOrbsReverse(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		coolDownTime = 6.0f;

		if (4 == OrbOrder)
		{
			OrbOrder = 1;
			attOrder = 2;
		}
		SkillDestory = false;
		Phase1.ChangeState("Phase1Idle");
		Boss2->SetPosition(FVector(0.0f, 0.0f, 0.0f));
	}
}

void ADevil1::Phase1Death(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		Boss2->SetPosition(FVector(-42.0f, -22.0f, 10.0f));
		Phase1.ChangeState("Phase2Change");
		return;
	}
}

void ADevil1::Phase2Change(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd() && false==Die)
	{
		attOrder = 1;
		coolDownTime = 6.0f;
		GetWorld()->SpawnActor<AHole>("Hole");
		Boss2->SetActive(false);
		Boss2Phase2->SetActive(true);
		Die = true;
	}

	if (true == Die && DieTime > -1.0f)
	{
		DieTime -= _DeltaTime;
		if (DieTime < 0)
		{
			Destroy();
		}
	}
}
