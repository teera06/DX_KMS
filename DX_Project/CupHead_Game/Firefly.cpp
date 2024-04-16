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
}

void AFirefly::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AFirefly::patternStateInit()
{
	pattern.CreateState("smallintro");
	

	//pattern.SetUpdateFunction("smallintro", std::bind(&AFirefly::Intro, this, std::placeholders::_1));
	//pattern.SetStartFunction("smallintro", [=] {SmallBoss1->ChangeAnimation("smallintro"); });
}

void AFirefly::Intro()
{
}
