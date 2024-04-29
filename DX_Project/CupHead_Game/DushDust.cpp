#include "PreCompile.h"
#include "DushDust.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

ADushDust::ADushDust()
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

ADushDust::~ADushDust()
{
}

void ADushDust::BeginPlay()
{
	Super::BeginPlay();
	PlayerPos = APlay_Cuphead::GetPlayerPos();

	SetActorLocation(PlayerPos + FVector::Up * 100.0f);

	Effect->CreateAnimation("DashDust", "DashDust", 0.05f);

	Effect->ChangeAnimation("DashDust");
}

void ADushDust::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == Effect->IsCurAnimationEnd())
	{
		Destroy();
	}
}
