#include "PreCompile.h"
#include "ScreenEffect.h"
#include "ContentsENum.h"

#include <EngineCore/DefaultSceneComponent.h>
AScreenEffect::AScreenEffect()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");

	OldFilter = CreateDefaultSubObject<USpriteRenderer>("OldRenderer");

	OldFilter->SetupAttachment(Root);

	SetRoot(Root);
}

AScreenEffect::~AScreenEffect()
{
}

void AScreenEffect::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(FVector(0.0f, 0.0f, -10.0f));
	//SetActorScale3D(FVector(1100.0f, 620.0f, 0.0f));
	OldFilter->SetOrder(ERenderOrder::Filter);
	OldFilter->SetSprite("cuphead_screen_fx_0000.png");
	OldFilter->SetAutoSize(4.0f, true);
	//CupRenderer->Get
	OldFilter->SetSamplering(ETextureSampling::LINEAR);

	OldFilter->CreateAnimation("OldFilmEffect", "OldFilmEffect", 0.05f);

	OldFilter->ChangeAnimation("OldFilmEffect");
}

void AScreenEffect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
