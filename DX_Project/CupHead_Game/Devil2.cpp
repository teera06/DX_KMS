#include "PreCompile.h"
#include "Devil2.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "BombBat.h"

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

	SetRoot(Root);

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
	Phase1.Update(_DeltaTime);
}

void ADevil2::Phase1StateInit()
{
	Phase1.CreateState("DevilPhase2Idle");
	Phase1.CreateState("BombAttack");
	Phase1.CreateState("SpiralAttack");
	Phase1.CreateState("SpiralAttackEnd");

	Phase1.SetUpdateFunction("DevilPhase2Idle", std::bind(&ADevil2::DevilPhase2Idle, this, std::placeholders::_1));
	Phase1.SetStartFunction("DevilPhase2Idle", [=] {Boss2->ChangeAnimation("DevilPhase2Idle"); });
	
	Phase1.SetUpdateFunction("BombAttack", std::bind(&ADevil2::BombAttack, this, std::placeholders::_1));
	Phase1.SetStartFunction("BombAttack", [=] {Boss2->ChangeAnimation("BombAttack"); });

	Phase1.SetUpdateFunction("SpiralAttack", std::bind(&ADevil2::SpiralAttack, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiralAttack", [=] {Boss2->ChangeAnimation("SpiralAttack"); });

	Phase1.SetUpdateFunction("SpiralAttackEnd", std::bind(&ADevil2::SpiralAttackEnd, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiralAttackEnd", [=] {Boss2->ChangeAnimation("SpiralAttackEnd"); });

	Phase1.ChangeState("DevilPhase2Idle");
}

void ADevil2::AniCreate()
{
	Boss2->CreateAnimation("DevilPhase2Idle", "DevilPhase2Idle", 0.075f);
	Boss2->CreateAnimation("BombAttack", "BombAttack", 0.075f);
	Boss2->CreateAnimation("SpiralAttack", "SpiralAttack", 0.075f);
	Boss2->CreateAnimation("SpiralAttackEnd", "SpiralAttackEnd", 0.075f);

	DevilNeck->CreateAnimation("DevilNeck", "DevilNeck", 0.075f);
}

void ADevil2::CreateBombBat()
{
	NewBombBat = GetWorld()->SpawnActor<ABombBat>("BombBat");
}

void ADevil2::DevilPhase2Idle(float _DeltaTime)
{
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
