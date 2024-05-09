#include "PreCompile.h"
#include "FatDemonSkill.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h";

AFatDemonSkill::AFatDemonSkill()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Skill");
	Skill = CreateDefaultSubObject<USpriteRenderer>("Skill");
	Skill->SetupAttachment(Root);

	Skill->SetOrder(ERenderOrder::SkillMonsterSkill);
	Skill->SetSprite("devil_ph3_fat_demon_skull_0005.png");
	Skill->SetSamplering(ETextureSampling::LINEAR);
	Skill->SetAutoSize(0.85f, true);
	Skill->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));


	FatSkill = CreateDefaultSubObject<UCollision>("FatSkill");
	FatSkill->SetupAttachment(Root);
	FatSkill->SetScale(FVector(70.0f, 70.0f, 100.0f));
	FatSkill->SetCollisionGroup(ECollisionOrder::FatSkill);
	FatSkill->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

AFatDemonSkill::~AFatDemonSkill()
{
}

void AFatDemonSkill::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(-400.0f, 200.0f, 5.0f));

	Skill->CreateAnimation("FatDemonSkull", "FatDemonSkull", 0.075f);
	Skill->CreateAnimation("FatDemonSkullParry", "FatDemonSkullParry", 0.075f);
	
	//Skill->ChangeAnimation("FatDemonSkull");
}

void AFatDemonSkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == DirOneChek)
	{
		if (false == ParryCheck)
		{
			Skill->ChangeAnimation("FatDemonSkull");
		}
		else
		{
			Skill->ChangeAnimation("FatDemonSkullParry");
		}


		if (GetActorLocation().iX() > 0)
		{
			Move = FVector::Left;
		}
		else {
			Move = FVector::Right;
		}
		DirOneChek = true;
	}

	AddActorLocation(Move * Speed * _DeltaTime);
	PlayerCollisionCheck();
	if (GetActorLocation().iX() >= 720 || GetActorLocation().iX()<=-720)
	{
		Destroy();
	}
	
}

void AFatDemonSkill::PlayerCollisionCheck()
{
	FatSkill->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
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
