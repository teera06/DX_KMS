#include "PreCompile.h"
#include "MainMenuMode.h"

AMainMenuMode::AMainMenuMode()
{
}

AMainMenuMode::~AMainMenuMode()
{
}

void AMainMenuMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMainMenuMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AMainMenuMode::LevelEnd(ULevel* _NextLevel)
{
}

void AMainMenuMode::LevelStart(ULevel* _PrevLevel)
{
}
