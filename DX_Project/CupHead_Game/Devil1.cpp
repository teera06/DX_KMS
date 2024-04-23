#include "PreCompile.h"
#include "Devil1.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "HeadAtt.h"
#include "RamArms.h"
#include "SpiderHead.h"
#include "DevilBall.h"


ADevil1::ADevil1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");
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
	SetRoot(Root);

	

}

ADevil1::~ADevil1()
{
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
}

void ADevil1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
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

	Phase1.SetUpdateFunction("Phase1Intro", std::bind(&ADevil1::Phase1Intro, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase1Intro", [=] {Boss2->ChangeAnimation("Phase1Intro"); });

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
}

void ADevil1::CreateHeadAtt()
{
	NewHeadAtt = GetWorld()->SpawnActor<AHeadAtt>("HeadAtt");
	//NewHeadAtt->SetSmallSkillDir(FVector::Left);
	//SkillYMove();
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
	NewDevilBall1 = GetWorld()->SpawnActor<ADevilBall>("DevilBall1");
	NewDevilBall2 = GetWorld()->SpawnActor<ADevilBall>("DevilBall2");
	NewDevilBall3 = GetWorld()->SpawnActor<ADevilBall>("DevilBall3");
	NewDevilBall4 = GetWorld()->SpawnActor<ADevilBall>("DevilBall4");

	NewDevilBall1->SetParryCheck(true);

	NewDevilBall1->SetActorLocation(FVector(200.0f, 150.0f, 10.0f));
	NewDevilBall2->SetActorLocation(FVector(-200.0f, 200.0f, 10.0f));
	NewDevilBall3->SetActorLocation(FVector(-200.0f, -150.0f, 10.0f));
	NewDevilBall4->SetActorLocation(FVector(200.0f, -200.0f, 10.0f));

	NewDevilBall1->SetStartPos(FVector::Up*0.2f + FVector::Right);
	NewDevilBall2->SetStartPos(FVector::Up + FVector::Left);
	NewDevilBall3->SetStartPos(FVector::Down*0.2f + FVector::Left);
	NewDevilBall4->SetStartPos(FVector::Down + FVector::Right);

	NewDevilBall1->SetWallHitCount(7);
	NewDevilBall2->SetWallHitCount(6);
	NewDevilBall3->SetWallHitCount(7);
	NewDevilBall4->SetWallHitCount(6);
}

void ADevil1::Phase1Intro(float _DeltaTime)
{
	Boss2->SetPosition(FVector(-60.0f, 0.0f, 0.0f));
	if (true == Boss2->IsCurAnimationEnd())
	{
		Boss2->SetPosition(FVector(0.0f, 0.0f, 0.0f));
		Phase1.ChangeState("Phase1Idle");
		return;
	}

}

void ADevil1::Phase1Idle(float _DeltaTime)
{

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
		CreateBall();
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
		attOrder = 2;
		SkillDestory = false;
		Phase1.ChangeState("Phase1Idle");
		Boss2->SetPosition(FVector(0.0f, 0.0f, 0.0f));
	}
}
