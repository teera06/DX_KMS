#include "PreCompile.h"
#include "Imp.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

AImp::AImp()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Imp");
	Imp = CreateDefaultSubObject<USpriteRenderer>("Imp");
	Imp->SetupAttachment(Root);

	Imp->SetOrder(ERenderOrder::FrontSkillMonster);
	Imp->SetSprite("devil_ph3_small_demon_fly_up_0001.png");
	Imp->SetSamplering(ETextureSampling::LINEAR);
	Imp->SetAutoSize(1.0f, true);

	SetRoot(Root);
}

AImp::~AImp()
{
}

void AImp::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(200.0f, 200.0f, 5.0f));

	Imp->CreateAnimation("ImpFlyingUp", "ImpFlyingUp", 0.075f);
	Imp->CreateAnimation("ImpFlying", "ImpFlying", 0.075f);
	Imp->CreateAnimation("ImpAttack", "ImpAttack", 0.075f);
	Imp->CreateAnimation("ImpAttackEnd", "ImpAttackEnd", 0.075f);

	//BombBat->ChangeAnimation("BombBat");

	patternInit();
}

void AImp::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Delay -= _DeltaTime;

	pattern.Update(_DeltaTime);
}

void AImp::CalDir(float _DeltaTime)
{
	FVector AxeDir = GetActorLocation();
	FVector PlayerPos = APlay_Cuphead::GetPlayerPos();

	FVector Move = PlayerPos - AxeDir;

	MoveNorMalize = Move.Normalize3DReturn();

	if (MoveNorMalize.iX() <= 0)
	{
		Imp->SetDir(EEngineDir::Right);
	}
	else {
		Imp->SetDir(EEngineDir::Left);
	}
}

void AImp::patternInit()
{
	pattern.CreateState("Start");
	pattern.CreateState("ImpFlying");
	pattern.CreateState("ImpAttack");
	pattern.CreateState("ImpAttackEnd");


	pattern.SetUpdateFunction("Start", std::bind(&AImp::Start, this, std::placeholders::_1));
	pattern.SetStartFunction("Start", [=] {Imp->ChangeAnimation("ImpFlyingUp"); });

	pattern.SetUpdateFunction("ImpFlying", std::bind(&AImp::ImpFlying, this, std::placeholders::_1));
	pattern.SetStartFunction("ImpFlying", [=] {Imp->ChangeAnimation("ImpFlying"); });

	pattern.SetUpdateFunction("ImpAttack", std::bind(&AImp::ImpAttack, this, std::placeholders::_1));
	pattern.SetStartFunction("ImpAttack", [=] {Imp->ChangeAnimation("ImpAttack"); });

	pattern.SetUpdateFunction("ImpAttackEnd", std::bind(&AImp::ImpAttackEnd, this, std::placeholders::_1));
	pattern.SetStartFunction("ImpAttackEnd", [=] {Imp->ChangeAnimation("ImpAttackEnd"); });


	pattern.ChangeState("Start");
}

void AImp::Start(float _DeltaTime)
{

	AddActorLocation(FVector::Up * Speed * _DeltaTime);
	if (Delay < 0)
	{
		Delay = 1.5;
		pattern.ChangeState("ImpFlying");
		return;
	}
}

void AImp::ImpFlying(float _DeltaTime)
{
	if (GetActorLocation().iX() >= 0)
	{
		AddActorLocation((FVector::Down+FVector::Left) * Speed * _DeltaTime);
	}
	else {
		AddActorLocation((FVector::Down + FVector::Right) * Speed * _DeltaTime);
	}

	if (Delay < 0)
	{
		Delay = 3.0;
		pattern.ChangeState("ImpAttack");
		return;
	}
}

void AImp::ImpAttack(float _DeltaTime)
{
	CalDir(_DeltaTime);

	AddActorLocation(MoveNorMalize * Speed * _DeltaTime);

	if (Delay < 0)
	{
		//Delay = 3.0;
		pattern.ChangeState("ImpAttackEnd");
		return;
	}
}

void AImp::ImpAttackEnd(float _DeltaTime)
{
	if (true == Imp->IsCurAnimationEnd())
	{
		Delay = 1.5;
		pattern.ChangeState("Start");
		return;
	}
}
