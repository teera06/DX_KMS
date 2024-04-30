#include "PreCompile.h"
#include "MoveObject1.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

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
	TopCollision->AddPosition(FVector(0.0f, 110.0f, 0.0f));
	TopCollision->SetScale(FVector(160.0f, 5.0f, 100.0f));

	TopCollision->SetCollisionGroup(ECollisionOrder::Boss1Top);
	TopCollision->SetCollisionType(ECollisionType::RotRect);

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
	ObjectFront->CreateAnimation("Object1Front", "Object1Front", 0.1f);

	Fire->CreateAnimation("Object1SmallFire", "Object1SmallFire", 0.1f);
	Fire->CreateAnimation("Object1BigFire", "Object1BigFire", 0.1f,false);

	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);
	ObjectFront->ChangeAnimation("Object1Front");
	ObjectRender->ChangeAnimation("Object1");
	Fire->ChangeAnimation("Object1SmallFire");
}

void AMoveObject1::Tick(float _DeltaTime)
{
	if (false == OneCheck)
	{
		if (UpDownSet.iY() > 0)
		{
			ObjectFront->AddPosition(FVector(1.2f, 3.5f, 0.0f));
			
			Fire->SetDir(EEngineDir::Up);
		
			Fire->SetPosition(FVector(0.0f, 150.0f, 0.0f));
			TopCollision->SetActive(false);
		}
		else
		{
			ObjectFront->AddPosition(FVector(1.2f, 3.5f, 0.0f));
			
			Fire->SetDir(EEngineDir::Down);
			
			Fire->SetPosition(FVector(0.0f, -0.0f, 0.0f));
		}

		OneCheck = true;
	}


	Super::Tick(_DeltaTime);
	AddActorLocation(FVector::Left * Speed * _DeltaTime);
	Collisiongather(_DeltaTime);
}

void AMoveObject1::Collisiongather(float _DeltaTime)
{
	if (GetActorLocation().iX() <= -50 && false==changeFire)
	{
		Fire->ChangeAnimation("Object1BigFire");

		Fire->SetFrameCallback("Object1BigFire", 2, [=] {ChangeFirePos(); });
		changeFire = true;
	}

	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}

	UpPower = FVector::Up * 500.0f;

	if (GetActorLocation().iY() >= -140)
	{
		UpPower = FVector::Zero;
	}

	AddActorLocation(UpPower * _DeltaTime);
}

void AMoveObject1::ChangeFirePos()
{
	if (UpDownSet.iY() > 0)
	{
		Fire->AddPosition(FVector(0.0f, 310.0f, 0.0f));
	}
	else
	{
		Fire->AddPosition(FVector(0.0f, -310.0f, 0.0f));
	}
}
