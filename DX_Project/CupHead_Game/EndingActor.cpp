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

}

AEndingActor::~AEndingActor()
{
}

void AEndingActor::BeginPlay()
{
	Super::BeginPlay();

	end->SetOrder(ERenderOrder::Log);
	end->SetSprite("shorfrog_clap_ball_0001.png");
	end->SetSamplering(ETextureSampling::LINEAR);
	end->SetAutoSize(1.0f, true);
	end->CreateAnimation("Ending", "Ending", 0.075f);

	end->ChangeAnimation("Endgind");
}

void AEndingActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == end->IsCurAnimationEnd())
	{
		GEngine->ChangeLevel("Loading");
	}
}
