#include "PreCompile.h"
#include "Boss1_Monster2.h"
#include "ContentsENum.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ABoss1_Monster2::ABoss1_Monster2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss1_1");
	BigBoss1 = CreateDefaultSubObject<USpriteRenderer>("Boss1_1");

	BigBoss1->SetupAttachment(Root);
	BigBoss1->SetPivot(EPivot::BOT);
	SetRoot(Root);
}

ABoss1_Monster2::~ABoss1_Monster2()
{
}

void ABoss1_Monster2::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(324.0f, 350.0f, 0.0f));
	SetActorLocation(FVector(450.0f, -250.0f, 0.0f));
	BigBoss1->SetOrder(ERenderOrder::Monster1);
	BigBoss1->SetSprite("tallfrog_idle_0001.png");
	BigBoss1->SetSamplering(ETextureSampling::LINEAR);
	BigBoss1->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	BigBoss1->CreateAnimation("bigintro", "bigintro", 0.12f);
	BigBoss1->CreateAnimation("bigIdle", "bigIdle", 0.1f);

	Phase1StateInit();

	BigBoss1->SetAutoSize(1.0f, true);
}

void ABoss1_Monster2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (1 == phasecheck)
	{
		Phase1.Update(_DeltaTime);
	}
}

void ABoss1_Monster2::Phase1StateInit()
{

	Phase1.CreateState("bigintro");
	Phase1.CreateState("bigIdle");
	

	Phase1.SetUpdateFunction("bigintro", std::bind(&ABoss1_Monster2::bigintro, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigintro", [=] {BigBoss1->ChangeAnimation("bigintro"); });

	Phase1.SetUpdateFunction("bigIdle", std::bind(&ABoss1_Monster2::bigIdle, this, std::placeholders::_1));
	Phase1.SetStartFunction("bigIdle", [=] {BigBoss1->ChangeAnimation("bigIdle"); });

	
	Phase1.ChangeState("bigintro");
}

void ABoss1_Monster2::bigintro(float _DeltaTime)
{
	if (true == BigBoss1->IsCurAnimationEnd())
	{
		Phase1.ChangeState("bigIdle");
		return;
	}
}

void ABoss1_Monster2::bigIdle(float _DeltaTime)
{
}

void ABoss1_Monster2::bigatt(float _DeltaTime)
{

}
