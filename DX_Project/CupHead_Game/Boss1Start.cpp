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
	
	startRender->SetOrder(ERenderOrder::Monster2);
	startRender->SetSprite("devil_ph3_idle_0001.png");
	startRender->SetSamplering(ETextureSampling::LINEAR);
	startRender->SetAutoSize(0.8f, true);
}

ABoss1Start::~ABoss1Start()
{
}

void ABoss1Start::BeginPlay()
{
	Super::BeginPlay();

}

void ABoss1Start::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ABoss1Start::AniCreate()
{

}
