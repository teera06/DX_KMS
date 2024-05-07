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
#include "DevilTear.h"
#include "ScreenEffect.h"



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

	Summon1 = CreateDefaultSubObject<USpriteRenderer>("Summon1");
	
	Summon1->SetupAttachment(Root);

	Summon1->SetOrder(ERenderOrder::FrontSkillMonster);
	Summon1->SetSprite("_0011_devil_ph3_small_demon_pimple_0001.png");
	Summon1->SetSamplering(ETextureSampling::LINEAR);
	Summon1->SetAutoSize(1.0f, true);
	Summon1->AddPosition(FVector(-150.0f, 150.0f, 0.0f));

	Summon2 = CreateDefaultSubObject<USpriteRenderer>("Summon2");
	
	Summon2->SetupAttachment(Root);

	Summon2->SetOrder(ERenderOrder::FrontSkillMonster);
	Summon2->SetSprite("_0011_devil_ph3_small_demon_pimple_0001.png");
	Summon2->SetSamplering(ETextureSampling::LINEAR);
	Summon2->SetAutoSize(1.0f, true);
	Summon2->AddPosition(FVector(150.0f, 140.0f, 0.0f));

	Summon3 = CreateDefaultSubObject<USpriteRenderer>("Summon3");
	Summon3->SetupAttachment(Root);
	
	Summon3->SetOrder(ERenderOrder::FrontSkillMonster);
	Summon3->SetSprite("_0011_devil_ph3_small_demon_pimple_0001.png");
	Summon3->SetSamplering(ETextureSampling::LINEAR);
	Summon3->SetAutoSize(1.0f, true);
	Summon3->AddPosition(FVector(180.0f, 160.0f, 0.0f));


	SetRoot(Root);

	Hand->SetActive(false);
	Summon1->SetActive(false);
	Summon2->SetActive(false);
	Summon3->SetActive(false);
	DevilNeck->AddPosition(FVector(40.0f, -400.0f, 0.0f));
}

ADevil2::~ADevil2()
{
	CrySound.Off();
}

void ADevil2::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 90.0f, 10.0f));

	AniCreate();
	DevilNeck->ChangeAnimation("DevilNeck");
	Phase1StateInit();

	

	CrySound = UEngineSound::SoundPlay("sfx_level_devil_head_devil_cry_idle_001.wav");
	CrySound.Loop();
	CrySound.Off();
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
	Boss2->CreateAnimation("DevilKnockout", "DevilKnockout", 0.075f);

	DevilNeck->CreateAnimation("DevilNeck", "DevilNeck", 0.085f);

	Hand->CreateAnimation("FatDemonIntro", "FatDemonIntro", 0.075f);
	Hand->CreateAnimation("FatDemonRelease", "FatDemonRelease", 0.065f,false);

	Summon1->CreateAnimation("SpawnImp", "SpawnImp", 0.045f);
	Summon2->CreateAnimation("SpawnImp", "SpawnImp", 0.045f);
	Summon3->CreateAnimation("SpawnImp", "SpawnImp", 0.045f);

	Summon1->ChangeAnimation("SpawnImp");
	Summon2->ChangeAnimation("SpawnImp");
	Summon3->ChangeAnimation("SpawnImp");
}

void ADevil2::CreateBombBat()
{
	NewBombBat = GetWorld()->SpawnActor<ABombBat>("BombBat");
}

void ADevil2::CreateAxe()
{
	//UEngineSound::SoundPlay("sfx_level_devil_sitting_devil_trident_attack_01.wav");
	NewAxe = GetWorld()->SpawnActor<AAxe>("Axe");
}

void ADevil2::CreateImp(const FVector& _Pos)
{

	GetWorld()->SpawnActor<AImp>("Imp")->SetActorLocation(_Pos);
	
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
	Phase2.CreateState("DevilKnockout");
	
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

	Phase2.SetUpdateFunction("DevilKnockout", std::bind(&ADevil2::DevilKnockout, this, std::placeholders::_1));
	Phase2.SetStartFunction("DevilKnockout", [=] {Boss2->ChangeAnimation("DevilKnockout"); });

	Phase2.ChangeState("Phase3Idle");
}

void ADevil2::Phase3Idle(float _DeltaTime)
{
	if (phasecheck == 3 && GetHp() <= 25)
	{
		coolDownTime = 1.0f;
		Phase2.ChangeState("DevilStartCrying");
		return;
	}

	if (coolDownTime < 0 && 2 == attOrder)
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

	if (coolDownTime < 0 && 1 == attOrder)
	{
		Phase2.ChangeState("DevilSummonImpIdle");
		return;
	}
}

void ADevil2::DevilSummonImpIdle(float _DeltaTime)
{
	
	Summon1->SetActive(true);
	Summon2->SetActive(true);
	Summon3->SetActive(true);

	Summon1->ChangeAnimation("SpawnImp");
	Summon2->ChangeAnimation("SpawnImp");
	Summon3->ChangeAnimation("SpawnImp");

	Summon1->SetFrameCallback("SpawnImp", 9, [=] {CreateImp(Summon1->GetWorldPosition());});
	Summon2->SetFrameCallback("SpawnImp", 9, [=] {CreateImp(Summon2->GetWorldPosition()); });
	Summon3->SetFrameCallback("SpawnImp", 9, [=] {CreateImp(Summon3->GetWorldPosition()); });

	if (true == Boss2->IsCurAnimationEnd())
	{
		Summon1->SetActive(false);
		Summon2->SetActive(false);
		Summon3->SetActive(false);
	
		attOrder = 2;
		coolDownTime = 6.0f;
		Phase2.ChangeState("Phase3Idle");
		return;
	}
}

void ADevil2::FatDemonIntro(float _DeltaTime)
{
	Hand->AddPosition(FVector(FVector::Up * 200.0f * _DeltaTime));

	if (Hand->GetWorldPosition().iY() == 250)
	{
		Hand->ChangeAnimation("FatDemonRelease");
	}

	if (Hand->GetWorldPosition().iY() == 300)
	{
		CreateFatDemon();
	
	}

	if (Hand->GetWorldPosition().iY() >= 450)
	{
		Hand->SetActive(false);
		coolDownTime = 6.0f;
		attOrder = 1;
		Phase2.ChangeState("Phase3Idle");
		return;
	}
}

void ADevil2::DevilStartCrying(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		CrySound.On();
		Phase2.ChangeState("DevilCrying");
		return;
	}
}

void ADevil2::DevilCrying(float _DeltaTime)
{
	if (coolDownTime < 0)
	{
		if (false == LRTear)
		{
			LRTear = true;
			GetWorld()->SpawnActor<ADevilTear>("Tear")->AddActorLocation(FVector(- 200.0f, 165.0f, 5.0f));
		}
		else
		{
			LRTear = false;
			GetWorld()->SpawnActor<ADevilTear>("Tear")->AddActorLocation(FVector(200.0f, 165.0f, 5.0f));
		}

		coolDownTime = 1.0f;
	}

	if (GetHp() <= 0)
	{
		CrySound.Off();
		GetWorld()->SpawnActor<AScreenEffect>("Knockout")->SetScreenEffect(EScreenEffect::Knockout);
		Phase2.ChangeState("DevilKnockout");
		return;
	}
}

void ADevil2::DevilKnockout(float _DeltaTime)
{
	ClearLevelChange -= _DeltaTime;

	if (ClearLevelChange < 0)
	{
		GetWorld()->SpawnActor<AScreenEffect>("IrisReBoss1Clear")->SetScreenEffect(EScreenEffect::IrisReBoss1Clear);
	}
}
