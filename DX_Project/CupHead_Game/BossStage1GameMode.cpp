#include "PreCompile.h"
#include "BossStage1GameMode.h"

#include "Boss1Map.h"
#include <EngineCore/Camera.h>

ABossStage1GameMode::ABossStage1GameMode()
{
}

ABossStage1GameMode::~ABossStage1GameMode()
{
}

void ABossStage1GameMode::BeginPlay()
{
	Super::BeginPlay();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ABoss1Map>("Boss1Map");
}

void ABossStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ABossStage1GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ABossStage1GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
