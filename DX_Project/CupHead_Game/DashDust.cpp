#include "PreCompile.h"
#include "DashDust.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

ADashDust::ADashDust()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Dusy");


	Effect = CreateDefaultSubObject<USpriteRenderer>("Dust");
	Effect->SetupAttachment(Root);
	Effect->SetAutoSize(1.0f, true);

	SetRoot(Root);


	Effect->SetOrder(ERenderOrder::FrontSkill);
	Effect->SetSprite("DashDust01.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
}

ADashDust::~ADashDust()
{
}

void ADashDust::BeginPlay()
{
	Super::BeginPlay();
	PlayerPos = APlay_Cuphead::GetPlayerPos();

	SetActorLocation(PlayerPos + FVector::Up * 100.0f);

	Effect->CreateAnimation("DashDust", "DashDust", 0.075f);

	Effect->ChangeAnimation("DashDust");
}

void ADashDust::Tick(float _DeltaTime)
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
