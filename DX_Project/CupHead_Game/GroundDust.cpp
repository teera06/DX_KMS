#include "PreCompile.h"
#include "GroundDust.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"


AGroundDust::AGroundDust()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Dusy");


	Effect = CreateDefaultSubObject<USpriteRenderer>("Dust");
	Effect->SetupAttachment(Root);
	Effect->SetAutoSize(1.0f, true);

	SetRoot(Root);


	Effect->SetOrder(ERenderOrder::FrontSkill);
	Effect->SetSprite("LandDust01.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
}

AGroundDust::~AGroundDust()
{
}

void AGroundDust::BeginPlay()
{
	Super::BeginPlay();
	PlayerPos = APlay_Cuphead::GetPlayerPos();

	SetActorLocation(PlayerPos+FVector::Up*50.0f);

	Effect->CreateAnimation("LandDust", "LandDust", 0.075f);

	Effect->ChangeAnimation("LandDust");
}

void AGroundDust::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == Effect->IsCurAnimationEnd())
	{
		Destroy();
	}
}
