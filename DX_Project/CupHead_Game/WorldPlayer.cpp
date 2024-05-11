#include "PreCompile.h"
#include "WorldPlayer.h"
#include "ContentsENum.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

FVector AWorldPlayer::PlayerPos = FVector::Zero;
AWorldPlayer::AWorldPlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("WorldMap");

	WorldPlayerRenderer = CreateDefaultSubObject<USpriteRenderer>("WorldPlayer");

	WorldPlayerRenderer->SetupAttachment(Root);

	AButton  = CreateDefaultSubObject<USpriteRenderer>("AButton ");

	AButton ->SetupAttachment(Root);

	Boss2title = CreateDefaultSubObject<USpriteRenderer>("Boss2title");

	Boss2title->SetupAttachment(Root);

	Boss1title = CreateDefaultSubObject<USpriteRenderer>("Boss1title");

	Boss1title->SetupAttachment(Root);


	PlayerCollision = CreateDefaultSubObject<UCollision>("Collision");
	PlayerCollision->SetupAttachment(Root);
	
	PlayerCollision->SetScale(FVector(70.0f, 100.0f, 100.0f));

	PlayerCollision->SetCollisionGroup(ECollisionOrder::Player);
	PlayerCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
	InputOn();
}

AWorldPlayer::~AWorldPlayer()
{
}

void AWorldPlayer::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(1600.0f/2.0f, -1600.0f/2.0f, 50.0f));

	AButton->SetOrder(ERenderOrder::Cuphead);
	AButton->SetSprite("PressSign.png");
	AButton->SetSamplering(ETextureSampling::LINEAR);
	AButton->SetPosition(FVector::Up * 55.0f);
	AButton->SetAutoSize(1.0f, true);

	Boss2title ->SetOrder(ERenderOrder::ScreenBar);
	Boss2title ->SetSprite("DevilC8.png");
	Boss2title ->SetSamplering(ETextureSampling::LINEAR);
	Boss2title ->SetAutoSize(1.0f, true);

	Boss1title->SetOrder(ERenderOrder::ScreenBar);
	Boss1title->SetSprite("SlotC8.png");
	Boss1title->SetSamplering(ETextureSampling::LINEAR);
	Boss1title->SetAutoSize(1.0f, true);


	WorldPlayerRenderer->SetOrder(ERenderOrder::Cuphead);
	WorldPlayerRenderer->SetSprite("WorldDiagonalIdle_01.png");
	WorldPlayerRenderer->SetSamplering(ETextureSampling::LINEAR);
	WorldPlayerRenderer->CreateAnimation("UpIdle", "UpIdle", 0.05f);
	WorldPlayerRenderer->CreateAnimation("UpWalk", "UpWalk", 0.05f);
	WorldPlayerRenderer->CreateAnimation("DownIdle", "DownIdle", 0.05f);
	WorldPlayerRenderer->CreateAnimation("DownWalk", "DownWalk", 0.05f);
	WorldPlayerRenderer->CreateAnimation("StraightIdle", "StraightIdle", 0.05f);
	WorldPlayerRenderer->CreateAnimation("StraightWalk", "StraightWalk", 0.05f);
	WorldPlayerRenderer->CreateAnimation("DiagonalUpIdle", "DiagonalUpIdle", 0.05f);
	WorldPlayerRenderer->CreateAnimation("DiagonalUpWalk", "DiagonalUpWalk", 0.05f);
	WorldPlayerRenderer->CreateAnimation("DiagonalDownIdle", "DiagonalDownIdle", 0.05f);
	WorldPlayerRenderer->CreateAnimation("DiagonalDownWalk", "DiagonalDownWalk", 0.05f);
	//WorldPlayerRenderer->CreateAnimation("DownIdle", "DownIdle", 0.05f);
	//WorldPlayerRenderer->CreateAnimation("DownWalk", "DownWalk", 0.05f);
	//WorldPlayerRenderer->CreateAnimation("UpIdle", "UpIdle", 0.05f);

	StateInit();
	WorldPlayerRenderer->SetAutoSize(1.0f, true);
	AButton->SetActive(false);
	Boss1title->SetActive(false);
	Boss2title->SetActive(false);
	//WorldPlayerRenderer->ChangeAnimation("Idle");
}

void AWorldPlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	State.Update(_DeltaTime);

	PlayerPos = GetActorLocation();
	DebugMessageFunction();

}
