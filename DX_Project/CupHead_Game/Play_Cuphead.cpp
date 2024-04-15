#include "PreCompile.h"
#include "Play_Cuphead.h"
#include "ContentsENum.h"
#include <EngineCore/SpriteRenderer.h>

#include <EngineCore/Collision.h>

#include <EngineCore/DefaultSceneComponent.h>

APlay_Cuphead::APlay_Cuphead()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");

	PlayCuphead = CreateDefaultSubObject<USpriteRenderer>("WorldPlayer");

	PlayCuphead->SetupAttachment(Root);
	PlayCuphead->SetPivot(EPivot::BOT);

	Collision = CreateDefaultSubObject<UCollision>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	Collision->SetCollisionGroup(ECollisionOrder::Player);
	Collision->SetCollisionType(ECollisionType::Rect);


	SetRoot(Root);
	PlayCuphead->SetOrder(ERenderOrder::Cuphead);
	PlayCuphead->SetSprite("cuphead_idle_0001.png");
	PlayCuphead->SetSamplering(ETextureSampling::LINEAR);

	InputOn();

}

APlay_Cuphead::~APlay_Cuphead()
{
}

void APlay_Cuphead::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
	SetActorLocation(FVector(-400.0f, -250.0f, -50.0f));
	PlayCuphead->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	PlayCuphead->CreateAnimation("Idle", "Idle", 0.05f);

	PlayCuphead->CreateAnimation("Run", "Run", 0.05f);
	PlayCuphead->CreateAnimation("Dash", "Dash", 0.05f);
	PlayCuphead->CreateAnimation("Duck", "Duck", 0.05f,false);
	PlayCuphead->CreateAnimation("Shoot_Straight", "Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Run_Shoot_Straight", "Run_Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Duck_Shoot", "Duck_Shoot", 0.05f);
	PlayCuphead->CreateAnimation("Jump", "Jump", 0.05f);
	//PlayCuphead->CreateAnimation("Duck", "Duck", 0.05f, false);

	StateInit();
	PlayCuphead->SetAutoSize(1.0f, true);
	Dir = EDir::Right;
	//PlayCuphead->ChangeAnimation("Idle");
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
	State.Update(_DeltaTime);


	// 나는 APlayer 인데
	// 	Collision->SetCollisionGroup(ECollisionOrder::Player);
	// 상대 ECollisionOrder::Monster

	//if (Collision->Collision(ECollisionOrder::Monster))
	//{

	//}


	//Collision->CollisionStay(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
	//	{
	//		int a = 0;

	//		// _Collison[0]->GetActor()->Destroy();
	//	}
	//);

	Collision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
	{
	
	//_Collison->GetActor()->Destroy();
	});



	//Collision->CollisionExit(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
	//{
		//int a = 0;

		// _Collison[0]->GetActor()->Destroy();
	//}
	//);

	DebugMessageFunction();
}




