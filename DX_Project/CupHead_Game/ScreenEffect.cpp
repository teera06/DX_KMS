#include "PreCompile.h"
#include "ScreenEffect.h"
#include "ContentsENum.h"
AScreenEffect::AScreenEffect()
{
	OldFilter = CreateDefaultSubObject<USpriteRenderer>("OldRenderer");
}

AScreenEffect::~AScreenEffect()
{
}

void AScreenEffect::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 0.0f, -10.0f));
	OldFilter->SetOrder(ERenderOrder::Filter);
	OldFilter->SetSprite("cuphead_screen_fx_0000.png");
	OldFilter->SetAutoSize(2.0f, true);
	//CupRenderer->Get
	OldFilter->SetSamplering(ETextureSampling::LINEAR);

	OldFilter->CreateAnimation("OldFilmEffect", "OldFilmEffect", 0.05f);

	OldFilter->ChangeAnimation("OldFilmEffect");
}

void AScreenEffect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}