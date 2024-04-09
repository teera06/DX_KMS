#include "PreCompile.h"
#include "LoadActor.h"
#include "ContentsENum.h"

ALoadActor::ALoadActor()
{
	back = CreateDefaultSubObject<USpriteRenderer>("back");
	timmer = CreateDefaultSubObject<USpriteRenderer>("timmer");
}

ALoadActor::~ALoadActor()
{
}

void ALoadActor::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(180.0f, 320.0f, 100.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));

	back->SetOrder(ERenderOrder::background);
	back->SetSprite("irisA_0000.png");
	back->SetAutoSize(3.0f, true);
	back->SetSamplering(ETextureSampling::LINEAR);


	timmer->SetOrder(ERenderOrder::Log);
	timmer->SetSprite("hourglass_01.png");
	timmer->SetAutoSize(1.0f, true);
	timmer->SetSamplering(ETextureSampling::LINEAR);

	timmer->CreateAnimation("Hourglass", "Hourglass", 0.05f);

	timmer->ChangeAnimation("Hourglass");
}

void ALoadActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


}
