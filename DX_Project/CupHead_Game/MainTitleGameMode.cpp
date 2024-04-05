#include "PreCompile.h"
#include "MainTitleGameMode.h"
#include "MainTitleActor.h"

#include <EngineCore/Camera.h>

AMainTitleGameMode::AMainTitleGameMode()
{
}

AMainTitleGameMode::~AMainTitleGameMode()
{
}

void AMainTitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<AMainTitleActor>("TitleLogo");
}

void AMainTitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AMainTitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AMainTitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
