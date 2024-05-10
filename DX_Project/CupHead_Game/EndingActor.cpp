#include "PreCompile.h"
#include "EndingActor.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

#include "ContentsHelper.h"
#include "ContentsENum.h"

AEndingActor::AEndingActor()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("end");

	end = CreateDefaultSubObject<USpriteRenderer>("end");

	end->SetupAttachment(Root);

	SetRoot(Root);

}

AEndingActor::~AEndingActor()
{
}

void AEndingActor::BeginPlay()
{
	Super::BeginPlay();

	end->SetOrder(ERenderOrder::Log);
	end->SetSprite("book_outro_0000.png");
	end->SetSamplering(ETextureSampling::LINEAR);
	end->SetAutoSize(1.0f, true);
	end->CreateAnimation("TheEnd", "TheEnd", 0.075f);

	end->ChangeAnimation("TheEnd");
}

void AEndingActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == end->IsCurAnimationEnd())
	{
		Destroy();
		GEngine->ChangeLevel("Loading");
	}
}
