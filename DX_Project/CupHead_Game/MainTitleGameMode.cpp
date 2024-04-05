#include "PreCompile.h"
#include "MainTitleGameMode.h"
#include <EngineCore/Camera.h>

MainTitleGameMode::MainTitleGameMode()
{
}

MainTitleGameMode::~MainTitleGameMode()
{
}

void MainTitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ATitleLogo>("TitleLogo");
}

void MainTitleGameMode::Tick(float _DeltaTime)
{
}

void MainTitleGameMode::LevelEnd(ULevel* _NextLevel)
{
}

void MainTitleGameMode::LevelStart(ULevel* _PrevLevel)
{
}
