#include "PreCompile.h"
#include "MoveObject2.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

AMoveObject2::AMoveObject2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("smallskill");

	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectRender->SetupAttachment(Root);

	ObjectRender->SetPivot(EPivot::BOT);
	TopCollision = CreateDefaultSubObject<UCollision>("TopCollision ");
	TopCollision->SetupAttachment(Root);
	TopCollision->AddPosition(FVector(0.0f, 110.0f, 0.0f));
	TopCollision->SetScale(FVector(130.0f, 5.0f, 100.0f));
	
	TopCollision->SetCollisionGroup(ECollisionOrder::Boss1Top);
	TopCollision->SetCollisionType(ECollisionType::RotRect);

	LRCollision = CreateDefaultSubObject<UCollision>("LRCollision");
	LRCollision->SetupAttachment(Root);
	LRCollision->AddPosition(FVector(0.0f, 60.0f, 0.0f));
	LRCollision->SetScale(FVector(160.0f, 100.0f, 100.0f));
	
	LRCollision->SetCollisionGroup(ECollisionOrder::Boss1LR);
	LRCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

AMoveObject2::~AMoveObject2()
{
}

void AMoveObject2::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(400.0f, -200.0f, 0.0f));
	//SetActorLocation(FVector(0.0f, -200.0f, 0.0f));

	ObjectRender->SetOrder(ERenderOrder::skilleffect);
	ObjectRender->SetSprite("tallfrog_slotman_platform_bison_0001.png");
	ObjectRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectRender->SetAutoSize(1.0f, true);
	
	
	
	ObjectRender->CreateAnimation("Object2", "Object2", 0.1f);
	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	ObjectRender->ChangeAnimation("Object2");
}

void AMoveObject2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	PlayerCollision();
	AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
}


void AMoveObject2::PlayerCollision()
{
	LRCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		Player->State.ChangeState("hit");
	});
}

void AMoveObject2::Collisiongather(float _DeltaTime)
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
