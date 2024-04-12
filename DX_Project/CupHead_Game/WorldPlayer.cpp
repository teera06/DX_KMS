#include "PreCompile.h"
#include "WorldPlayer.h"
#include "ContentsENum.h"

#include <EngineCore/DefaultSceneComponent.h>

AWorldPlayer::AWorldPlayer()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("WorldMap");

	WorldPlayerRenderer = CreateDefaultSubObject<USpriteRenderer>("WorldPlayer");

	WorldPlayerRenderer->SetupAttachment(Root);

	SetRoot(Root);
	InputOn();
}

AWorldPlayer::~AWorldPlayer()
{
}

void AWorldPlayer::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(10.0f, 10.0f, 100.0f));
	SetActorLocation(FVector(1500.0f/2.0f, -1700.0f/2.0f, 50.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
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

	//WorldPlayerRenderer->ChangeAnimation("Idle");
}

void AWorldPlayer::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	State.Update(_DeltaTime);
	DebugMessageFunction();
}
