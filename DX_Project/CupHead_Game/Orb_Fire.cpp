#include "PreCompile.h"

#include "Orb_Fire.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

int AOrb_Fire::AttOrder = 0;

AOrb_Fire::AOrb_Fire()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Orb_Fire");

	Orb_Fire = CreateDefaultSubObject<USpriteRenderer>("Orb_Fire");

	Orb_Fire->SetupAttachment(Root);


	SetRoot(Root);
}

AOrb_Fire::~AOrb_Fire()
{
}

void AOrb_Fire::BeginPlay()
{

	Super::BeginPlay();
	Orb_Fire->SetOrder(ERenderOrder::skilleffect);
	Orb_Fire->SetSprite("devil_ph1_fire_spark_0001.png");
	Orb_Fire->SetSamplering(ETextureSampling::LINEAR);
	Orb_Fire->SetAutoSize(1.0f, true);
	
	Orb_Fire->CreateAnimation("OrbsSpawn_Fire", "OrbsSpawn_Fire", 0.1f);
	Orb_Fire->CreateAnimation("Orb_Fire", "Orb_Fire", 0.1f);
	
	Orb_Fire->ChangeAnimation("Orb_Fire");
}

void AOrb_Fire::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == OneCheck)
	{
		PlayerPos = APlay_Cuphead::GetPlayerPos();
		OneCheck = true;
		return;
	}
	CalDir(_DeltaTime);
}

void AOrb_Fire::CalDir(float _DeltaTime)
{
	if (false == OneCheck2)
	{
		FVector CoinPos = GetActorLocation();

		FVector Move = PlayerPos - CoinPos;

		MoveNorMalize = Move.Normalize3DReturn();

		OneCheck2 = true;
	}


	AddActorLocation(MoveNorMalize * Speed * _DeltaTime);
	Collisiongather();
}

void AOrb_Fire::Collisiongather()
{
	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600 || GetActorLocation().iY() >= 360 || GetActorLocation().iX() <= -360) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}
