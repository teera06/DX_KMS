#include "PreCompile.h"
#include "MoveObject1.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

AMoveObject1::AMoveObject1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("smallskill");

	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectRender->SetupAttachment(Root);

	ObjectFront = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectFront->SetupAttachment(Root);

	Fire = CreateDefaultSubObject<USpriteRenderer>("Fire");

	Fire->SetupAttachment(Root);

	ObjectRender->SetPivot(EPivot::BOT);
	ObjectFront->SetPivot(EPivot::BOT);
	TopCollision = CreateDefaultSubObject<UCollision>("TopCollision ");
	TopCollision->SetupAttachment(Root);
	TopCollision->AddPosition(FVector(0.0f, 120.0f, 0.0f));
	TopCollision->SetScale(FVector(130.0f, 5.0f, 100.0f));

	TopCollision->SetCollisionGroup(ECollisionOrder::Boss1Top);
	TopCollision->SetCollisionType(ECollisionType::RotRect);

	BodyCollision = CreateDefaultSubObject<UCollision>("TopCollision ");
	BodyCollision->SetupAttachment(Root);
	BodyCollision->AddPosition(FVector(0.0f, 60.0f, 0.0f));
	BodyCollision->SetScale(FVector(160.0f, 100.0f, 100.0f));
	BodyCollision->SetCollisionGroup(ECollisionOrder::Boss1LR);
	BodyCollision->SetCollisionType(ECollisionType::RotRect);

	FireCollision = CreateDefaultSubObject<UCollision>("TopCollision ");
	FireCollision->SetupAttachment(Root);
	//FireCollision->AddPosition(FVector(0.0f, 60.0f, 0.0f));
	FireCollision->SetScale(FVector(50.0f, 400.0f, 100.0f));
	FireCollision->SetCollisionGroup(ECollisionOrder::Boss1Fire);
	FireCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

AMoveObject1::~AMoveObject1()
{
}

void AMoveObject1::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(400.0f, -200.0f, 0.0f));
	SetActorLocation(FVector(400.0f, -200.0f, 0.0f));

	ObjectRender->SetOrder(ERenderOrder::Object1Back);
	ObjectRender->SetSprite("tallfrog_slotman_platform_bison_0001.png");
	ObjectRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectRender->SetAutoSize(1.0f, true);
	ObjectRender->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	ObjectFront->SetOrder(ERenderOrder::MidObject);
	ObjectFront->SetSprite("tallfrog_slotman_platform_bison_top_0001.png");
	ObjectFront->SetSamplering(ETextureSampling::LINEAR);
	ObjectFront->SetAutoSize(1.0f, true);
	ObjectFront->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	Fire->SetOrder(ERenderOrder::Fire);
	Fire->SetSprite("tallfrog_slotman_platform_bison_flame_sm_0001.png");
	Fire->SetSamplering(ETextureSampling::LINEAR);
	Fire->SetAutoSize(1.0f, true);
	Fire->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));


	ObjectRender->CreateAnimation("Object1", "Object1", 0.092f);
	ObjectFront->CreateAnimation("Object1Front", "Object1Front", 0.092f);

	Fire->CreateAnimation("Object1SmallFire", "Object1SmallFire", 0.1f);
	Fire->CreateAnimation("Object1BigFire", "Object1BigFire", 0.1f,false);

	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);
	ObjectFront->ChangeAnimation("Object1Front");
	ObjectRender->ChangeAnimation("Object1");
	Fire->ChangeAnimation("Object1SmallFire");

	FireCollision->SetActive(false);

	LoopSound = UEngineSound::SoundPlay("frogs_platform_loop_01.wav");
	LoopSound.Loop();
	LoopSound.Off();
}

void AMoveObject1::Tick(float _DeltaTime)
{
	if (false == OneCheck)
	{
		ObjectFront->AddPosition(FVector(1.2f, 3.5f, 0.0f));
		if (UpDownSet.iY() > 0)
		{
			Fire->SetDir(EEngineDir::Up);
		
			Fire->SetPosition(FVector(0.0f, 140.0f, 0.0f));
			TopCollision->SetActive(false);
		}
		else
		{
			Fire->SetDir(EEngineDir::Down);
			
			Fire->SetPosition(FVector(0.0f, -10.0f, 0.0f));
		}

		OneCheck = true;
	}


	Super::Tick(_DeltaTime);
	PlayerCollision();
	AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
}

void AMoveObject1::PlayerCollision()
{
	BodyCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);
		
		Player->AddActorLocation(FVector::Up * 100.0f);
		Player->State.ChangeState("hit");
	});

	FireCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

			Player->AddActorLocation(FVector::Up * 100.0f);
			Player->State.ChangeState("hit");
		});
}

void AMoveObject1::Collisiongather(float _DeltaTime)
{
	LoopSound.On();
	if (GetActorLocation().iX() <= -50 && false==changeFire)
	{
		UEngineSound::SoundPlay("frogs_flame_platform_fire_burst_01.wav");
		Fire->ChangeAnimation("Object1BigFire");

		Fire->SetFrameCallback("Object1BigFire", 1, [=] {ChangeFirePos(); });
		changeFire = true;
	}

	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		LoopSound.Off();
		Destroy();
	}

	UpPower = FVector::Up * 500.0f;

	if (GetActorLocation().iY() >= -130)
	{
		UpPower = FVector::Zero;
	}

	AddActorLocation(UpPower * _DeltaTime);
}

void AMoveObject1::ChangeFirePos()
{
	FireCollision->SetActive(true);

	if (UpDownSet.iY() > 0)
	{
		Fire->AddPosition(FVector(0.0f, 305.0f, 0.0f));
		FireCollision->SetPosition(FVector(0.0f, 280.0f, 0.0f));
	}
	else
	{
		Fire->AddPosition(FVector(0.0f, -305.0f, 0.0f));
		FireCollision->SetPosition(FVector(0.0f, -120.0f, 0.0f));
	}
}
