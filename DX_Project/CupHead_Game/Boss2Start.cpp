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
	startRender->SetSprite("Boss1Zone.png");
	startRender->SetSamplering(ETextureSampling::LINEAR);
	startRender->SetAutoSize(1.0f, true);

	SetRoot(Root);
}

ABoss2Start::~ABoss2Start()
{
}

void ABoss2Start::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FVector(0.0f, 0.0f, 7.0f));
	SetActorLocation({ 2300.0f, -1500.0f, 100.0f });
	AniCreate();

	startRender->ChangeAnimation("Boss1Zone");
}

void ABoss2Start::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ABoss2Start::AniCreate()
{
	startRender->CreateAnimation("Boss1Zone", "Boss1Zone.png", 0.075f, 0, 2, true);
}
