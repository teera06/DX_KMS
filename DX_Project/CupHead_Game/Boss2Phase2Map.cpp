#include "PreCompile.h"
#include "Boss2Phase2Map.h"

#include "ContentsENum.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

ABoss2Phase2Map::ABoss2Phase2Map()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2Phase2Map");
	Boss2Phase2Map = CreateDefaultSubObject<USpriteRenderer>("Boss2Phase2Map");
	
	Boss2Phase2Map->SetupAttachment(Root);
	
	Boss2Phase2Map->SetOrder(ERenderOrder::Boss1_back3);
	Boss2Phase2Map->SetSprite("BossDevil_Phase2Background.png");
	Boss2Phase2Map->SetSamplering(ETextureSampling::LINEAR);
	Boss2Phase2Map->SetAutoSize(1.2f, true);

	SetRoot(Root);
}

ABoss2Phase2Map::~ABoss2Phase2Map()
{
}

void ABoss2Phase2Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 0.0f, 200.0f));
}

void ABoss2Phase2Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
