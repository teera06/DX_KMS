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
}

void AFirefly::Tick(float _DeltaTime)
{
}
