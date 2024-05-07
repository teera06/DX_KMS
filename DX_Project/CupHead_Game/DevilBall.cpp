#include "PreCompile.h"
#include "DevilBall.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

ADevilBall::ADevilBall()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("DevilBall");
	DevilBall = CreateDefaultSubObject<USpriteRenderer>("DevilBall");

	DevilBall->SetupAttachment(Root);

	DevilBallCol = CreateDefaultSubObject<UCollision>("DevilBallCol");
	DevilBallCol->SetupAttachment(Root);
	DevilBallCol->SetScale(FVector(70.0f, 70.0f, 100.0f));
	DevilBallCol->SetCollisionGroup(ECollisionOrder::Devil1ball);
	DevilBallCol->SetCollisionType(ECollisionType::RotRect);

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

	DevilBall->CreateAnimation("Orb_Bubble", "Orb_Bubble",0.05f);
	DevilBall->CreateAnimation("Orb_Bubble_Parry", "Orb_Bubble_Parry", 0.05f);

}

void ADevilBall::Tick(float _DeltaTime)
{
	if (false == ParryCheck)
	{
		DevilBall->ChangeAnimation("Orb_Bubble");
	}
	else
	{
		DevilBall->ChangeAnimation("Orb_Bubble_Parry");
	}
	Super::Tick(_DeltaTime);
	Delay -= _DeltaTime;
	if (Delay < 0)
	{
		Collisiongather(_DeltaTime);
		PlayerCollisionCheck();
	}
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

void ADevilBall::PlayerCollisionCheck()
{
	DevilBallCol->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		Player->State.ChangeState("hit");

	});
}

