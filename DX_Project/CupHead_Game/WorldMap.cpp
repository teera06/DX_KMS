#include "PreCompile.h"
#include "WorldMap.h"

#include "ContentsENum.h"
#include "ContentsHelper.h"

#include <EngineCore/SpriteRenderer.h>

AWorldMap::AWorldMap()
{
	//MapRenderer = CreateDefaultSubObject<USpriteRenderer>("MapRenderer");
	ColRenderer = CreateDefaultSubObject<USpriteRenderer>("ColRenderer");
	InputOn();
}

AWorldMap::~AWorldMap()
{
}

void AWorldMap::SetColMapImage()
{
	ColRenderer->SetSprite("WorldMap_PixelCheck.png");
	ColRenderer->SetOrder(ERenderOrder::WorldMap);
	//UContentsHelper::MapTex = UEngineTexture::FindRes("WorldMap_PixelCheck.png");; // ÇÈ¼¿ Ãæµ¹ÇÒ ¸Ê ¼³Á¤
	ColRenderer->SetAutoSize(1.0f, true);
}

void AWorldMap::BeginPlay()
{
	Super::BeginPlay();

	SetColMapImage();
	//SetActorScale3D(FVector(3200.0f, 2220.0f, 100.0f));
	//SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
	//SetMapImage();
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	//MapRenderer->SetSprite("WorldMap.png");
	//MapRenderer->SetSamplering(ETextureSampling::LINEAR);

	//MapRenderer->CreateAnimation("Hourglass", "Hourglass", 0.05f);

	//MapRenderer->ChangeAnimation("Hourglass");
}

void AWorldMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AWorldMap::SetMapImage()
{
	//SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
	//MapRenderer->SetOrder(ERenderOrder::WorldMap);
	//MapRenderer->SetSprite("WorldMap.png");
	//MapRenderer->SetSamplering(ETextureSampling::LINEAR);
	//MapRenderer->SetAutoSize(1.0f, true);
}
