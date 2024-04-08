#include "PreCompile.h"
#include "WorldMap.h"

AWorldMap::AWorldMap()
{
	MapRenderer = CreateDefaultSubObject<USpriteRenderer>("MapRenderer");
}

AWorldMap::~AWorldMap()
{
}

void AWorldMap::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(3200.0f, 2220.0f, 100.0f));
	SetActorLocation(FVector(0.0f, 0.0f, -50.0f));
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	MapRenderer->SetSprite("WorldMap.png");
	MapRenderer->SetSamplering(ETextureSampling::LINEAR);

	//MapRenderer->CreateAnimation("Hourglass", "Hourglass", 0.05f);

	//MapRenderer->ChangeAnimation("Hourglass");
}

void AWorldMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
