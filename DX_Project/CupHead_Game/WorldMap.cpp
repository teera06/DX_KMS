#include "PreCompile.h"
#include "WorldMap.h"
#include "ContentsHelper.h"
#include "ContentsENum.h"
AWorldMap::AWorldMap()
{
	MapRenderer = CreateDefaultSubObject<USpriteRenderer>("MapRenderer");
	ColRenderer = CreateDefaultSubObject<USpriteRenderer>("ColRenderer");
}

AWorldMap::~AWorldMap()
{
}

void AWorldMap::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(3200.0f, 2220.0f, 100.0f));
	SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
	SetColMapImage();
	SetMapImage();
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
	MapRenderer->SetOrder(ERenderOrder::WorldMap);
	MapRenderer->SetSprite("WorldMap.png");
	MapRenderer->SetSamplering(ETextureSampling::LINEAR);
}

void AWorldMap::SetColMapImage()
{
	ColRenderer->SetOrder(ERenderOrder::WorldCol);
	ColRenderer->SetSprite("WorldMap_PixelCheck.png");
	ColRenderer->SetSamplering(ETextureSampling::LINEAR);
	UContentsHelper::MapTex = UEngineTexture::FindRes("WorldMap_PixelCheck.png");
}

void AWorldMap::SwitchDebug()
{
}
