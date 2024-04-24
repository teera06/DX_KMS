
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

	SetRoot(Root);
}

AFatDemon::~AFatDemon()
{
}

void AFatDemon::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(-400.0f, 200.0f, 5.0f));

	FatDemon->CreateAnimation("FatDemonIdle", "FatDemonIdle", 0.075f);
	FatDemon->CreateAnimation("FatDemonAttack", "FatDemonAttack", 0.075f);
	

	//BombBat->ChangeAnimation("BombBat");

	patternInit();
}

void AFatDemon::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Delay -= _DeltaTime;

	pattern.Update(_DeltaTime);
}

void AFatDemon::CreateSkill()
{
	GetWorld()->SpawnActor<AFatDemonSkill>("FatDemonSkill")->SetActorLocation(GetActorLocation());
}

void AFatDemon::patternInit()
{
	pattern.CreateState("FatDemonIdle");
	pattern.CreateState("FatDemonAttack");
	//pattern.CreateState("ImpAttack");
	//pattern.CreateState("ImpAttackEnd");


	pattern.SetUpdateFunction("FatDemonIdle", std::bind(&AFatDemon::FatDemonIdle, this, std::placeholders::_1));
	pattern.SetStartFunction("FatDemonIdle", [=] {FatDemon->ChangeAnimation("FatDemonIdle"); });

	pattern.SetUpdateFunction("FatDemonAttack", std::bind(&AFatDemon::FatDemonAttack, this, std::placeholders::_1));
	pattern.SetStartFunction("FatDemonAttack", [=] {FatDemon->ChangeAnimation("FatDemonAttack"); });

	pattern.ChangeState("FatDemonIdle");
}

void AFatDemon::FatDemonIdle(float _DeltaTime)
{
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
	if (true == FatDemon->IsCurAnimationEnd())
	{
		Delay = 3.0f;
		CreateSkill();
		pattern.ChangeState("FatDemonIdle");
		return;
	}

}
