#include "PreCompile.h"
#include "Boss2Start.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

ABoss2Start::ABoss2Start()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("start1Render");
	startRender = CreateDefaultSubObject<USpriteRenderer>("start1Render");

	startRender->SetupAttachment(Root);

	startRender->SetOrder(ERenderOrder::ObjectFront2);
	startRender->SetSprite("DevilZone.png");
	startRender->SetSamplering(ETextureSampling::LINEAR);
	startRender->SetAutoSize(1.0f, true);

	WallCollision = CreateDefaultSubObject<UCollision>("WallCollision");
	WallCollision->SetupAttachment(Root);

	WallCollision->SetScale(FVector(150.0f, 150.0f, 100.0f));

	WallCollision->SetCollisionGroup(ECollisionOrder::WorldWall);
	WallCollision->SetCollisionType(ECollisionType::RotRect);


	startCollision = CreateDefaultSubObject<UCollision>("startCollision1");
	startCollision->SetupAttachment(Root);

	startCollision->SetScale(FVector(200.0f, 200.0f, 100.0f));

	startCollision->SetCollisionGroup(ECollisionOrder::WorldObject2);
	startCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

ABoss2Start::~ABoss2Start()
{
}

void ABoss2Start::BeginPlay()
{
	Super::BeginPlay();
	startRender->SetDir(EEngineDir::Left);
	SetActorRotation(FVector(0.0f, 0.0f, 10.0f));
	SetActorLocation({ 2200.0f, -1085.0f, 100.0f });
	AniCreate();

	startRender->ChangeAnimation("DevilZone");
}

void ABoss2Start::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ABoss2Start::AniCreate()
{
	startRender->CreateAnimation("DevilZone", "DevilZone.png", 0.075f, 0, 2, true);
}
