#include "PreCompile.h"
#include "DevilPlatform.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"


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
	GroundCollision->AddPosition(FVector(0.0f, 35.0f, 0.0f));
	GroundCollision->SetScale(FVector(160.0f, 10.0f, 100.0f));

	GroundCollision->SetCollisionGroup(ECollisionOrder::Boss2Object1);
	GroundCollision->SetCollisionType(ECollisionType::RotRect);

	LRCollision = CreateDefaultSubObject<UCollision>("LRCollision2");
	LRCollision->SetupAttachment(Root);
	LRCollision->AddPosition(FVector(0.0f, -20.0f, 0.0f));
	LRCollision->SetScale(FVector(180.0f, 90.0f, 100.0f));

	LRCollision->SetCollisionGroup(ECollisionOrder::Boss1LR);
	LRCollision->SetCollisionType(ECollisionType::RotRect);

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
	PlayerCollision();
}

void ADevilPlatform::PlayerCollision()
{
	LRCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);
		Player->AddActorLocation(FVector::Up * 100.0f);
		Player->State.ChangeState("hit");
	});
}
