#include "PreCompile.h"
#include "ScreenEffect.h"
#include "ContentsENum.h"

#include <EngineCore/DefaultSceneComponent.h>
AScreenEffect::AScreenEffect()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");

	OldFilter = CreateDefaultSubObject<USpriteRenderer>("OldRenderer");

	OldFilter->SetupAttachment(Root);
	OldFilter->SetScale(FVector(1280.0f, 720.0f, 2.0f));

	SetRoot(Root);

	OldFilter->SetOrder(ERenderOrder::Filter);
	OldFilter->SetSprite("cuphead_screen_fx_0000.png");
	//OldFilter->SetAutoSize(1.0f, true);
	OldFilter->SetSamplering(ETextureSampling::LINEAR);
}

AScreenEffect::~AScreenEffect()
{
}

void AScreenEffect::BeginPlay()
{
	Super::BeginPlay();
	
	OldFilter->CreateAnimation("OldFilmEffect", "OldFilmEffect", 0.05f);

	OldFilter->ChangeAnimation("OldFilmEffect");
}

void AScreenEffect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
