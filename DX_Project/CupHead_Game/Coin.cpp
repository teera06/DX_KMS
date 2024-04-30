#include "PreCompile.h"
#include "Coin.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

ACoin::ACoin()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ball");

	CoinRender = CreateDefaultSubObject<USpriteRenderer>("coin");

	CoinRender->SetupAttachment(Root);

	CoinCollision = CreateDefaultSubObject<UCollision>("ballCollision");
	CoinCollision->SetupAttachment(Root);
	CoinCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));

	CoinCollision->SetCollisionGroup(ECollisionOrder::Coin);
	CoinCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

ACoin::~ACoin()
{
}

void ACoin::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(350.0f,220.0f, 0.0f));

	CoinRender->SetOrder(ERenderOrder::skilleffect);
	CoinRender->SetSprite("tallfrog_slotman_coin_0001.png");
	CoinRender->SetSamplering(ETextureSampling::LINEAR);
	CoinRender->SetAutoSize(1.0f, true);

	//CoinRender->SetDir(EEngineDir::Left);

	CoinRender->CreateAnimation("Coin", "Coin", 0.1f);

	CoinRender->ChangeAnimation("Coin");

}

void ACoin::Tick(float _DeltaTime)
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

void ACoin::CalDir(float _DeltaTime)
{

	if (false == OneCheck2)
	{
		FVector CoinPos = GetActorLocation();

		FVector Move = PlayerPos - CoinPos;

		MoveNorMalize = Move.Normalize3DReturn();

		OneCheck2 = true;
	}
	

	AddActorLocation(MoveNorMalize * Speed * _DeltaTime);
	CollisionCheck();
}

void ACoin::CollisionCheck()
{
	if (GetActorLocation().iY() <= -350)
	{
		Destroy();
	}

	CoinCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		Player->State.ChangeState("hit");
		Destroy();
	});
}
