#include "PreCompile.h"
#include "Boss1Start.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

ABoss1Start::ABoss1Start()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("start1Render");
	startRender = CreateDefaultSubObject<USpriteRenderer>("start1Render");
	
	startRender->SetupAttachment(Root);
	
	startRender->SetOrder(ERenderOrder::ObjectFront2);
	startRender->SetSprite("Boss1Zone.png");
	startRender->SetSamplering(ETextureSampling::LINEAR);
	startRender->SetAutoSize(1.0f, true);

	

	startCollision = CreateDefaultSubObject<UCollision>("startCollision1");
	startCollision->SetupAttachment(Root);

	startCollision->SetScale(FVector(400.0f, 250.0f, 100.0f));
	
	startCollision->SetCollisionGroup(ECollisionOrder::WorldObject1);
	startCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

ABoss1Start::~ABoss1Start()
{
}

void ABoss1Start::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FVector(0.0f, 0.0f, 7.0f));
	SetActorLocation({ 2300.0f, -1912.0f, 100.0f });
	AniCreate();

	startRender->ChangeAnimation("Boss1Zone");
}

void ABoss1Start::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ABoss1Start::AniCreate()
{
	startRender->CreateAnimation("Boss1Zone", "Boss1Zone.png", 0.075f, 0, 2, true);
}
