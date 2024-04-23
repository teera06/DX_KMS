#include "PreCompile.h"
#include "Devil2.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ADevil2::ADevil2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");
	Boss2 = CreateDefaultSubObject<USpriteRenderer>("Boss2");

	Boss2->SetupAttachment(Root);

	Boss2->SetOrder(ERenderOrder::Monster2);
	Boss2->SetSprite("devil_ph3_idle_0001.png");
	Boss2->SetSamplering(ETextureSampling::LINEAR);
	Boss2->SetAutoSize(0.8f, true);

	DevilNeck = CreateDefaultSubObject<USpriteRenderer>("DevilNeck");
	
	DevilNeck->SetupAttachment(Root);
	
	DevilNeck->SetOrder(ERenderOrder::Monster1);
	DevilNeck->SetSprite("devil_ph3_neck_boil_0001.png");
	DevilNeck->SetSamplering(ETextureSampling::LINEAR);
	DevilNeck->SetAutoSize(0.8f, true);

	SetRoot(Root);

	DevilNeck->AddPosition(FVector(40.0f, -400.0f, 0.0f));
}

ADevil2::~ADevil2()
{
}

void ADevil2::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 90.0f, 10.0f));

	AniCreate();
	DevilNeck->ChangeAnimation("DevilNeck");
	Phase1StateInit();
}

void ADevil2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	coolDownTime -= _DeltaTime;
	Phase2.Update(_DeltaTime);
}

void ADevil2::Phase1StateInit()
{
	Phase2.CreateState("DevilPhase2Idle");

	Phase2.SetUpdateFunction("DevilPhase2Idle", std::bind(&ADevil2::DevilPhase2Idle, this, std::placeholders::_1));
	Phase2.SetStartFunction("DevilPhase2Idle", [=] {Boss2->ChangeAnimation("DevilPhase2Idle"); });

	Phase2.ChangeState("DevilPhase2Idle");
}

void ADevil2::AniCreate()
{
	Boss2->CreateAnimation("DevilPhase2Idle", "DevilPhase2Idle", 0.075f);

	DevilNeck->CreateAnimation("DevilNeck", "DevilNeck", 0.075f);
}

void ADevil2::DevilPhase2Idle(float _DeltaTime)
{

}
