#include "PreCompile.h"
#include "Devil2.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "BombBat.h"
#include "Axe.h"
#include "Imp.h"
#include "FatDemon.h"


ADevil2::ADevil2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");
	Boss2 = CreateDefaultSubObject<USpriteRenderer>("Boss2");

	Boss2->SetupAttachment(Root);

	Boss2->SetOrder(ERenderOrder::Monster2);
	Boss2->SetSprite("devil_ph3_idle_0001.png");
	Boss2->SetSamplering(ETextureSampling::LINEAR);
	Boss2->SetAutoSize(0.8f, true);

	DevilNeck = CreateDefaultSubObject<USpriteRenderer>("DevilNeck");
	
	DevilNeck->SetupAttachment(Root);
	
	DevilNeck->SetOrder(ERenderOrder::Monster1);
	DevilNeck->SetSprite("devil_ph3_neck_boil_0001.png");
	DevilNeck->SetSamplering(ETextureSampling::LINEAR);
	DevilNeck->SetAutoSize(0.8f, true);
	
	Hand = CreateDefaultSubObject<USpriteRenderer>("Hand");

	Hand->SetupAttachment(Root);

	Hand->SetOrder(ERenderOrder::FrontSkillMonster);
	Hand->SetSprite("devil_ph3_demon_hand_0001.png");
	Hand->SetSamplering(ETextureSampling::LINEAR);
	Hand->SetAutoSize(0.8f, true);

	SetRoot(Root);

	Hand->SetActive(false);
	DevilNeck->AddPosition(FVector(40.0f, -400.0f, 0.0f));
}

ADevil2::~ADevil2()
{
}

void ADevil2::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 90.0f, 10.0f));

	AniCreate();
	DevilNeck->ChangeAnimation("DevilNeck");
	Phase1StateInit();
}

void ADevil2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	coolDownTime -= _DeltaTime;
	UpdateDelay -= _DeltaTime;
	if (phasecheck == 2 && UpdateDelay<0)
	{
		Phase1.Update(_DeltaTime);
	}
	else if (phasecheck == 3)
	{
		Phase2.Update(_DeltaTime);
	}
	
}

void ADevil2::Phase1StateInit()
{
	Phase1.CreateState("DevilPhase2Idle");
	Phase1.CreateState("BombAttack");
	Phase1.CreateState("SpiralAttack");
	Phase1.CreateState("SpiralAttackEnd");
	Phase1.CreateState("Phase2ToPhase3");

	Phase1.SetUpdateFunction("DevilPhase2Idle", std::bind(&ADevil2::DevilPhase2Idle, this, std::placeholders::_1));
	Phase1.SetStartFunction("DevilPhase2Idle", [=] {Boss2->ChangeAnimation("DevilPhase2Idle"); });
	
	Phase1.SetUpdateFunction("BombAttack", std::bind(&ADevil2::BombAttack, this, std::placeholders::_1));
	Phase1.SetStartFunction("BombAttack", [=] {Boss2->ChangeAnimation("BombAttack"); });

	Phase1.SetUpdateFunction("SpiralAttack", std::bind(&ADevil2::SpiralAttack, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiralAttack", [=] {Boss2->ChangeAnimation("SpiralAttack"); });

	Phase1.SetUpdateFunction("SpiralAttackEnd", std::bind(&ADevil2::SpiralAttackEnd, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiralAttackEnd", [=] {Boss2->ChangeAnimation("SpiralAttackEnd"); });

	Phase1.SetUpdateFunction("Phase2ToPhase3", std::bind(&ADevil2::Phase2ToPhase3, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase2ToPhase3", [=] {Boss2->ChangeAnimation("Phase2ToPhase3"); });

	Phase1.ChangeState("DevilPhase2Idle");
}

void ADevil2::AniCreate()
{
	Boss2->CreateAnimation("DevilPhase2Idle", "DevilPhase2Idle", 0.075f);
	Boss2->CreateAnimation("BombAttack", "BombAttack", 0.075f);
	Boss2->CreateAnimation("SpiralAttack", "SpiralAttack", 0.075f);
	Boss2->CreateAnimation("SpiralAttackEnd", "SpiralAttackEnd", 0.075f);

	Boss2->CreateAnimation("Phase2ToPhase3", "Phase2ToPhase3", 0.075f);
	Boss2->CreateAnimation("Phase3Idle", "Phase3Idle", 0.075f);
	Boss2->CreateAnimation("DevilSummonImpIdle", "DevilSummonImpIdle", 0.075f);

	Boss2->CreateAnimation("DevilStartCrying", "DevilStartCrying", 0.075f);
	Boss2->CreateAnimation("DevilCrying", "DevilCrying", 0.075f);

	DevilNeck->CreateAnimation("DevilNeck", "DevilNeck", 0.075f);

	Hand->CreateAnimation("FatDemonIntro", "FatDemonIntro", 0.075f);
}

void ADevil2::CreateBombBat()
{
	NewBombBat = GetWorld()->SpawnActor<ABombBat>("BombBat");
}

void ADevil2::CreateAxe()
{
	NewAxe = GetWorld()->SpawnActor<AAxe>("Axe");
}

void ADevil2::CreateImp()
{

	GetWorld()->SpawnActor<AImp>("Imp1")->SetActorLocation(FVector(200.0f, 300.0f, 5.0f));
	GetWorld()->SpawnActor<AImp>("Imp2")->SetActorLocation(FVector(50.0f, 300.0f, 5.0f));
	GetWorld()->SpawnActor<AImp>("Imp3")->SetActorLocation(FVector(-200.0f, 300.0f, 5.0f));
}

void ADevil2::CreateFatDemon()
{
	NewFatDemon = GetWorld()->SpawnActor<AFatDemon>("FatDemon");
	NewFatDemon->SetActorLocation(FVector(Hand->GetWorldPosition().X
		, Hand->GetWorldPosition().Y-400.0f, Hand->GetWorldPosition().Z));
	if (true == LRHand)
	{
		NewFatDemon->GetRender()->SetDir(EEngineDir::Right);
	}
	else
	{
		NewFatDemon->GetRender()->SetDir(EEngineDir::Left);
	}
}

void ADevil2::DevilPhase2Idle(float _DeltaTime)
{
	if (phasecheck == 2 && GetHp() <= 50)
	{
		Phase1.ChangeState("Phase2ToPhase3");
		return;
	}

	if (coolDownTime < 0 && 1 == attOrder)
	{
		Phase1.ChangeState("BombAttack");
		return;
	}

	if (coolDownTime < 0 && 2 == attOrder)
	{
		Phase1.ChangeState("SpiralAttack");
		return;
	}
}

void ADevil2::BombAttack(float _DeltaTime)
{
	Boss2->SetFrameCallback("BombAttack", 56, [=] {CreateBombBat(); });

	if (true == Boss2->IsCurAnimationEnd())
	{
		attOrder = 2;
		coolDownTime = 6.0f;
		Phase1.ChangeState("DevilPhase2Idle");
		return;
	}
}

void ADevil2::SpiralAttack(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		CreateAxe();
		Phase1.ChangeState("SpiralAttackEnd");
		return;
	}
}

void ADevil2::SpiralAttackEnd(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		attOrder = 1;
		coolDownTime = 6.0f;
		Phase1.ChangeState("DevilPhase2Idle");
		return;
	}
}

void ADevil2::Phase2ToPhase3(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		attOrder = 1;
		coolDownTime = 6.0f;
		phasecheck = 3;
		Phase2StateInit();
		return;
	}
}

void ADevil2::Phase2StateInit()
{
	Phase2.CreateState("Phase3Idle");
	Phase2.CreateState("DevilSummonImpIdle");
	Phase2.CreateState("FatDemonIntro");
	Phase2.CreateState("DevilStartCrying");
	Phase2.CreateState("DevilCrying");
	
	Phase2.SetUpdateFunction("Phase3Idle", std::bind(&ADevil2::Phase3Idle, this, std::placeholders::_1));
	Phase2.SetStartFunction("Phase3Idle", [=] {Boss2->ChangeAnimation("Phase3Idle"); });

	Phase2.SetUpdateFunction("DevilSummonImpIdle", std::bind(&ADevil2::DevilSummonImpIdle, this, std::placeholders::_1));
	Phase2.SetStartFunction("DevilSummonImpIdle", [=] {Boss2->ChangeAnimation("DevilSummonImpIdle"); });

	Phase2.SetUpdateFunction("FatDemonIntro", std::bind(&ADevil2::FatDemonIntro, this, std::placeholders::_1));
	Phase2.SetStartFunction("FatDemonIntro", [=] {Hand->ChangeAnimation("FatDemonIntro"); });

	Phase2.SetUpdateFunction("DevilStartCrying", std::bind(&ADevil2::DevilStartCrying, this, std::placeholders::_1));
	Phase2.SetStartFunction("DevilStartCrying", [=] {Boss2->ChangeAnimation("DevilStartCrying"); });

	Phase2.SetUpdateFunction("DevilCrying", std::bind(&ADevil2::DevilCrying, this, std::placeholders::_1));
	Phase2.SetStartFunction("DevilCrying", [=] {Boss2->ChangeAnimation("DevilCrying"); });

	Phase2.ChangeState("Phase3Idle");
}

void ADevil2::Phase3Idle(float _DeltaTime)
{
	if (phasecheck == 3 && GetHp() <= 25)
	{
		Phase2.ChangeState("DevilStartCrying");
		return;
	}

	if (coolDownTime < 0 && 1 == attOrder)
	{
		if (false == LRHand)
		{
			LRHand = true;
			Hand->SetPosition(FVector(-550.0f, -400.0f, 0.0f));
			Hand->SetDir(EEngineDir::Right);
		}
		else {
			LRHand = false;
			Hand->SetPosition(FVector(550.0f, -400.0f, 0.0f));
			Hand->SetDir(EEngineDir::Left);
		}
		Hand->SetActive(true);
		Phase2.ChangeState("FatDemonIntro");
		return;
	}

	if (coolDownTime < 0 && 2 == attOrder)
	{
		Phase2.ChangeState("DevilSummonImpIdle");
		return;
	}
}

void ADevil2::DevilSummonImpIdle(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		CreateImp();
		attOrder = 1;
		coolDownTime = 6.0f;
		Phase2.ChangeState("Phase3Idle");
		return;
	}
}

void ADevil2::FatDemonIntro(float _DeltaTime)
{
	Hand->AddPosition(FVector(FVector::Up * 200.0f * _DeltaTime));

	if (Hand->GetWorldPosition().iY() >= 500)
	{
		CreateFatDemon();
		Hand->SetActive(false);
		coolDownTime = 6.0f;
		Phase2.ChangeState("Phase3Idle");
		return;
	}
}

void ADevil2::DevilStartCrying(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		Phase2.ChangeState("DevilCrying");
		return;
	}
}

void ADevil2::DevilCrying(float _DeltaTime)
{

}
