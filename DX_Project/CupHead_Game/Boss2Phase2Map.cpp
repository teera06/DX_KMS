#include "PreCompile.h"
#include "Boss2Phase2Map.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>


#include "ContentsENum.h"

#include "PokerChip.h"

ABoss2Phase2Map::ABoss2Phase2Map()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2Phase2Map");
	Boss2Phase2Map = CreateDefaultSubObject<USpriteRenderer>("Boss2Phase2Map");
	
	Boss2Phase2Map->SetupAttachment(Root);
	
	Boss2Phase2Map->SetOrder(ERenderOrder::Boss1_back3);
	Boss2Phase2Map->SetSprite("BossDevil_Phase1Background.png");
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

	Boss2Phase2Map->SetScale(FVector(1280.0f, 720.0f, 0.0f));
	Boss2Phase2Map->CreateAnimation("LastMap", "BossDevil_Phase1Background.png", 0.01f,false, 4, 5);

	Boss2Phase2Map->ChangeAnimation("LastMap");


	SetActorLocation(FVector(0.0f, 0.0f, 200.0f));
}

void ABoss2Phase2Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
