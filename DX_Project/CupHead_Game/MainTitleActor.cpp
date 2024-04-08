#include "PreCompile.h"
#include "MainTitleActor.h"

AMainTitleActor::AMainTitleActor()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

AMainTitleActor::~AMainTitleActor()
{
}

void AMainTitleActor::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, -50.0f, 0.0f));
	SetActorScale3D(FVector(1100.0f, 620.0f, 100.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	Renderer->SetSprite("cuphead_title_screen_0001.png");
	Renderer->SetSamplering(ETextureSampling::LINEAR);

	Renderer->CreateAnimation("CupDence", "CupDence", 0.05f);

	Renderer->ChangeAnimation("CupDence");
}

void AMainTitleActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
