#include "PreCompile.h"
#include "BossStage2GameMode.h"

BossStage2GameMode::BossStage2GameMode()
{
}

BossStage2GameMode::~BossStage2GameMode()
{
}

void BossStage2GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void BossStage2GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void BossStage2GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void BossStage2GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
