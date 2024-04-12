#include "PreCompile.h"
#include "WorldGameMode.h"

#include "ScreenEffect.h"
#include "WorldMap.h"
#include "WorldPlayer.h"
#include "ContentsHelper.h"


#include <EngineCore/Camera.h>
AWorldGameMode::AWorldGameMode()
{
}

AWorldGameMode::~AWorldGameMode()
{
}

void AWorldGameMode::BeginPlay()
{
	Super::BeginPlay();

	UContentsHelper::MapTex = UEngineTexture::FindRes("WorldMap_PixelCheck.png");
	UContentsHelper::MapTexScale = UContentsHelper::MapTex->GetScale();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(1500.0f / 2.0f, -1700.0f / 2.0f, -100.0f));
	GetWorld()->SpawnActor<AWorldPlayer>("WorldPlayer");
	{
		std::shared_ptr<AWorldMap> Front = GetWorld()->SpawnActor<AWorldMap>("WorldMap");

		float4 TexScale = UContentsHelper::MapTexScale;
		float4 ImageScale = { TexScale.X, TexScale.Y, 0.0f };

		Front->SetActorScale3D(ImageScale);
		Front->SetActorLocation({ ImageScale.hX(), -ImageScale.hY(), 100.0f});
	}

	GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");
}

void AWorldGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWorldGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AWorldGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
