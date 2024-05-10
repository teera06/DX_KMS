#include "PreCompile.h"
#include "EndingLevel.h"
#include "EndingActor.h"

AEndingLevel::AEndingLevel()
{
}

AEndingLevel::~AEndingLevel()
{
}

void AEndingLevel::BeginPlay()
{
	Super::BeginPlay();
}

void AEndingLevel::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AEndingLevel::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AEndingLevel::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelEnd(_PrevLevel);
}
