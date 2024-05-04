#include "PreCompile.h"
#include "MoveObject3.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
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

	BoxCollision = CreateDefaultSubObject<UCollision>("BoxCollision ");
	BoxCollision->SetupAttachment(Root);
	BoxCollision->AddPosition(FVector(0.0f, 110.0f, 0.0f));
	BoxCollision->SetScale(FVector(160.0f, 20.0f, 100.0f));

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
}

void AMoveObject3::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(400.0f, -200.0f, 0.0f));
	SetActorLocation(FVector(400.0f, -200.0f, 0.0f));

	ObjectRender->SetOrder(ERenderOrder::Object3);
	ObjectRender->SetSprite("tallfrog_slotman_platform_bison_0001.png");
	ObjectRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectRender->SetAutoSize(1.0f, true);

	ObjectBallRender->SetOrder(ERenderOrder::Object3Ball);
	ObjectBallRender->SetSprite("tallfrog_slotman_platform_tiger_bullet_0001.png");
	ObjectBallRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectBallRender->SetAutoSize(1.0f, true);

	ObjectFront->SetOrder(ERenderOrder::ObjectFront);
	ObjectFront->SetSprite("tallfrog_slotman_platform_tiger_top_0001.png");
	ObjectFront->SetSamplering(ETextureSampling::LINEAR);
	ObjectFront->SetAutoSize(1.0f, true);
	
	ObjectRender->CreateAnimation("Object3", "Object3", 0.092f);
	ObjectBallRender->CreateAnimation("Object3Ball", "Object3Ball", 0.1f);
	ObjectFront->CreateAnimation("Object3Front", "Object3Front", 0.1f);
	

	ObjectBallRender->ChangeAnimation("Object3Ball");
	ObjectRender->ChangeAnimation("Object3");
	ObjectFront->ChangeAnimation("Object3Front");
}

void AMoveObject3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
	BallMove(_DeltaTime);
}

void AMoveObject3::Collisiongather(float _DeltaTime)
{
	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
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
		GravityVector = FVector::Zero;
	}
	ObjectBallRender->AddPosition((JumpVector +GravityVector) * _DeltaTime);
	ballCollision->AddPosition((JumpVector + GravityVector) * _DeltaTime);
}
