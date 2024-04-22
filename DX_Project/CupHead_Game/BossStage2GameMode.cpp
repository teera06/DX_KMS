#include "PreCompile.h"
#include "BossStage2GameMode.h"

ABossStage2GameMode::ABossStage2GameMode()
{
}

ABossStage2GameMode::~ABossStage2GameMode()
{
}

void ABossStage2GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ABossStage2GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ABossStage2GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ABossStage2GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
