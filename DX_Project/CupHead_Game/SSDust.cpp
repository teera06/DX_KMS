#include "PreCompile.h"
#include "SSDust.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

ASSDust::ASSDust()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("SSDust");


	Effect = CreateDefaultSubObject<USpriteRenderer>("SSDust");
	Effect->SetupAttachment(Root);
	Effect->SetAutoSize(1.0f, true);

	SetRoot(Root);


	Effect->SetOrder(ERenderOrder::FrontSkill);
	Effect->SetSprite("SSDust01.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
}

ASSDust::~ASSDust()
{
}

void ASSDust::BeginPlay()
{
	Super::BeginPlay();
	PlayerPos = APlay_Cuphead::GetPlayerPos();

	SetActorLocation(PlayerPos + (FVector::Up * 100.0f));

	Effect->CreateAnimation("SSDust", "SSDust", 0.015f);

	Effect->ChangeAnimation("SSDust");
}

void ASSDust::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (DushDir.iX() == 1)
	{
		Effect->SetDir(EEngineDir::Right);
	}
	else if (DushDir.iX() == -1)
	{
		Effect->SetDir(EEngineDir::Left);
	}

	if (true == Effect->IsCurAnimationEnd())
	{
		Destroy();
	}
}

