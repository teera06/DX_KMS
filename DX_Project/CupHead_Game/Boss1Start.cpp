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
	
	startRender->SetOrder(ERenderOrder::FrontGround1);
	startRender->SetSprite("Boss1Zone.png");
	startRender->SetSamplering(ETextureSampling::LINEAR);
	startRender->SetAutoSize(1.0f, true);

	SetRoot(Root);
}

ABoss1Start::~ABoss1Start()
{
}

void ABoss1Start::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation({ -500.0f, -500.0f, 100.0f });
	//AniCreate();

	//startRender->ChangeAnimation("Boss1Zone");
}

void ABoss1Start::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ABoss1Start::AniCreate()
{
	//startRender->CreateAnimation("Boss1Zone", "Boss1Zone.png", 0.075f, 0, 2, true);
}
