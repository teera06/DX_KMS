#include "PreCompile.h"
#include "RamArms.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ARamArms::ARamArms()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("RamArms");
	RamArms = CreateDefaultSubObject<USpriteRenderer>("RamArms");
	RamArms->SetupAttachment(Root);

	SetRoot(Root);

	RamArms->SetOrder(ERenderOrder::backSkill);
	RamArms->SetSprite("devil_ph1_ram_hand_attack_0001.png");
	RamArms->SetSamplering(ETextureSampling::LINEAR);
	RamArms->SetAutoSize(1.0f, true);
}

ARamArms::~ARamArms()
{
}

void ARamArms::BeginPlay()
{
	Super::BeginPlay();
	AniCreate();

	StateInit();
}

void ARamArms::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
}

void ARamArms::AniCreate()
{
	RamArms->CreateAnimation("RamArmsStart", "RamArmsStart", 0.075f);
	RamArms->CreateAnimation("RamArmsEnd", "RamArmsEnd", 0.075f);
}

void ARamArms::StateInit()
{
	State.CreateState("RamArmsStart");
	State.CreateState("RamArmsEnd");

	State.SetUpdateFunction("RamArmsStart", std::bind(&ARamArms::RamArmsStart, this, std::placeholders::_1));
	State.SetStartFunction("RamArmsStart", [=] {RamArms->ChangeAnimation("RamArmsStart"); });

	State.SetUpdateFunction("RamArmsEnd", std::bind(&ARamArms::RamArmsEnd, this, std::placeholders::_1));
	State.SetStartFunction("RamArmsEnd", [=] {RamArms->ChangeAnimation("RamArmsEnd"); });

	State.ChangeState("RamArmsStart");
}

void ARamArms::RamArmsStart(float _DeltaTime)
{
	AddActorLocation(FVector::Right * speed * _DeltaTime);

	if (GetActorLocation().iX() >= 0)
	{
		State.ChangeState("RamArmsEnd");
		return;
	}
}

void ARamArms::RamArmsEnd(float _DeltaTime)
{
	AddActorLocation(FVector::Left * 900.0f * _DeltaTime);

	if (GetActorLocation().iX() <= -1000)
	{

		if (true == RamArms->IsCurAnimationEnd())
		{
			//SkillDestory = true;
			Destroy();
			return;
		}
	}
}
