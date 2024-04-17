#include "PreCompile.h"
#include "Firefly.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"
AFirefly::AFirefly()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Firefly");

	FireflyRender = CreateDefaultSubObject<USpriteRenderer>("FireflyRender");

	FireflyRender->SetupAttachment(Root);

	FireflyCollision = CreateDefaultSubObject<UCollision>("FireflyCollision");
	FireflyCollision->SetupAttachment(Root);
	FireflyCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));

	FireflyCollision->SetCollisionGroup(ECollisionOrder::MonsterSkill);
	FireflyCollision->SetCollisionType(ECollisionType::CirCle);


	SetRoot(Root);

	FireflyRender->SetOrder(ERenderOrder::skilleffect);
	FireflyRender->SetSprite("tallfrog_firefly_left_0001.png");
	FireflyRender->SetSamplering(ETextureSampling::LINEAR);
	FireflyRender->SetAutoSize(1.0f, true);
}

AFirefly::~AFirefly()
{

}

void AFirefly::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation({ GetActorLocation().X - 10.0f,270.0f,0.0f });
	FireflyRender->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	FireflyRender->CreateAnimation("bigskillLRMove", "bigskillLRMove", 0.1f);
	FireflyRender->CreateAnimation("bigSkillIdle", "bigSkillIdle", 0.1f);
	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	patternStateInit();

}

void AFirefly::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	

	pattern.Update(_DeltaTime);
	
}

void AFirefly::CalDir(float _DeltaTime)
{
	FVector PlayerPos = APlay_Cuphead::GetPlayerPos();
	FVector MonsterPos = GetActorLocation();

	FVector Move = PlayerPos- MonsterPos;


	AddActorLocation(Move.Normalize3DReturn() * Speed * _DeltaTime);
}

void AFirefly::patternStateInit()
{
	pattern.CreateState("Intro");
	pattern.CreateState("bigSkillIdle");
	pattern.CreateState("bigskillLRMove");

	

	pattern.SetUpdateFunction("Intro", std::bind(&AFirefly::Intro, this, std::placeholders::_1));
	pattern.SetStartFunction("Intro", [=] {FireflyRender->ChangeAnimation("bigskillLRMove"); });

	pattern.SetUpdateFunction("bigSkillIdle", std::bind(&AFirefly::bigSkillIdle, this, std::placeholders::_1));
	pattern.SetStartFunction("bigSkillIdle", [=] {FireflyRender->ChangeAnimation("bigSkillIdle"); });

	pattern.SetUpdateFunction("bigskillLRMove", std::bind(&AFirefly::bigskillLRMove, this, std::placeholders::_1));
	pattern.SetStartFunction("bigskillLRMove", [=] {FireflyRender->ChangeAnimation("bigskillLRMove"); });

	pattern.ChangeState("Intro");
}

void AFirefly::Intro(float _DeltaTime)
{
	Delay -= _DeltaTime;
	AddActorLocation(FVector::Left * Speed * _DeltaTime);

	if (Delay < 0.0f)
	{
		Delay = 2.0f;
		//MoveCoolDonwTime = 2.0f;
		pattern.ChangeState("bigSkillIdle");
		return;
	}
}

void AFirefly::bigSkillIdle(float _DeltaTime)
{
	Delay -= _DeltaTime;
	if (Delay < 0.0f)
	{
		Delay = 0.3f;
		//MoveCoolDonwTime = 2.0f;
		pattern.ChangeState("bigskillLRMove");
		return;
	}
}

void AFirefly::bigskillLRMove(float _DeltaTime)
{
	CalDir(_DeltaTime);
	Delay -= _DeltaTime;
	if (Delay < 0.0f)
	{
		Delay = 2.0f;
		//MoveCoolDonwTime = 2.0f;
		pattern.ChangeState("bigSkillIdle");
		return;
	}
}
