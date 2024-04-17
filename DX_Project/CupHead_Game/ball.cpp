#include "PreCompile.h"
#include "ball.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"


Aball::Aball()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ball");

	ballRender = CreateDefaultSubObject<USpriteRenderer>("ballRender");

	ballRender->SetupAttachment(Root);

	ballCollision = CreateDefaultSubObject<UCollision>("ballCollision");
	ballCollision->SetupAttachment(Root);
	ballCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));

	ballCollision->SetCollisionGroup(ECollisionOrder::MonsterSkill);
	ballCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

Aball::~Aball()
{
}

void Aball::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(-300.0f, 0.0f, 0.0f));

	ballRender->SetOrder(ERenderOrder::skilleffect);
	ballRender->SetSprite("shorfrog_clap_ball_0001.png");
	ballRender->SetSamplering(ETextureSampling::LINEAR);
	ballRender->SetAutoSize(1.5f, true);
	
	ballRender->SetDir(EEngineDir::Left);
	
	ballRender->CreateAnimation("Ball", "Ball", 0.1f);
	
	ballRender->ChangeAnimation("Ball");

}

void Aball::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Collisiongather(_DeltaTime);
}

void Aball::Collisiongather(float _DeltaTime)
{
	if (GetActorLocation().iX() >= 640)
	{
		Destroy();
	}


	if (GetActorLocation().iY() <= -350 || GetActorLocation().iY() >= 360)
	{
		StartPos.Y *= -1.0f;
	}

	AddActorLocation(StartPos *Speed*_DeltaTime);
}