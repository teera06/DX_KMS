#include "PreCompile.h"
#include "WorldDust.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "ContentsENum.h"

#include "WorldPlayer.h"

AWorldDust::AWorldDust()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("WorldDust");


	Effect = CreateDefaultSubObject<USpriteRenderer>("WorldDust");
	Effect->SetupAttachment(Root);
	Effect->SetAutoSize(1.0f, true);

	SetRoot(Root);


	Effect->SetOrder(ERenderOrder::backSkill);
	Effect->SetSprite("world_playerDustA_0001.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
}

AWorldDust::~AWorldDust()
{
}

void AWorldDust::BeginPlay()
{
	Super::BeginPlay();
	PlayerPos = AWorldPlayer::GetPlayerPos();

	SetActorLocation(PlayerPos + FVector::Up * 10.0f);

	Effect->CreateAnimation("WorldDustA", "WorldDustA", 0.075f);

	Effect->ChangeAnimation("WorldDustA");
}

void AWorldDust::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == Effect->IsCurAnimationEnd())
	{
		Destroy();
	}
}
