#include "PreCompile.h"
#include "LoadActor.h"

ALoadActor::ALoadActor()
{
	timmer = CreateDefaultSubObject<USpriteRenderer>("timmer");
}

ALoadActor::~ALoadActor()
{
}

void ALoadActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(180.0f, 320.0f, 100.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	timmer->SetSprite("hourglass_01.png");
	timmer->SetSamplering(ETextureSampling::LINEAR);

	timmer->CreateAnimation("Hourglass", "Hourglass", 0.05f);

	timmer->ChangeAnimation("Hourglass");
}

void ALoadActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
