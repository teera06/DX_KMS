#include "PreCompile.h"
#include "Devil1.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "HeadAtt.h"
#include "RamArms.h"

ADevil1::ADevil1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");
	Boss2 = CreateDefaultSubObject<USpriteRenderer>("Boss2");

	Boss2->SetupAttachment(Root);
	//Boss2->SetPivot(EPivot::LEFTTOP);

	SetRoot(Root);

	Boss2->SetOrder(ERenderOrder::Monster1);
	Boss2->SetSprite("devil_ph1_intro_0004.png");
	Boss2->SetSamplering(ETextureSampling::LINEAR);
	Boss2->SetAutoSize(1.0f, true);
}

ADevil1::~ADevil1()
{
}

void ADevil1::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(30.0f, 50.0f, 10.0f));
	AniCreate();

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
		Boss2->SetPosition(FVector(-60.0f, 0.0f, 0.0f));
		Phase1.ChangeState("SpiderTransform");
		return;
	}

	if (coolDownTime < 0 && 2 == attOrder)
	{
		Phase1.ChangeState("DragonTransform");
		return;
	}

	if (coolDownTime < 0 && 3== attOrder)
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
		attOrder = 2;
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
		attOrder = 2;
		SkillDestory = false;
		Phase1.ChangeState("Phase1Idle");
		return;
	}
}

void ADevil1::SpiderTransform(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		Phase1.ChangeState("SpiderIdle");
		return;
	}
}

void ADevil1::SpiderIdle(float _DeltaTime)
{
}
