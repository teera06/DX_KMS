#include "PreCompile.h"
#include "Play_Cuphead.h"
#include "ContentsENum.h"
#include <EngineCore/SpriteRenderer.h>

#include <EngineCore/Collision.h>

#include <EngineCore/DefaultSceneComponent.h>

FVector APlay_Cuphead::PlayerPos = FVector::Zero;

APlay_Cuphead::APlay_Cuphead()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");

	PlayCuphead = CreateDefaultSubObject<USpriteRenderer>("PlayCuphead");

	PlayCuphead->SetupAttachment(Root);
	PlayCuphead->SetPivot(EPivot::BOT);

	BulletStart = CreateDefaultSubObject<USpriteRenderer>("BulletStart");

	BulletStart->SetupAttachment(Root);

	PlayerCollision = CreateDefaultSubObject<UCollision>("Collision");
	PlayerCollision->SetupAttachment(Root);
	PlayerCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));
	PlayerCollision->SetScale(FVector(70.0f, 70.0f, 100.0f));
	//PlayerCollision은 무조건 오더를 지정해줘야 한다.
	PlayerCollision->SetCollisionGroup(ECollisionOrder::Player);
	PlayerCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
	PlayCuphead->SetOrder(ERenderOrder::Cuphead);
	PlayCuphead->SetSprite("cuphead_idle_0001.png");
	PlayCuphead->SetSamplering(ETextureSampling::LINEAR);

	BulletStart->SetOrder(ERenderOrder::skilleffect);
	BulletStart->SetSprite("Spawn01.png");
	BulletStart->SetSamplering(ETextureSampling::LINEAR);


	InputOn();

}

APlay_Cuphead::~APlay_Cuphead()
{
}


void APlay_Cuphead::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
	SetActorLocation(FVector(-400.0f, -250.0f, 0.0f));



	PlayCuphead->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	PlayCuphead->CreateAnimation("Intro", "Intro", 0.05f);
	PlayCuphead->CreateAnimation("Idle", "Idle", 0.05f);

	PlayCuphead->CreateAnimation("Run", "Run", 0.05f);
	PlayCuphead->CreateAnimation("Dash", "Dash", 0.05f);
	PlayCuphead->CreateAnimation("Duck", "Duck", 0.05f,false);
	PlayCuphead->CreateAnimation("Shoot_Straight", "Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Run_Shoot_Straight", "Run_Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Run_Shoot_DiagonalUp", "Run_Shoot_DiagonalUp", 0.05f);
	PlayCuphead->CreateAnimation("Duck_Shoot", "Duck_Shoot", 0.05f);
	PlayCuphead->CreateAnimation("Shoot_Up", "Shoot_Up", 0.05f);
	PlayCuphead->CreateAnimation("Aim_Up", "Aim_Up", 0.05f);
	PlayCuphead->CreateAnimation("Jump", "Jump", 0.05f);
	PlayCuphead->CreateAnimation("Parry", "Parry", 0.03f, false);
	PlayCuphead->CreateAnimation("Scared", "Scared", 0.075f, false);

	BulletStart->CreateAnimation("Peashot_Spawn", "Peashot_Spawn", 0.05f);

	BulletStart->ChangeAnimation("Peashot_Spawn");


	StateInit();
	PlayCuphead->SetAutoSize(1.0f, true);
	BulletStart->SetAutoSize(1.0f, true);
	Dir = EDir::Right;
	
	BulletStart->SetActive(false);
	//PlayCuphead->ChangeAnimation("Idle");
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
	State.Update(_DeltaTime);

	PlayerPos = GetActorLocation();

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

	PlayerCollision->CollisionEnter(ECollisionOrder::Boss1Monster1, [=](std::shared_ptr<UCollision> _Collison)
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



