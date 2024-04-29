#include "PreCompile.h"
#include "ScreenEffect.h"


#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
AScreenEffect::AScreenEffect()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");

	
	FilterEffect = CreateDefaultSubObject<USpriteRenderer>("FilterEffect");

	FilterEffect->SetupAttachment(Root);
	FilterEffect->SetScale(FVector(1280.0f, 720.0f, 2.0f));

	SetRoot(Root);


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
	
	SetActorLocation(FVector(0.0f, 0.0f, -50.0f));
	
	FilterEffect->CreateAnimation("Iris", "Iris", 0.05f,false);
	FilterEffect->CreateAnimation("IrisRe", "Iris", 0.05f, false,16,1);
	FilterEffect->CreateAnimation("ReadyWALLOP!", "ReadyWALLOP!", 0.05f, false);

}

void AScreenEffect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	switch (Effect)
	{
	case EScreenEffect::None:
		break;
	case EScreenEffect::Iris:
		FilterEffect->ChangeAnimation("Iris");
		break;
	case EScreenEffect::IrisRe:
		FilterEffect->ChangeAnimation("IrisRe");
		break;
	case EScreenEffect::ReadyWALLOP:
		FilterEffect->ChangeAnimation("ReadyWALLOP!");

		if (true == FilterEffect->IsCurAnimationEnd())
		{
			Destroy();
		}
		break;
	case EScreenEffect::Iris2:
		FilterEffect->ChangeAnimation("Iris");

		if (true == FilterEffect->IsCurAnimationEnd())
		{
			Destroy();
		}
		break;
	default:
		break;
	}

	if (Effect == EScreenEffect::Iris && true == FilterEffect->IsCurAnimationEnd())
	{
		Effect = EScreenEffect::ReadyWALLOP;
	}
}
