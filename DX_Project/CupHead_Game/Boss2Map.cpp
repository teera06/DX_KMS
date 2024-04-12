#include "PreCompile.h"
#include "Boss2Map.h"
#include "ContentsENum.h"

#include <EngineCore/DefaultSceneComponent.h>
ABoss2Map::ABoss2Map()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");
	back2Map = CreateDefaultSubObject<USpriteRenderer>("back2");
	crowd2 = CreateDefaultSubObject<USpriteRenderer>("crowd2");
	JazzGirls = CreateDefaultSubObject<USpriteRenderer>("JazzGirls");

	back2Map->SetupAttachment(Root);
	crowd2->SetupAttachment(Root);
	JazzGirls->SetupAttachment(Root);

	crowd2->AddPosition({ -350.0f,-150.0f,0.0f });
	JazzGirls->AddPosition({ 20.0f,-78.0f,0.0f });
	SetRoot(Root);
}

ABoss2Map::~ABoss2Map()
{
}

void ABoss2Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 180.0f, 160.0f));
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

	JazzGirls->SetOrder(ERenderOrder::Boss1_crowd2);
	JazzGirls->SetSprite("jazz_girls_0001.png");
	JazzGirls->SetSamplering(ETextureSampling::LINEAR);
	JazzGirls->CreateAnimation("Jazz Girls", "Jazz Girls", 0.1f);
	JazzGirls->ChangeAnimation("Jazz Girls");

	JazzGirls->SetAutoSize(1.0f, true);
}

void ABoss2Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
