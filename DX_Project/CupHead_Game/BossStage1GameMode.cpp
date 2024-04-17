#include "PreCompile.h"
#include "BossStage1GameMode.h"

#include "Boss1Map.h"
#include "Boss2Map.h"
#include "Boss3Map.h"
#include "ScreenEffect.h"
#include "Play_Cuphead.h"
#include "Boss1_Monster1.h"
#include "Boss1_Monster2.h"
#include "ContentsHelper.h"

#include "ball.h"


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
	UContentsHelper::MapTex = UEngineTexture::FindRes("back3back.png");
	UContentsHelper::MapTexScale = UContentsHelper::MapTex->GetScale();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ABoss1Map>("Boss1Map");
	GetWorld()->SpawnActor<ABoss2Map>("Boss2Map");
	GetWorld()->SpawnActor<ABoss3Map>("Boss3Map");
	GetWorld()->SpawnActor<APlay_Cuphead>("Play_Cuphead");
	GetWorld()->SpawnActor<ABoss1_Monster1>("Boss1_Monster1");
	GetWorld()->SpawnActor<ABoss1_Monster2>("Boss1_Monster2");
	GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");

	GetWorld()->SpawnActor<Aball>("ball");

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
