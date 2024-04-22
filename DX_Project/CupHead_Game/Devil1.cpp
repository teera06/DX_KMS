#include "PreCompile.h"
#include "Devil1.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
ADevil1::ADevil1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2");
	Boss2 = CreateDefaultSubObject<USpriteRenderer>("Boss2");

	Boss2->SetupAttachment(Root);

	SetRoot(Root);

	Boss2->SetOrder(ERenderOrder::Monster1);
	Boss2->SetSprite("devil_ph1_intro_0004.png");
	Boss2->SetSamplering(ETextureSampling::LINEAR);
	Boss2->SetAutoSize(1.0f, true);
}

ADevil1::~ADevil1()
{
}

void ADevil1::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(-10.0f, 30.0f, 10.0f));
	AniCreate();

	Phase1StateInit();
}

void ADevil1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Phase1.Update(_DeltaTime);
}

void ADevil1::Phase1StateInit()
{
	Phase1.CreateState("Phase1Intro");
	Phase1.CreateState("Phase1Idle");

	Phase1.SetUpdateFunction("Phase1Intro", std::bind(&ADevil1::Phase1Intro, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase1Intro", [=] {Boss2->ChangeAnimation("Phase1Intro"); });

	Phase1.SetUpdateFunction("Phase1Idle", std::bind(&ADevil1::Phase1Idle, this, std::placeholders::_1));
	Phase1.SetStartFunction("Phase1Idle", [=] {Boss2->ChangeAnimation("Phase1Idle"); });

	Phase1.ChangeState("Phase1Intro");
}

void ADevil1::AniCreate()
{
	Boss2->CreateAnimation("Phase1Intro", "DevilIntro", 0.075f);
	Boss2->CreateAnimation("Phase1Idle", "DevilIdle", 0.075f);
}

void ADevil1::Phase1Intro(float _DeltaTime)
{
	if (true == Boss2->IsCurAnimationEnd())
	{
		Phase1.ChangeState("Phase1Idle");
		return;
	}

}

void ADevil1::Phase1Idle(float _DeltaTime)
{

}
