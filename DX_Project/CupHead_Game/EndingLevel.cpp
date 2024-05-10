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
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<AEndingActor>("Ending");
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
