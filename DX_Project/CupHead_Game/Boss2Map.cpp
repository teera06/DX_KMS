#include "PreCompile.h"
#include "Boss2Map.h"
#include "ContentsENum.h"
ABoss2Map::ABoss2Map()
{
	back2Map = CreateDefaultSubObject<USpriteRenderer>("back2");
}

ABoss2Map::~ABoss2Map()
{
}

void ABoss2Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, -10.0f, 100.0f));
	back2Map->SetOrder(ERenderOrder::Boss1_back2);
	back2Map->SetSprite("back2.png");
	back2Map->SetSamplering(ETextureSampling::LINEAR);
	back2Map->SetAutoSize(1.0f, true);
}

void ABoss2Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
