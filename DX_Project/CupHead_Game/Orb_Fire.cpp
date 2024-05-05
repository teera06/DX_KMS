#include "PreCompile.h"

#include "Orb_Fire.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

AOrb_Fire::AOrb_Fire()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Orb_Fire");

	Orb_Fire = CreateDefaultSubObject<USpriteRenderer>("Orb_Fire");

	Orb_Fire->SetupAttachment(Root);

	Fire1Collision = CreateDefaultSubObject<UCollision>("Fire1Collision");
	Fire1Collision->SetupAttachment(Root);
	Fire1Collision->SetScale(FVector(70.0f, 70.0f, 100.0f));
	Fire1Collision->SetCollisionGroup(ECollisionOrder::Orb_Fire1);
	Fire1Collision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

AOrb_Fire::~AOrb_Fire()
{
}

void AOrb_Fire::BeginPlay()
{

	Super::BeginPlay();
	Orb_Fire->SetOrder(ERenderOrder::skilleffect);
	Orb_Fire->SetSprite("devil_ph1_fire_spark_0001.png");
	Orb_Fire->SetSamplering(ETextureSampling::LINEAR);
	Orb_Fire->SetAutoSize(1.0f, true);
	
	Orb_Fire->CreateAnimation("OrbsSpawn_Fire", "OrbsSpawn_Fire", 0.1f);
	Orb_Fire->CreateAnimation("Orb_Fire", "Orb_Fire", 0.1f);

	Orb_Fire->CreateAnimation("OrbsSpawn_Fire_Parry", "OrbsSpawn_Fire_Parry", 0.1f);
	Orb_Fire->CreateAnimation("Orb_Fire_Parry", "Orb_Fire_Parry", 0.1f);
	
	//Orb_Fire->ChangeAnimation("OrbsSpawn_Fire");
}

void AOrb_Fire::Tick(float _DeltaTime)
{

	if (false == StartAni)
	{
		StartAni = true;
		if (false == ParryCheck)
		{
			Orb_Fire->ChangeAnimation("OrbsSpawn_Fire");
		}
		else
		{
			Orb_Fire->ChangeAnimation("OrbsSpawn_Fire_Parry");
		}

	}


	Super::Tick(_DeltaTime);

	

	if (true == Orb_Fire->IsCurAnimationEnd() && true==StartAni)
	{
		EndAni = true;

		if (false == ParryCheck)
		{
			Orb_Fire->ChangeAnimation("Orb_Fire");
		}
		else
		{
			Orb_Fire->ChangeAnimation("Orb_Fire_Parry");
		}
	}

	if (true == EndAni)
	{
		Delay -= _DeltaTime;
		if (Delay < 0 && false == att)
		{
			att = true;
		}

		if (true == att)
		{
			if (false == OneCheck)
			{
				PlayerPos = APlay_Cuphead::GetPlayerPos();
				OneCheck = true;
				return;
			}

			CalDir(_DeltaTime);
		}
	}
	
}

void AOrb_Fire::CalDir(float _DeltaTime)
{
	if (false == OneCheck2)
	{
		FVector CoinPos = GetActorLocation();

		FVector Move = PlayerPos - CoinPos;

		MoveNorMalize = Move.Normalize3DReturn();

		OneCheck2 = true;
	}


	AddActorLocation(MoveNorMalize * Speed * _DeltaTime);
	Collisiongather();
}

void AOrb_Fire::Collisiongather()
{
	Fire1Collision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		Player->AddActorLocation(FVector::Up * 100.0f);
		Player->State.ChangeState("hit");

		Destroy();
	});

	

	if (GetActorLocation().iX() <= -800 || GetActorLocation().iX() >= 800) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}

	if (GetActorLocation().iY() >= 500 || GetActorLocation().iY() <= -500)
	{
		Destroy();
	}
}
