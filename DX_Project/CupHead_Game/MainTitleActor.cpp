#include "PreCompile.h"
#include "MainTitleActor.h"
#include "ContentsENum.h"
#include <EngineCore/DefaultSceneComponent.h>

AMainTitleActor::AMainTitleActor()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("title");

	titleRenderer = CreateDefaultSubObject<USpriteRenderer>("titleRenderer");

	CupRenderer = CreateDefaultSubObject<USpriteRenderer>("CupRenderer");

	//Renderer->SetScale(FVector(100.0f, 100.0f, 100.0f));
	titleRenderer->SetupAttachment(Root);
	CupRenderer->SetupAttachment(Root);

	//USpriteRenderer* ChildRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	//ChildRenderer->SetupAttachment(Root);
	//ChildRenderer->SetScale(FVector(100.0f, 100.0f, 100.0f));
	CupRenderer->AddPosition({ 0.0f, -55.0f, 0.0f });
	SetRoot(Root);
}

AMainTitleActor::~AMainTitleActor()
{
}

void AMainTitleActor::BeginPlay()
{
	Super::BeginPlay();
	//SetActorLocation(FVector(0.0f, 0.0f, 50.0f));
	//SetActorScale3D(FVector(1100.0f, 620.0f, 0.0f));

	titleRenderer->SetOrder(ERenderOrder::background);
	titleRenderer->SetSprite("title_screen_background.png");
	titleRenderer->SetAutoSize(1.0f, true);
	titleRenderer->SetSamplering(ETextureSampling::LINEAR);
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	CupRenderer->SetOrder(ERenderOrder::CupheadDence);
	CupRenderer->SetSprite("cuphead_title_screen_0001.png");
	CupRenderer->SetAutoSize(1.0f, true);
	//CupRenderer->Get
	CupRenderer->SetSamplering(ETextureSampling::LINEAR);

	CupRenderer->CreateAnimation("CupDence", "CupDence", 0.05f);

	CupRenderer->ChangeAnimation("CupDence");

}

void AMainTitleActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	int a = 0;
}
