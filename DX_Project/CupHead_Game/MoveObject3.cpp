#include "PreCompile.h"
#include "MoveObject3.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"
AMoveObject3::AMoveObject3()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("smallskill");

	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectRender->SetupAttachment(Root);

	ObjectFront = CreateDefaultSubObject<USpriteRenderer>("ObjectFront");

	ObjectFront->SetupAttachment(Root);

	ObjectBallRender = CreateDefaultSubObject<USpriteRenderer>("ObjectBallRender");

	ObjectBallRender->SetupAttachment(Root);

	ObjectRender->SetPivot(EPivot::BOT);
	ObjectFront->SetPivot(EPivot::BOT);
	ObjectFront->AddPosition(FVector(1.2f, 3.5f, 0.0f));


	TopCollision = CreateDefaultSubObject<UCollision>("BoxCollision ");
	TopCollision->SetupAttachment(Root);
	TopCollision->AddPosition(FVector(0.0f, 120.0f, 0.0f));
	TopCollision->SetScale(FVector(130.0f, 5.0f, 100.0f));

	TopCollision->SetCollisionGroup(ECollisionOrder::Boss1Top);
	TopCollision->SetCollisionType(ECollisionType::RotRect);

	BoxCollision = CreateDefaultSubObject<UCollision>("BoxCollision ");
	BoxCollision->SetupAttachment(Root);
	BoxCollision->AddPosition(FVector(0.0f, 60.0f, 0.0f));
	BoxCollision->SetScale(FVector(160.0f, 100.0f, 100.0f));

	BoxCollision->SetCollisionGroup(ECollisionOrder::Boss1Object3);
	BoxCollision->SetCollisionType(ECollisionType::RotRect);

	ballCollision = CreateDefaultSubObject<UCollision>("ballCollision");
	ballCollision->SetupAttachment(Root);
	ballCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));

	ballCollision->SetCollisionGroup(ECollisionOrder::ball);
	ballCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

AMoveObject3::~AMoveObject3()
{
	LoopSound.Off();
}

void AMoveObject3::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(400.0f, -200.0f, 0.0f));
	SetActorLocation(FVector(400.0f, -200.0f, 0.0f));

	ObjectRender->SetOrder(ERenderOrder::Object1Back);
	ObjectRender->SetSprite("tallfrog_slotman_platform_bison_0001.png");
	ObjectRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectRender->SetAutoSize(1.0f, true);

	ObjectBallRender->SetOrder(ERenderOrder::Object3Ball);
	ObjectBallRender->SetSprite("tallfrog_slotman_platform_tiger_bullet_0001.png");
	ObjectBallRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectBallRender->SetAutoSize(1.0f, true);

	ObjectFront->SetOrder(ERenderOrder::MidObject);
	ObjectFront->SetSprite("tallfrog_slotman_platform_tiger_top_0001.png");
	ObjectFront->SetSamplering(ETextureSampling::LINEAR);
	ObjectFront->SetAutoSize(1.0f, true);
	
	ObjectRender->CreateAnimation("Object3", "Object3", 0.092f);
	ObjectBallRender->CreateAnimation("Object3Ball", "Object3Ball", 0.1f);
	ObjectFront->CreateAnimation("Object3Front", "Object3Front", 0.1f);
	

	ObjectBallRender->ChangeAnimation("Object3Ball");
	ObjectRender->ChangeAnimation("Object3");
	ObjectFront->ChangeAnimation("Object3Front");


	LoopSound = UEngineSound::SoundPlay("frogs_platform_loop_01.wav");
	LoopSound.Loop();
	LoopSound.Off();
}

void AMoveObject3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
	BallMove(_DeltaTime);
	PlayerCollisionCheck();
}

void AMoveObject3::Collisiongather(float _DeltaTime)
{
	LoopSound.On();

	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		LoopSound.Off();
		Destroy();
	}

	DownPower = FVector::Down * 500.0f;

	if (GetActorLocation().iY() <= -300)
	{
		DownPower = FVector::Zero;
	}

	AddActorLocation(DownPower * _DeltaTime);
}

void AMoveObject3::BallMove(float _DeltaTime)
{
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // 중력은 계속 가해진다.

	if (ObjectBallRender->GetWorldPosition().iY() <= -250)
	{
		UEngineSound::SoundPlay("frogs_ball_platform_ball_launch_01.wav");
		GravityVector = FVector::Zero;
	}
	ObjectBallRender->AddPosition((JumpVector +GravityVector) * _DeltaTime);
	ballCollision->AddPosition((JumpVector + GravityVector) * _DeltaTime);
}

void AMoveObject3::PlayerCollisionCheck()
{
	ballCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

			Player->State.ChangeState("hit");

		});

	BoxCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

			Player->State.ChangeState("hit");

		});
}
