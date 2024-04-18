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

	CoinRender = CreateDefaultSubObject<USpriteRenderer>("ballRender");

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

	SetActorLocation(FVector(-300.0f, 0.0f, 0.0f));

	CoinRender->SetOrder(ERenderOrder::skilleffect);
	CoinRender->SetSprite("tallfrog_slotman_coin_0001.png");
	CoinRender->SetSamplering(ETextureSampling::LINEAR);
	CoinRender->SetAutoSize(1.0f, true);

	//CoinRender->SetDir(EEngineDir::Left);

	CoinRender->CreateAnimation("Coin", "Coin", 0.1f);

	CoinRender->ChangeAnimation("Coin");

	PlayerPos = APlay_Cuphead::GetPlayerPos();
}

void ACoin::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CalDir(_DeltaTime);
}

void ACoin::CalDir(float _DeltaTime)
{
	FVector CoinPos = GetActorLocation();

	FVector Move = PlayerPos - CoinPos;

	FVector MoveNorMalize = Move.Normalize3DReturn();

	AddActorLocation(Move.Normalize3DReturn() * Speed * _DeltaTime);
}
