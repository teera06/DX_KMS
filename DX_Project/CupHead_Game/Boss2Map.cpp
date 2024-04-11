#include "PreCompile.h"
#include "Boss2Map.h"
#include "ContentsENum.h"
ABoss2Map::ABoss2Map()
{
	back2Map = CreateDefaultSubObject<USpriteRenderer>("back2");
	crowd2 = CreateDefaultSubObject<USpriteRenderer>("crowd2");
}

ABoss2Map::~ABoss2Map()
{
}

void ABoss2Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 140.0f, 160.0f));
	back2Map->SetOrder(ERenderOrder::Boss1_back2);
	back2Map->SetSprite("back2.png");
	back2Map->SetSamplering(ETextureSampling::LINEAR);
	back2Map->SetAutoSize(1.0f, true);

	crowd2->SetOrder(ERenderOrder::Boss1_crowd2);
	crowd2->SetSprite("jazz_crowdB_0001.png");
	crowd2->SetSamplering(ETextureSampling::LINEAR);
	crowd2->CreateAnimation("B", "B", 0.1f);
	crowd2->ChangeAnimation("B");

	crowd2->SetAutoSize(1.0f, true);
}

void ABoss2Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
