#include "PreCompile.h"
#include "MoveObject.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

AMoveObject::AMoveObject()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("smallskill");

	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectRender->SetupAttachment(Root);

	ObjectRender->SetPivot(EPivot::BOT);
	TopCollision = CreateDefaultSubObject<UCollision>("TopCollision ");
	TopCollision->SetupAttachment(Root);
	TopCollision->AddPosition(FVector(0.0f, 110.0f, 0.0f));
	TopCollision->SetScale(FVector(160.0f, 20.0f, 100.0f));
	
	TopCollision->SetCollisionGroup(ECollisionOrder::Boss1Top);
	TopCollision->SetCollisionType(ECollisionType::RotRect);

	LRCollision = CreateDefaultSubObject<UCollision>("LRCollision");
	LRCollision->SetupAttachment(Root);
	LRCollision->AddPosition(FVector(0.0f, 50.0f, 0.0f));
	LRCollision->SetScale(FVector(200.0f, 50.0f, 100.0f));
	
	LRCollision->SetCollisionGroup(ECollisionOrder::Boss1LR);
	LRCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

AMoveObject::~AMoveObject()
{
}

void AMoveObject::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(400.0f, -200.0f, 0.0f));
	//SetActorLocation(FVector(0.0f, -200.0f, 0.0f));

	ObjectRender->SetOrder(ERenderOrder::skilleffect);
	ObjectRender->SetSprite("tallfrog_slotman_platform_bison_0001.png");
	ObjectRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectRender->SetAutoSize(1.0f, true);
	
	
	ObjectRender->CreateAnimation("Object1", "Object1", 0.1f);
	ObjectRender->CreateAnimation("Object2", "Object2", 0.1f);
	ObjectRender->CreateAnimation("Object3", "Object3", 0.1f);
	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	ObjectRender->ChangeAnimation("Object2");
}

void AMoveObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
}

void AMoveObject::Collisiongather(float _DeltaTime)
{
	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600) // ��(Red)�� �浹�� ��� -> �����̴� �� 0
	{
		Destroy();
	}
}