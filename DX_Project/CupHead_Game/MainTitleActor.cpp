#include "PreCompile.h"
#include "MainTitleActor.h"

#include <EngineCore/DefaultSceneComponent.h>

#include "ContentsENum.h"


AMainTitleActor::AMainTitleActor()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("title");

	titleRenderer = CreateDefaultSubObject<USpriteRenderer>("titleRenderer");

	CupRenderer = CreateDefaultSubObject<USpriteRenderer>("CupRenderer");

	button = CreateDefaultSubObject<USpriteRenderer>("button");

	//Renderer->SetScale(FVector(100.0f, 100.0f, 100.0f));
	titleRenderer->SetupAttachment(Root);
	
	CupRenderer->SetupAttachment(Root);

	button->SetupAttachment(Root);

	CupRenderer->AddPosition({ 0.0f, -360.0f, 0.0f });
	CupRenderer->SetPivot(EPivot::BOT);
	CupRenderer->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	button->AddPosition({ 0.0f, -320.0f, 0.0f });
	button->SetPivot(EPivot::BOT);

	button->SetMulColor(FVector(0.9f, 0.9f, 0.9f));
	
	SetRoot(Root);


}

AMainTitleActor::~AMainTitleActor()
{
}

void AMainTitleActor::BeginPlay()
{
	Super::BeginPlay();

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

	button->SetOrder(ERenderOrder::Log);
	button->SetSprite("TitleButton.png");
	button->SetAutoSize(0.8f, true);
	button->SetSamplering(ETextureSampling::LINEAR);
	CupRenderer->CreateAnimation("CupDence", "CupDence", 0.042f);

	CupRenderer->ChangeAnimation("CupDence");

}

void AMainTitleActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == CupRenderer->IsCurAnimationEnd())
	{
		if (true == OnOff)
		{
			OnOff = false;
		}
		else
		{
			OnOff = true;
		}

		button->SetActive(OnOff);
	}
}

void AMainTitleActor::DebugMessageFunction()
{

}
