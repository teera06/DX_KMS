#include "PreCompile.h"
#include "WorldBack.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>


#include "ContentsENum.h"

AWorldBack::AWorldBack()
{
	ColRenderer = CreateDefaultSubObject<USpriteRenderer>("ColRenderer");
	InputOn();
}

AWorldBack::~AWorldBack()
{
}

void AWorldBack::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(3844.0f, 2211.0f, 100.0f));
	//SetActorLocation(FVector(0.0f, 0.0f, 100.0f));
	ColRenderer->SetOrder(ERenderOrder::WorldCol);
	// 내부에서 샘플러도 같이 찾을
	ColRenderer->SetSprite("WorldMap_PixelCheck.png");

	ColRenderer->SetAutoSize(1.0f, true);

}

void AWorldBack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
