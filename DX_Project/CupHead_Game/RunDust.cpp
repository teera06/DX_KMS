#include "PreCompile.h"
#include "RunDust.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

ARunDust::ARunDust()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Dusy");


	Effect = CreateDefaultSubObject<USpriteRenderer>("Dust");
	Effect->SetupAttachment(Root);
	Effect->SetAutoSize(1.0f, true);

	SetRoot(Root);


	Effect->SetOrder(ERenderOrder::FilterEffect);
	Effect->SetSprite("irisA_0000.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
}

ARunDust::~ARunDust()
{
}

void ARunDust::BeginPlay()
{

	Super::BeginPlay();
	PlayerPos = APlay_Cuphead::GetPlayerPos();

	SetActorLocation(PlayerPos+FVector::Up*50.0f);

	Effect->CreateAnimation("RunDust", "RunDust", 0.05f);

	Effect->ChangeAnimation("RunDust");
}

void ARunDust::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	

	if (true == Effect->IsCurAnimationEnd())
	{
		Destroy();
	}
}
