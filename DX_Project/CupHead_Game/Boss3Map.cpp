#include "PreCompile.h"
#include "Boss3Map.h"
#include "ContentsENum.h"

#include <EngineCore/DefaultSceneComponent.h>
ABoss3Map::ABoss3Map()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");

	back3Map = CreateDefaultSubObject<USpriteRenderer>("back2");
	crowd3 = CreateDefaultSubObject<USpriteRenderer>("crowd3");
	Object1 = CreateDefaultSubObject<USpriteRenderer>("Object1");
	Object2 = CreateDefaultSubObject<USpriteRenderer>("Object2");

	back3Map->SetupAttachment(Root);
	crowd3->SetupAttachment(Root);
	Object1->SetupAttachment(Root);
	Object2->SetupAttachment(Root);

	Object1->AddPosition({ 0.0f, -355.0f, 50.0f });
	Object2->AddPosition({ 0.0f, -350.0f, -90.0f });
	crowd3->AddPosition({ 9.0f, -60.0f, 80.0f });
	SetRoot(Root);
}

ABoss3Map::~ABoss3Map()
{
}

void ABoss3Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 60.0f, 100.0f));
	back3Map->SetOrder(ERenderOrder::Boss1_Back3);
	back3Map->SetSprite("back3.png");
	back3Map->SetSamplering(ETextureSampling::LINEAR);
	back3Map->SetAutoSize(1.0f, true);

	crowd3->SetOrder(ERenderOrder::Boss1_crowd3);
	crowd3->SetSprite("jazz_crowdA_0001.png");
	crowd3->SetSamplering(ETextureSampling::LINEAR);
	crowd3->CreateAnimation("A", "A", 0.1f);
	crowd3->ChangeAnimation("A");

	crowd3->SetAutoSize(0.97f, true);

	Object1->SetOrder(ERenderOrder::Object1);
	Object1->SetSprite("table.png");

	Object1->SetAutoSize(2.1f, true);

	Object2->SetOrder(ERenderOrder::Object2);
	Object2->SetSprite("C8.png");

	Object2->SetAutoSize(1.3f, true);
}

void ABoss3Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
