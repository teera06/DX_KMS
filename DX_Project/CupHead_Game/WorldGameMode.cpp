#include "PreCompile.h"
#include "WorldGameMode.h"

WorldGameMode::WorldGameMode()
{
}

WorldGameMode::~WorldGameMode()
{
}

void WorldGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void WorldGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void WorldGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void WorldGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
