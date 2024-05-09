#include "PreCompile.h"
#include "DevilTear.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

ADevilTear::ADevilTear()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Tear");
	Tear = CreateDefaultSubObject<USpriteRenderer>("Tear");
	Tear->SetupAttachment(Root);

	Tear->SetOrder(ERenderOrder::backSkill);
	Tear->SetSprite("devil_ph3_tear_drop_bb_0001.png");
	Tear->SetSamplering(ETextureSampling::LINEAR);
	Tear->SetAutoSize(0.85f, true);
	Tear->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	TearCollision  = CreateDefaultSubObject<UCollision>("TearCollision");
	TearCollision ->SetupAttachment(Root);

	TearCollision ->SetScale(FVector(50.0f, 60.0f, 100.0f));

	TearCollision ->SetCollisionGroup(ECollisionOrder::Tear);
	TearCollision ->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

ADevilTear::~ADevilTear()
{
}

void ADevilTear::BeginPlay()
{
	Super::BeginPlay();


	Tear->CreateAnimation("DevilTear1", "DevilTear1", 0.075f);
	
	Tear->ChangeAnimation("DevilTear1");
}

void ADevilTear::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	GroundCheck(_DeltaTime);
	PlayerCollisionCheck();
}

void ADevilTear::PlayerCollisionCheck()
{
	TearCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		if (nullptr != Player)
		{
			Player->AddActorLocation(FVector::Up * 100.0f);
			Player->State.ChangeState("hit");
		}
	});
}

void ADevilTear::GroundCheck(float _DeltaTime)
{
	GravityVector += FVector::Down * Speed * _DeltaTime;

	AddActorLocation(GravityVector * _DeltaTime);

	if (GetActorLocation().iY() <= -300)
	{
		Destroy();
	}
}
