#include "PreCompile.h"
#include "Boss3Map.h"
#include "ContentsENum.h"
ABoss3Map::ABoss3Map()
{
	back3Map = CreateDefaultSubObject<USpriteRenderer>("back2");
	crowd3 = CreateDefaultSubObject<USpriteRenderer>("crowd3");
}

ABoss3Map::~ABoss3Map()
{
}

void ABoss3Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 20.0f, 75.0f));
	back3Map->SetOrder(ERenderOrder::Boss1_Back3);
	back3Map->SetSprite("back3.png");
	back3Map->SetSamplering(ETextureSampling::LINEAR);
	back3Map->SetAutoSize(2.0f, true);

	crowd3->SetOrder(ERenderOrder::Boss1_crowd3);
	crowd3->SetSprite("jazz_crowdA_0001.png");
	crowd3->SetSamplering(ETextureSampling::LINEAR);
	crowd3->CreateAnimation("A", "A", 0.1f);
	crowd3->ChangeAnimation("A");

	crowd3->SetAutoSize(1.0f, true);
}

void ABoss3Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
