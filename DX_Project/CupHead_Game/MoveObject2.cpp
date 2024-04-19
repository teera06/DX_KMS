#include "PreCompile.h"
#include "MoveObject2.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
AMoveObject2::AMoveObject2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("smallskill");

	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectRender->SetupAttachment(Root);

	ObjectFront = CreateDefaultSubObject<USpriteRenderer>("ObjectFront");

	ObjectFront->SetupAttachment(Root);

	ObjectBallRender = CreateDefaultSubObject<USpriteRenderer>("ObjectBallRender");

	ObjectRender->SetupAttachment(Root);

	ObjectRender->SetPivot(EPivot::BOT);
	ObjectFront->SetPivot(EPivot::BOT);
	ObjectFront->AddPosition(FVector(1.2f, 3.5f, 0.0f));
	BoxCollision = CreateDefaultSubObject<UCollision>("BoxCollision ");
	BoxCollision->SetupAttachment(Root);
	BoxCollision->AddPosition(FVector(0.0f, 110.0f, 0.0f));
	BoxCollision->SetScale(FVector(160.0f, 20.0f, 100.0f));

	BoxCollision->SetCollisionGroup(ECollisionOrder::Boss1Object3);
	BoxCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

AMoveObject2::~AMoveObject2()
{
}

void AMoveObject2::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(400.0f, -200.0f, 0.0f));
	SetActorLocation(FVector(0.0f, -200.0f, 0.0f));

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
	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	ObjectBallRender->ChangeAnimation("Object3Ball");
	ObjectRender->ChangeAnimation("Object3");
	ObjectFront->ChangeAnimation("Object3Front");
}

void AMoveObject2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	//AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
	BallMove(_DeltaTime);
}

void AMoveObject2::Collisiongather(float _DeltaTime)
{
}

void AMoveObject2::BallMove(float _DeltaTime)
{
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // 중력은 계속 가해진다.

	if (ObjectBallRender->GetLocalPosition().iY() <= -250)
	{
		GravityVector = FVector::Zero;
	}
	ObjectBallRender->AddPosition((JumpVector +GravityVector) * _DeltaTime);
}
