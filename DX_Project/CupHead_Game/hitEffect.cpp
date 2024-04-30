#include "PreCompile.h"
#include "hitEffect.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsENum.h"

#include "Play_Cuphead.h"



AhitEffect::AhitEffect()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("hit");


	Effect = CreateDefaultSubObject<USpriteRenderer>("hit");
	Effect->SetupAttachment(Root);
	Effect->SetAutoSize(1.0f, true);

	SetRoot(Root);


	Effect->SetOrder(ERenderOrder::FrontSkill);
	Effect->SetSprite("player_hitFXa_0001.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
}

AhitEffect::~AhitEffect()
{
}

void AhitEffect::BeginPlay()
{
	Super::BeginPlay();
	PlayerPos = APlay_Cuphead::GetPlayerPos();

	SetActorLocation(PlayerPos + FVector::Up * 50.0f);

	Effect->CreateAnimation("HitFX01", "HitFX01", 0.075f);

	Effect->ChangeAnimation("HitFX01");
}


void AhitEffect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (hitDir.iX() == 1)
	{
		Effect->SetDir(EEngineDir::Right);
	}
	else if (hitDir.iX() == -1)
	{
		Effect->SetDir(EEngineDir::Left);
	}

	if (true == Effect->IsCurAnimationEnd())
	{
		Destroy();
	}
}
