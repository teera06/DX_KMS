#include "PreCompile.h"
#include "smallskill.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

Asmallskill::Asmallskill()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("smallskill");

	smallskillRender = CreateDefaultSubObject<USpriteRenderer>("smallskillRender");

	smallskillRender->SetupAttachment(Root);

	smallskillCollision = CreateDefaultSubObject<UCollision>("smallskillCollision");
	smallskillCollision->SetupAttachment(Root);
	smallskillCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));

	smallskillCollision->SetCollisionGroup(ECollisionOrder::MonsterSkill);
	smallskillCollision->SetCollisionType(ECollisionType::CirCle);


	SetRoot(Root);
}

Asmallskill::~Asmallskill()
{
}

void Asmallskill::BeginPlay()
{
	Super::BeginPlay();

	smallskillRender->SetOrder(ERenderOrder::Cuphead);
	smallskillRender->SetSprite("shortfrog_fist_0001.png");
	smallskillRender->SetSamplering(ETextureSampling::LINEAR);
	smallskillRender->SetAutoSize(1.0f, true);
	
	smallskillRender->SetDir(EEngineDir::Left);

	smallskillRender->CreateAnimation("smallskill", "smallskill", 0.1f);
	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	smallskillRender->ChangeAnimation("smallskill");
}

void Asmallskill::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (SmallSkillDir.iX() != 0)
	{
		Move = SmallSkillDir * Speed * _DeltaTime;

		

	
		AddActorLocation(Move);

		Collisiongather();
	}
}


void Asmallskill::Collisiongather()
{
	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}

