#include "PreCompile.h"
#include "Boss1Map.h"

ABoss1Map::ABoss1Map()
{
	Boss1MapRenderer = CreateDefaultSubObject<USpriteRenderer>("Boss1MapRenderer");
}

ABoss1Map::~ABoss1Map()
{
}

void ABoss1Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	Boss1MapRenderer->SetSprite("one1.png");
	Boss1MapRenderer->SetSamplering(ETextureSampling::LINEAR);

	//MapRenderer->CreateAnimation("Hourglass", "Hourglass", 0.05f);

	//MapRenderer->ChangeAnimation("Hourglass");
}

void ABoss1Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
