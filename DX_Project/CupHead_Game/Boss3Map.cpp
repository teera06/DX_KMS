#include "PreCompile.h"
#include "Boss3Map.h"
#include "ContentsENum.h"
ABoss3Map::ABoss3Map()
{
	back3Map = CreateDefaultSubObject<USpriteRenderer>("back2");
}

ABoss3Map::~ABoss3Map()
{
}

void ABoss3Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, -50.0f, 50.0f));
	back3Map->SetOrder(ERenderOrder::Boss1_Back3);
	back3Map->SetSprite("back3.png");
	back3Map->SetSamplering(ETextureSampling::LINEAR);
	back3Map->SetAutoSize(2.0f, true);
}

void ABoss3Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
