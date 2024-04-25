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

	FilterEffect = CreateDefaultSubObject<USpriteRenderer>("FilterEffect");

	FilterEffect->SetupAttachment(Root);
	FilterEffect->SetScale(FVector(1280.0f, 720.0f, 2.0f));

	SetRoot(Root);

	OldFilter->SetOrder(ERenderOrder::Filter);
	OldFilter->SetSprite("cuphead_screen_fx_0000.png");
	OldFilter->SetSamplering(ETextureSampling::LINEAR);

	FilterEffect->SetOrder(ERenderOrder::FilterEffect);
	FilterEffect->SetSprite("irisA_0000.png");
	FilterEffect->SetSamplering(ETextureSampling::LINEAR);
}

AScreenEffect::~AScreenEffect()
{
}

void AScreenEffect::BeginPlay()
{
	Super::BeginPlay();
	
	OldFilter->CreateAnimation("OldFilmEffect", "OldFilmEffect", 0.05f);
	FilterEffect->CreateAnimation("Iris", "Iris", 0.05f,false);

	FilterEffect->SetActive(false);
	OldFilter->ChangeAnimation("OldFilmEffect");
	OldFilter->SetActive(false);
}

void AScreenEffect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
