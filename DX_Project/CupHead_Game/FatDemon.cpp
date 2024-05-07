
#include "PreCompile.h"
#include "FatDemon.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "FatDemonSkill.h"


AFatDemon::AFatDemon()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("FatDemon");
	FatDemon = CreateDefaultSubObject<USpriteRenderer>("FatDemon");
	FatDemon->SetupAttachment(Root);

	FatDemon->SetOrder(ERenderOrder::FrontSkillMonster);
	FatDemon->SetSprite("devil_ph3_fat_demon_flying_idle_0001.png");
	FatDemon->SetSamplering(ETextureSampling::LINEAR);
	FatDemon->SetAutoSize(0.85f, true);
	FatDemon->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	MonsterCollision = CreateDefaultSubObject<UCollision>("MonsterCollision3");
	MonsterCollision->SetupAttachment(Root);
	MonsterCollision->SetScale(FVector(70.0f, 70.0f, 100.0f));
	MonsterCollision->SetCollisionGroup(ECollisionOrder::FatDemon);
	MonsterCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

AFatDemon::~AFatDemon()
{
}

void AFatDemon::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(-400.0f, 200.0f, 5.0f));

	FatDemon->CreateAnimation("FatDemonTransition", "FatDemonTransition", 0.075f);
	FatDemon->CreateAnimation("FatDemonIdle", "FatDemonIdle", 0.075f);
	FatDemon->CreateAnimation("FatDemonAttack", "FatDemonAttack", 0.075f);
	FatDemon->CreateAnimation("FatDemonDeath", "FatDemonDeath", 0.075f);
	FatDemon->CreateAnimation("FatDemonDeathIdle", "FatDemonDeathIdle", 0.075f);
	

	//BombBat->ChangeAnimation("BombBat");

	patternInit();
	UEngineSound::SoundPlay("fat_bat_spawn_01.wav");
}

void AFatDemon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Delay -= _DeltaTime;

	pattern.Update(_DeltaTime);
}

void AFatDemon::CreateSkill()
{
	if (GetActorLocation().X < 0)
	{
		GetWorld()->SpawnActor<AFatDemonSkill>("FatDemonSkill")->SetActorLocation(GetActorLocation() + FVector::Right * 200.0f);
	}
	else
	{
		GetWorld()->SpawnActor<AFatDemonSkill>("FatDemonSkill")->SetActorLocation(GetActorLocation()+FVector::Left*200.0f);
	}
}

void AFatDemon::patternInit()
{
	pattern.CreateState("FatDemonIntro");
	pattern.CreateState("FatDemonIdle");
	pattern.CreateState("FatDemonAttack");
	pattern.CreateState("FatDemonDeath");
	pattern.CreateState("FatDemonDeathIdle");

	//pattern.CreateState("ImpAttack");
	//pattern.CreateState("ImpAttackEnd");

	pattern.SetUpdateFunction("FatDemonIntro", std::bind(&AFatDemon::FatDemonIntro, this, std::placeholders::_1));
	pattern.SetStartFunction("FatDemonIntro", [=] {FatDemon->ChangeAnimation("FatDemonTransition"); });

	pattern.SetUpdateFunction("FatDemonIdle", std::bind(&AFatDemon::FatDemonIdle, this, std::placeholders::_1));
	pattern.SetStartFunction("FatDemonIdle", [=] {FatDemon->ChangeAnimation("FatDemonIdle"); });

	pattern.SetUpdateFunction("FatDemonAttack", std::bind(&AFatDemon::FatDemonAttack, this, std::placeholders::_1));
	pattern.SetStartFunction("FatDemonAttack", [=] {FatDemon->ChangeAnimation("FatDemonAttack"); });

	pattern.SetUpdateFunction("FatDemonDeath", std::bind(&AFatDemon::FatDemonDeath, this, std::placeholders::_1));
	pattern.SetStartFunction("FatDemonDeath", [=] {FatDemon->ChangeAnimation("FatDemonDeath"); });

	pattern.SetUpdateFunction("FatDemonDeathIdle", std::bind(&AFatDemon::FatDemonDeathIdle, this, std::placeholders::_1));
	pattern.SetStartFunction("FatDemonDeathIdle", [=] {FatDemon->ChangeAnimation("FatDemonDeathIdle"); });

	pattern.ChangeState("FatDemonIntro");
}

void AFatDemon::FatDemonIntro(float _DeltaTime)
{
	if (true == FatDemon->IsCurAnimationEnd())
	{
		pattern.ChangeState("FatDemonIdle");
		return;
	}
}


void AFatDemon::FatDemonIdle(float _DeltaTime)
{
	if (Hp <= 0)
	{
		UEngineSound::SoundPlay("fat_bat_die_01.wav");
		pattern.ChangeState("FatDemonDeath");
		return;
	}


	if (Delay < 0)
	{
		pattern.ChangeState("FatDemonAttack");
		return;
	}

	if (GetActorLocation().iY() >= 280 || GetActorLocation().iY() <= -280)
	{
		MoveVector *= -1.0f;
	}

	AddActorLocation(MoveVector * Speed * _DeltaTime);
}

void AFatDemon::FatDemonAttack(float _DeltaTime)
{
	if (Hp <= 0)
	{
		pattern.ChangeState("FatDemonDeath");
		return;
	
	}

	FatDemon ->SetFrameCallback("FatDemonAttack", 2, [=] {CreateSkill(); });

	if (true == FatDemon->IsCurAnimationEnd())
	{
		Delay = 3.0f;
		pattern.ChangeState("FatDemonIdle");
		return;
	}

}

void AFatDemon::FatDemonDeath(float _DeltaTime)
{
	if (true == FatDemon->IsCurAnimationEnd())
	{
		pattern.ChangeState("FatDemonDeathIdle");
		return;
	}
}


void AFatDemon::FatDemonDeathIdle(float _DeltaTime)
{
	if ( GetActorLocation().iY() <= -400)
	{
		Destroy();
	}

	AddActorLocation(FVector::Down * Speed * _DeltaTime);
}
