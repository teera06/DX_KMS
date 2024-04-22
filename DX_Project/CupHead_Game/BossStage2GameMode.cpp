#include "PreCompile.h"
#include "BossStage2GameMode.h"


#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>
#include <EngineCore/BlurEffect.h>

#include "BossBackMap1.h"
#include "BossBackMap2.h"
#include "Play_Cuphead.h"


#include "ContentsENum.h"

ABossStage2GameMode::ABossStage2GameMode()
{
}

ABossStage2GameMode::~ABossStage2GameMode()
{
}

void ABossStage2GameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ABossBackMap1>("BossBackMap1");
	GetWorld()->SpawnActor<ABossBackMap2>("BossBackMap2");
	GetWorld()->SpawnActor<APlay_Cuphead>("Play_Cuphead");

	GetWorld()->GetLastTarget()->AddEffect<UBlurEffect>();
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
