#include "PreCompile.h"
#include "WorldMap.h"

#include "ContentsENum.h"
#include "ContentsHelper.h"

#include <EngineCore/DefaultSceneComponent.h>

#include <EngineCore/SpriteRenderer.h>

AWorldMap::AWorldMap()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("WorldMap");

	MapRenderer = CreateDefaultSubObject<USpriteRenderer>("MapRenderer");

	MapRenderer->SetupAttachment(Root);

	SetRoot(Root);
	InputOn();
}

AWorldMap::~AWorldMap()
{
}

void AWorldMap::SetColMapImage()
{
	ColRenderer->SetSprite("WorldMap_PixelCheck.png");
	ColRenderer->SetOrder(ERenderOrder::WorldCol);
	ColRenderer->SetAutoSize(1.0f, true);
}

void AWorldMap::BeginPlay()
{
	Super::BeginPlay();

	//SetColMapImage();
	SetMapImage();
}

void AWorldMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWorldMap::SetMapImage()
{
	SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
	MapRenderer->SetOrder(ERenderOrder::WorldMap);
	MapRenderer->SetSprite("WorldMap.png");
	MapRenderer->SetSamplering(ETextureSampling::LINEAR);
	MapRenderer->SetAutoSize(1.0f, true);
}
