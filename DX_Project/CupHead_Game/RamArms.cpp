#include "PreCompile.h"
#include "RamArms.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"
ARamArms::ARamArms()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("RamArms");
	RamArms = CreateDefaultSubObject<USpriteRenderer>("RamArms");
	RamArms->SetupAttachment(Root);


	RamArmCol = CreateDefaultSubObject<UCollision>("RamArmCol");
	RamArmCol->SetupAttachment(Root);
	RamArmCol->SetPosition(FVector(0.0f, -50.0f, 0.0f));
	RamArmCol->SetScale(FVector(930.0f, 100.0f, 100.0f));
	RamArmCol->SetCollisionGroup(ECollisionOrder::RamArmCol);
	RamArmCol->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);

	RamArms->SetOrder(ERenderOrder::backSkill);
	RamArms->SetSprite("devil_ph1_ram_hand_attack_0001.png");
	RamArms->SetSamplering(ETextureSampling::LINEAR);
	RamArms->SetAutoSize(1.0f, true);
	RamArms->SetPlusColor(FVector(0.05f, 0.05f, 0.05f));
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
	if (true == hitCheck)
	{
		RamArms->SetPlusColor(FVector(0.15f, 0.15f, 0.15f));
	}

	DamgeColorDelay -= _DeltaTime;

	if (DamgeColorDelay < 0)
	{
		RamArms->SetPlusColor(FVector(0.05f, 0.05f, 0.05f));
		DamgeColorDelay = 0.25f;
	}

	Phase1.Update(_DeltaTime);
	PlayerCollisionCheck();
}

void ARamArms::AniCreate()
{
	RamArms->CreateAnimation("RamArmsStart", "RamArmsStart", 0.075f,false);
	RamArms->CreateAnimation("RamArmsEnd", "RamArmsEnd", 0.075f,false);
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

void ARamArms::PlayerCollisionCheck()
{
	RamArmCol->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

			Player->State.ChangeState("hit");

		});
}

void ARamArms::RamArmsStart(float _DeltaTime)
{
	AddActorLocation(MoveLR * speed * _DeltaTime);

	if (GetActorLocation().iX() >= -460 && MoveLR.iX()==1)
	{
		UEngineSound::SoundPlay("sfx_level_devil_ram_hand_clap_03.wav");
		Phase1.ChangeState("RamArmsEnd");
		return;
	}

	if (GetActorLocation().iX() <= 460 && MoveLR.iX() == -1)
	{
		UEngineSound::SoundPlay("sfx_level_devil_ram_hand_clap_03.wav");
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
			SkillDestory = true;
			Destroy();
			return;
		}
	}

	if (GetActorLocation().iX() >= 1000 && MoveLR.iX() == -1)
	{

		if (true == RamArms->IsCurAnimationEnd())
		{

			Destroy();
			return;
		}
	}
}
