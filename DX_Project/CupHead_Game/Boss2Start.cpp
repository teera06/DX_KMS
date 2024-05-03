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

	startRender->SetOrder(ERenderOrder::MidObject);
	startRender->SetSprite("world_platforming_icon_0001.png");
	startRender->SetSamplering(ETextureSampling::LINEAR);
	startRender->SetAutoSize(1.0f, true);




	startCollision = CreateDefaultSubObject<UCollision>("startCollision1");
	startCollision->SetupAttachment(Root);

	startCollision->SetScale(FVector(50.0f, 60.0f, 100.0f));

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
	SetActorLocation({ 2200.0f, -950.0f, 100.0f });
}

void ABoss2Start::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}


