#include "PreCompile.h"
#include "Firefly.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
AFirefly::AFirefly()
{
}

AFirefly::~AFirefly()
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
}

void AFirefly::BeginPlay()
{
	Super::BeginPlay();

	FireflyRender->SetOrder(ERenderOrder::Monster2);
	FireflyRender->SetSprite("tallfrog_firefly_left_0001.png");
	FireflyRender->SetSamplering(ETextureSampling::LINEAR);
	FireflyRender->SetAutoSize(1.0f, true);
	
	FireflyRender->SetDir(EEngineDir::Left);

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

void AFirefly::patternStateInit()
{
	pattern.CreateState("Intro");
	pattern.CreateState("bigSkillIdle");
	pattern.CreateState("bigskillLRMove");

	

	pattern.SetUpdateFunction("smallattready", std::bind(&AFirefly::Intro, this, std::placeholders::_1));
	pattern.SetStartFunction("smallintro", [=] {FireflyRender->ChangeAnimation("bigskillLRMove"); });

	pattern.SetUpdateFunction("bigSkillIdle", std::bind(&AFirefly::bigSkillIdle, this, std::placeholders::_1));
	pattern.SetStartFunction("bigSkillIdle", [=] {FireflyRender->ChangeAnimation("bigSkillIdle"); });

	pattern.SetUpdateFunction("bigskillLRMove", std::bind(&AFirefly::bigskillLRMove, this, std::placeholders::_1));
	pattern.SetStartFunction("bigskillLRMove", [=] {FireflyRender->ChangeAnimation("bigskillLRMove"); });

	pattern.ChangeState("Intro");
}

void AFirefly::Intro(float _DeltaTime)
{

}

void AFirefly::bigSkillIdle(float _DeltaTime)
{
}

void AFirefly::bigskillLRMove(float _DeltaTime)
{
}
