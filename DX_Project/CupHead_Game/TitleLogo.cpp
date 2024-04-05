#include "PreCompile.h"
#include "TitleLogo.h"

ATitleLogo::ATitleLogo() 
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");

}

int Index = 0;

ATitleLogo::~ATitleLogo() 
{
}

void ATitleLogo::RendererOn()
{
	Renderer->SetSprite("CharRun0.png", 11);
	//Renderer->SetActive(true);
	DelayCallBack(0.2f, std::bind(&ATitleLogo::RendererOff, this));

	// ++Index;
}

void ATitleLogo::RendererOff()
{
	Renderer->SetSprite("CharRun0.png", 11);
	//Renderer->SetActive(false);
	DelayCallBack(0.2f, std::bind(&ATitleLogo::RendererOn, this));

	// ++Index;
}

void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(700.0f, 300.0f, 100.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));

	// Renderer->SetSamplering(ETextureSampling::LINEAR);
	Renderer->SetSprite("CharRun0.png");

	Renderer->CreateAnimation("Run", "Run", 0.5f);

	Renderer->ChangeAnimation("Run");

}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
