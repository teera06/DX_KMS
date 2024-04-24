#include "PreCompile.h"
#include "DevilPlatform.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"


ADevilPlatform::ADevilPlatform()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("DevilPlatform");
	DevilPlatform = CreateDefaultSubObject<USpriteRenderer>("DevilPlatform");

	DevilPlatform->SetupAttachment(Root);

	DevilPlatform->SetOrder(ERenderOrder::MidObject);
	DevilPlatform->SetSprite("devil_platforms_rocks_004.png");
	DevilPlatform->SetSamplering(ETextureSampling::LINEAR);
	DevilPlatform->SetAutoSize(0.85f, true);

	GroundCollision = CreateDefaultSubObject<UCollision>("GroundCollision");
	GroundCollision->SetupAttachment(Root);

	GroundCollision->SetScale(FVector(150.0f, 80.0f, 100.0f));

	GroundCollision->SetCollisionGroup(ECollisionOrder::Boss2Object1);
	GroundCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

ADevilPlatform::~ADevilPlatform()
{
}

void ADevilPlatform::BeginPlay()
{
	Super::BeginPlay();

	DevilPlatform->CreateAnimation("DevilPlatform1", "DevilPlatform1", 0.075f);
	DevilPlatform->CreateAnimation("DevilPlatform2", "DevilPlatform2", 0.075f);
	DevilPlatform->CreateAnimation("DevilPlatform3", "DevilPlatform3", 0.075f);
	DevilPlatform->CreateAnimation("DevilPlatform4", "DevilPlatform4", 0.075f);

	DevilPlatform->ChangeAnimation("DevilPlatform1");
}

void ADevilPlatform::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
