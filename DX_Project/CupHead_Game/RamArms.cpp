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

	Phase1StateInit();
}

void ARamArms::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Phase1.Update(_DeltaTime);
}

void ARamArms::AniCreate()
{
	RamArms->CreateAnimation("RamArmsStart", "RamArmsStart", 0.075f);
	RamArms->CreateAnimation("RamArmsEnd", "RamArmsEnd", 0.075f);
}

void ARamArms::Phase1StateInit()
{
	Phase1.CreateState("RamArmsStart");
	Phase1.CreateState("RamArmsEnd");

	Phase1.SetUpdateFunction("RamArmsStart", std::bind(&ARamArms::RamArmsStart, this, std::placeholders::_1));
	Phase1.SetStartFunction("RamArmsStart", [=] {RamArms->ChangeAnimation("RamArmsStart"); });

	Phase1.SetUpdateFunction("RamArmsEnd", std::bind(&ARamArms::RamArmsEnd, this, std::placeholders::_1));
	Phase1.SetStartFunction("RamArmsEnd", [=] {RamArms->ChangeAnimation("RamArmsEnd"); });

	Phase1.ChangeState("RamArmsStart");
}

void ARamArms::RamArmsStart(float _DeltaTime)
{
	AddActorLocation(MoveLR * speed * _DeltaTime);

	if (GetActorLocation().iX() >= -430 && MoveLR.iX()==1)
	{
		Phase1.ChangeState("RamArmsEnd");
		return;
	}

	if (GetActorLocation().iX() <= 430 && MoveLR.iX() == -1)
	{
		Phase1.ChangeState("RamArmsEnd");
		return;
	}
}

void ARamArms::RamArmsEnd(float _DeltaTime)
{
	AddActorLocation(MoveLR*-1.0f * 900.0f * _DeltaTime);

	if (GetActorLocation().iX() <= -1000 && MoveLR.iX() == 1)
	{

		if (true == RamArms->IsCurAnimationEnd())
		{
			//SkillDestory = true;
			Destroy();
			return;
		}
	}

	if (GetActorLocation().iX() >= 1000 && MoveLR.iX() == -1)
	{

		if (true == RamArms->IsCurAnimationEnd())
		{
			//SkillDestory = true;
			Destroy();
			return;
		}
	}
}
