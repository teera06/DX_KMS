#include "PreCompile.h"
#include "Imp.h"

#include <EngineBase\EngineRandom.h>

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

	ImpCollision = CreateDefaultSubObject<UCollision>("ImpCollision");
	ImpCollision->SetupAttachment(Root);
	ImpCollision->SetScale(FVector(70.0f, 70.0f, 100.0f));
	ImpCollision->SetCollisionGroup(ECollisionOrder::imp);
	ImpCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

AImp::~AImp()
{
	spinSound.Off();
}

void AImp::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(200.0f, 200.0f, 5.0f));

	Imp->CreateAnimation("ImpFlyingUp", "ImpFlyingUp", 0.075f);
	Imp->CreateAnimation("ImpFlying", "ImpFlying", 0.075f);
	Imp->CreateAnimation("ImpAttack", "ImpAttack", 0.075f);
	Imp->CreateAnimation("ImpAttackEnd", "ImpAttackEnd", 0.075f);
	Imp->CreateAnimation("Explosion", "Explosion", 0.075f);

	//BombBat->ChangeAnimation("BombBat");
	RandomMove = UEngineRandom::MainRandom.RandomInt(1, 4);
	patternInit();
	UEngineSound::SoundPlay("sfx_devil_imp_spawn_01.wav");

	spinSound = UEngineSound::SoundPlay("devil_bat_bomb_spin_01.wav");
	spinSound.Loop();
	spinSound.Off();
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

	if (MoveNorMalize.iX() ==-1)
	{
		Imp->SetDir(EEngineDir::Left);
	}
	else {
		Imp->SetDir(EEngineDir::Right);
	}
}

void AImp::PlayerCollisionCheck()
{
	ImpCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		if (nullptr != Player)
		{
			Player->AddActorLocation(FVector::Up * 100.0f);
			Player->State.ChangeState("hit");
		}
	});
}

void AImp::patternInit()
{
	pattern.CreateState("Start");
	pattern.CreateState("ImpFlying");
	pattern.CreateState("ImpAttack");
	pattern.CreateState("ImpRandomMove");
	pattern.CreateState("ImpAttackEnd");
	pattern.CreateState("Die");


	pattern.SetUpdateFunction("Start", std::bind(&AImp::Start, this, std::placeholders::_1));
	pattern.SetStartFunction("Start", [=] {Imp->ChangeAnimation("ImpFlyingUp"); });

	pattern.SetUpdateFunction("ImpFlying", std::bind(&AImp::ImpFlying, this, std::placeholders::_1));
	pattern.SetStartFunction("ImpFlying", [=] {Imp->ChangeAnimation("ImpFlying"); });

	pattern.SetUpdateFunction("ImpAttack", std::bind(&AImp::ImpAttack, this, std::placeholders::_1));
	pattern.SetStartFunction("ImpAttack", [=] {Imp->ChangeAnimation("ImpAttack"); });

	pattern.SetUpdateFunction("ImpRandomMove", std::bind(&AImp::ImpRandomMove, this, std::placeholders::_1));
	pattern.SetStartFunction("ImpRandomMove", [=] {Imp->ChangeAnimation("ImpAttack"); });

	pattern.SetUpdateFunction("ImpAttackEnd", std::bind(&AImp::ImpAttackEnd, this, std::placeholders::_1));
	pattern.SetStartFunction("ImpAttackEnd", [=] {Imp->ChangeAnimation("ImpAttackEnd"); });

	pattern.SetUpdateFunction("Die", std::bind(&AImp::RealDie, this, std::placeholders::_1));
	pattern.SetStartFunction("Die", [=] {Imp->ChangeAnimation("Explosion"); });


	pattern.ChangeState("Start");
}

void AImp::Start(float _DeltaTime)
{

	AddActorLocation(FVector::Up * Speed * _DeltaTime);
	if (Delay < 0)
	{
		Delay = 2.5f;
		pattern.ChangeState("ImpFlying");
		return;
	}
}

void AImp::ImpFlying(float _DeltaTime)
{

	CalDir(_DeltaTime);

	if (RandomMove == 1)
	{
		AddActorLocation((FVector::Down + FVector::Right * 0.5f) * Speed * _DeltaTime);
	}
	else if (RandomMove == 2)
	{
		AddActorLocation((FVector::Down + FVector::Right) * Speed * _DeltaTime);
	}
	else if (RandomMove == 3)
	{
		AddActorLocation((FVector::Down + FVector::Left * 0.5f) * Speed * _DeltaTime);
	}
	else if (RandomMove == 4)
	{
		AddActorLocation((FVector::Down + FVector::Left) * Speed * _DeltaTime);
	}


	if (Delay < 0)
	{
		Delay = 3.0f;
		spinSound.On();
		pattern.ChangeState("ImpAttack");
		return;
	}

	if (true == DieCheck)
	{
		spinSound.Off();
		UEngineSound::SoundPlay("sfx_devil_imp_death_01.wav");
		pattern.ChangeState("Die");
		return;
	}
}

void AImp::ImpAttack(float _DeltaTime)
{
	CalDir(_DeltaTime);

	AddActorLocation(MoveNorMalize * Speed * _DeltaTime);
	PlayerCollisionCheck();
	if (Delay < 0)
	{
		spinSound.Off();
		Delay = 1.5f;
		RandomMove = UEngineRandom::MainRandom.RandomInt(1, 4);
		pattern.ChangeState("ImpRandomMove");
		return;
	}

	if (true == DieCheck)
	{
		spinSound.Off();
		pattern.ChangeState("Die");
		return;
	}
}

void AImp::ImpRandomMove(float _DeltaTime)
{
	CalDir(_DeltaTime);

	if (RandomMove == 1)
	{
		AddActorLocation((FVector::Up + FVector::Right * 0.5f) * Speed * _DeltaTime);
	}
	else if (RandomMove == 2)
	{
		AddActorLocation((FVector::Up + FVector::Right) * Speed * _DeltaTime);
	}
	else if (RandomMove == 3)
	{
		AddActorLocation((FVector::Up + FVector::Left * 0.5f) * Speed * _DeltaTime);
	}
	else if (RandomMove == 4)
	{
		AddActorLocation((FVector::Up + FVector::Left) * Speed * _DeltaTime);
	}
	PlayerCollisionCheck();
	if (Delay < 0)
	{
		pattern.ChangeState("ImpAttackEnd");
		return;
	}

	if (true == DieCheck)
	{
		pattern.ChangeState("Die");
		return;
	}
}

void AImp::ImpAttackEnd(float _DeltaTime)
{

	CalDir(_DeltaTime);
	if (true == Imp->IsCurAnimationEnd())
	{
		Delay = 1.5f;
		pattern.ChangeState("Start");
		return;
	}

	if (true == DieCheck)
	{
		pattern.ChangeState("Die");
		return;
	}
}

void AImp::RealDie(float _DeltaTime)
{
	if (true == Imp->IsCurAnimationEnd())
	{
		Destroy();
		return;
	}
}
