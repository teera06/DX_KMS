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

	SetActorScale3D(FVector(700.0f, 300.0f, 100.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));

	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->SetSprite("cuphead_title_screen_0001.png");

	Renderer->CreateAnimation("Run", "Run", 0.5f);

	Renderer->ChangeAnimation("Run");
}

void AMainTitleActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
