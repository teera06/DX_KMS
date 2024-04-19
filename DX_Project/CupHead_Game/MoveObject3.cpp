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

	ObjectFront = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectFront->SetupAttachment(Root);

	Fire = CreateDefaultSubObject<USpriteRenderer>("Fire");

	Fire->SetupAttachment(Root);

	ObjectRender->SetPivot(EPivot::BOT);
	ObjectFront->SetPivot(EPivot::BOT);
	ObjectFront->AddPosition(FVector(1.2f, 3.5f, 0.0f));
	TopCollision = CreateDefaultSubObject<UCollision>("TopCollision ");
	TopCollision->SetupAttachment(Root);
	TopCollision->AddPosition(FVector(0.0f, 110.0f, 0.0f));
	TopCollision->SetScale(FVector(160.0f, 20.0f, 100.0f));

	TopCollision->SetCollisionGroup(ECollisionOrder::Boss1Top);
	TopCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

AMoveObject3::~AMoveObject3()
{
}

void AMoveObject3::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(400.0f, -200.0f, 0.0f));
	SetActorLocation(FVector(100.0f, -200.0f, 0.0f));

	ObjectRender->SetOrder(ERenderOrder::Object1);
	ObjectRender->SetSprite("tallfrog_slotman_platform_bison_0001.png");
	ObjectRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectRender->SetAutoSize(1.0f, true);

	ObjectFront->SetOrder(ERenderOrder::ObjectFront);
	ObjectFront->SetSprite("tallfrog_slotman_platform_bison_top_0001.png");
	ObjectFront->SetSamplering(ETextureSampling::LINEAR);
	ObjectFront->SetAutoSize(1.0f, true);

	Fire->SetOrder(ERenderOrder::ObjectFront);
	Fire->SetSprite("tallfrog_slotman_platform_bison_top_0001.png");
	Fire->SetSamplering(ETextureSampling::LINEAR);
	Fire->SetAutoSize(1.0f, true);


	ObjectRender->CreateAnimation("Object1", "Object1", 0.1f);
	ObjectFront->CreateAnimation("Object1Front", "Object1Front", 0.1f);

	Fire->CreateAnimation("Object1SmallFire", "Object1SmallFire", 0.1f);
	Fire->CreateAnimation("Object1BigFire", "Object1BigFire", 0.1f);

	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);
	ObjectFront->ChangeAnimation("Object1Front");
	ObjectRender->ChangeAnimation("Object1");
}

void AMoveObject3::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	//AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
}

void AMoveObject3::Collisiongather(float _DeltaTime)
{
}
