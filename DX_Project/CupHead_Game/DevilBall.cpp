#include "PreCompile.h"
#include "DevilBall.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ADevilBall::ADevilBall()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("DevilBall");
	DevilBall = CreateDefaultSubObject<USpriteRenderer>("DevilBall");

	DevilBall->SetupAttachment(Root);

	SetRoot(Root);

	DevilBall->SetOrder(ERenderOrder::backSkill);
	DevilBall->SetSprite("devil_ph1_fire_orb_a_0001.png");
	DevilBall->SetSamplering(ETextureSampling::LINEAR);
	DevilBall->SetAutoSize(1.0f, true);
}

ADevilBall::~ADevilBall()
{
}

void ADevilBall::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(200.0f, 200.0f, 10.0f));
	
}

void ADevilBall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Collisiongather(_DeltaTime);
}

void ADevilBall::Collisiongather(float _DeltaTime)
{

	if (WallHitCount == HitCount)
	{
		Destroy();
	}

	if (GetActorLocation().iX() <= -640 ||GetActorLocation().iX() >= 640)
	{
		HitCount++;
		StartPos.X *= -1.0f;
	}


	if (GetActorLocation().iY() <= -350 || GetActorLocation().iY() >= 360)
	{
		HitCount++;
		StartPos.Y *= -1.0f;
	}

	AddActorLocation(StartPos * Speed * _DeltaTime);
}
