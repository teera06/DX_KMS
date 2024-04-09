#include "PreCompile.h"
#include "WorldGameMode.h"

#include "ScreenEffect.h"
#include "WorldMap.h"
#include "WorldPlayer.h"

#include <EngineCore/Camera.h>
AWorldGameMode::AWorldGameMode()
{
}

AWorldGameMode::~AWorldGameMode()
{
}

void AWorldGameMode::BeginPlay()
{
	Super::BeginPlay();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<AWorldPlayer>("WorldPlayer");
	GetWorld()->SpawnActor<AWorldMap>("WorldMap");
	GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");
}

void AWorldGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWorldGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AWorldGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
