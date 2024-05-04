#include "PreCompile.h"
#include "ball.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"


Aball::Aball()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ball");

	ballRender = CreateDefaultSubObject<USpriteRenderer>("ballRender");

	ballRender->SetupAttachment(Root);

	FxRender = CreateDefaultSubObject<USpriteRenderer>("FxRender");
	
	FxRender->SetupAttachment(Root);

	ballCollision = CreateDefaultSubObject<UCollision>("ballCollision");
	ballCollision->SetupAttachment(Root);
	ballCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));

	ballCollision->SetCollisionGroup(ECollisionOrder::ball);
	ballCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

Aball::~Aball()
{
}

void Aball::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(-300.0f, -50.0f, 0.0f));

	ballRender->SetOrder(ERenderOrder::skilleffect);
	ballRender->SetSprite("shorfrog_clap_ball_0001.png");
	ballRender->SetSamplering(ETextureSampling::LINEAR);
	ballRender->SetAutoSize(1.0f, true);
	
	ballRender->SetRotationDeg(FVector(0.0f, 0.0f, 35.0f));

	ballRender->SetDir(EEngineDir::Left);
	
	ballRender->CreateAnimation("Ball", "Ball", 0.1f);
	
	ballRender->ChangeAnimation("Ball");

	FxRender->SetOrder(ERenderOrder::skilleffect);
	FxRender->SetSprite("shorfrog_clap_fx_0001.png");
	FxRender->SetSamplering(ETextureSampling::LINEAR);
	FxRender->SetAutoSize(1.0f, true);
	
	FxRender->SetPosition(FVector(0.0f, 70.0f, 0.0f));
	FxRender->SetRotationDeg(FVector(0.0f, 0.0f, 35.0f));
	

	FxRender->CreateAnimation("FX", "FX", 0.035f,true);
	
	FxRender->ChangeAnimation("FX");

	FxRender->SetActive(false);

}

void Aball::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == OneCheck)
	{
		OneCheck = true;
		if (StartPos.Y > 0)
		{
			UpDown = false;
		}
		else
		{
			UpDown = true;
		}
	}

	if (false==UpDown)
	{
		CollisiongatherUp(_DeltaTime);
	}
	else
	{
		CollisiongatherDown(_DeltaTime);
	}

	PlayerCollisionCheck();
	
}

void Aball::CollisiongatherUp(float _DeltaTime)
{
	if (GetActorLocation().iX() >= 640)
	{
		Destroy();
	}


	if (GetActorLocation().iY() <= -300 || GetActorLocation().iY() >= 360)
	{
		FxRender->SetActive(true);
		FxRender->ChangeAnimation("FX");
		StartPos.Y *= -1.0f;
		RenderRot *= -1.0f;
		Renderpox *= -1.0f;
	}
	else
	{
		if (true == FxRender->IsActive() && true == FxRender->IsCurAnimationEnd())
		{
			FxRender->SetActive(false);
		}
	}

	FxRender->SetPosition(Renderpox*-1.0f);
	FxRender->SetRotationDeg(RenderRot*-1.0f);
	ballRender->SetRotationDeg(RenderRot);
	AddActorLocation(StartPos *Speed*_DeltaTime);
}

void Aball::CollisiongatherDown(float _DeltaTime)
{
	if (GetActorLocation().iX() >= 640)
	{
		Destroy();
	}


	if (GetActorLocation().iY() <= -300 || GetActorLocation().iY() >= 360)
	{
		FxRender->SetActive(true);
		FxRender->ChangeAnimation("FX");
		StartPos.Y *= -1.0f;
		RenderRot *= -1.0f;
		Renderpox *= -1.0f;
	}
	else
	{
		if (true == FxRender->IsActive() && true == FxRender->IsCurAnimationEnd())
		{
			FxRender->SetActive(false);
		}
	}

	FxRender->SetPosition(Renderpox * 1.0f);
	FxRender->SetRotationDeg(RenderRot * 1.0f);
	ballRender->SetRotationDeg(RenderRot*-1.0f);
	AddActorLocation(StartPos * Speed * _DeltaTime);
}

void Aball::PlayerCollisionCheck()
{
	ballCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

			Player->State.ChangeState("hit");

		});
}
