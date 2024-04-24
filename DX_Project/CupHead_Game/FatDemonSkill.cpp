#include "PreCompile.h"
#include "FatDemonSkill.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"


AFatDemonSkill::AFatDemonSkill()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Skill");
	Skill = CreateDefaultSubObject<USpriteRenderer>("Skill");
	Skill->SetupAttachment(Root);

	Skill->SetOrder(ERenderOrder::backSkill);
	Skill->SetSprite("devil_ph3_fat_demon_skull_0005.png");
	Skill->SetSamplering(ETextureSampling::LINEAR);
	Skill->SetAutoSize(0.85f, true);
	Skill->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

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
	
	Skill->ChangeAnimation("FatDemonSkull");
}

void AFatDemonSkill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == DirOneChek)
	{
		if (GetActorLocation().iX() > 0)
		{
			Move = FVector::Left;
		}
		else {
			Move = FVector::Right;
		}
		DirOneChek = true;
	}

	AddActorLocation(Move * 200.0f * _DeltaTime);

	if (GetActorLocation().iX() >= 720 || GetActorLocation().iX()<=-720)
	{
		Destroy();
	}
	
}
