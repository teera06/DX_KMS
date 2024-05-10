#include "PreCompile.h"
#include "Play_Cuphead.h"
#include "ContentsENum.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Image.h>
#include <EngineCore/Collision.h>

#include <EngineCore/DefaultSceneComponent.h>

FVector APlay_Cuphead::PlayerPos = FVector::Zero;
APlay_Cuphead* APlay_Cuphead::MainPlayer=nullptr;

int APlay_Cuphead::Hp=3;

APlay_Cuphead* APlay_Cuphead::GetMainPlayer()
{
	return MainPlayer;
}

APlay_Cuphead::APlay_Cuphead()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");

	PlayCuphead = CreateDefaultSubObject<USpriteRenderer>("PlayCuphead");

	PlayCuphead->SetupAttachment(Root);
	PlayCuphead->SetPivot(EPivot::BOT);

	BulletStart = CreateDefaultSubObject<USpriteRenderer>("BulletStart");

	BulletStart->SetupAttachment(Root);

	Effect = CreateDefaultSubObject<USpriteRenderer>("Parry");

	Effect->SetupAttachment(Root);

	Effect->SetPivot(EPivot::BOT);

	PlayerCollision = CreateDefaultSubObject<UCollision>("Collision");
	PlayerCollision->SetupAttachment(Root);
	PlayerCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));
	PlayerCollision->SetScale(FVector(70.0f, 100.0f, 100.0f));
	//PlayerCollision은 무조건 오더를 지정해줘야 한다.
	PlayerCollision->SetCollisionGroup(ECollisionOrder::Player);
	PlayerCollision->SetCollisionType(ECollisionType::RotRect);

	ParryCollision = CreateDefaultSubObject<UCollision>("Collision");
	ParryCollision->SetupAttachment(Root);
	ParryCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));
	ParryCollision->SetScale(FVector(100.0f, 120.0f, 100.0f));

	ParryCollision->SetCollisionGroup(ECollisionOrder::Parry);
	ParryCollision->SetCollisionType(ECollisionType::RotRect);

	GroundCollision = CreateDefaultSubObject<UCollision>("GroundCollision");
	GroundCollision->SetupAttachment(Root);
	GroundCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));
	GroundCollision->SetScale(FVector(70.0f, 100.0f, 100.0f));

	GroundCollision->SetCollisionGroup(ECollisionOrder::PlayerGround);
	GroundCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);

	ParryCollision->SetActive(false);
	PlayCuphead->SetOrder(ERenderOrder::Cuphead);
	PlayCuphead->SetSprite("cuphead_idle_0001.png");
	PlayCuphead->SetSamplering(ETextureSampling::LINEAR);

	BulletStart->SetOrder(ERenderOrder::skilleffect);
	BulletStart->SetSprite("Spawn01.png");
	BulletStart->SetSamplering(ETextureSampling::LINEAR);

	Effect->SetOrder(ERenderOrder::FrontSkill);
	Effect->SetSprite("parryeffect_01.png");
	Effect->SetSamplering(ETextureSampling::LINEAR);
	Effect->SetPosition(FVector(0.0f, -20.0f, 0.0f));

	InputOn();

	
}

APlay_Cuphead::~APlay_Cuphead()
{
	GrountSound.Off();
	BaseBulletSound.Off();
	Guage.clear();
	Guageint.clear();
}


void APlay_Cuphead::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
	SetActorLocation(FVector(-400.0f, -250.0f, 0.0f));




	PlayCuphead->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	PlayCuphead->CreateAnimation("Intro", "Intro", 0.05f);
	PlayCuphead->CreateAnimation("Idle", "Idle", 0.05f);

	PlayCuphead->CreateAnimation("Run", "Run", 0.05f);
	PlayCuphead->CreateAnimation("Dash", "Dash", 0.05f);
	PlayCuphead->CreateAnimation("Duck", "Duck", 0.05f,false);
	PlayCuphead->CreateAnimation("Shoot_Straight", "Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Run_Shoot_Straight", "Run_Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Run_Shoot_DiagonalUp", "Run_Shoot_DiagonalUp", 0.05f);
	PlayCuphead->CreateAnimation("Duck_Shoot", "Duck_Shoot", 0.05f);
	PlayCuphead->CreateAnimation("Shoot_Up", "Shoot_Up", 0.05f);
	PlayCuphead->CreateAnimation("Aim_Up", "Aim_Up", 0.05f);
	PlayCuphead->CreateAnimation("Jump", "Jump", 0.05f);
	PlayCuphead->CreateAnimation("hit", "Hit_Ground", 0.075f, false);
	PlayCuphead->CreateAnimation("Parry", "Parry", 0.03f, false);
	PlayCuphead->CreateAnimation("Scared", "Scared", 0.075f, false);
	PlayCuphead->CreateAnimation("SSGround_Straight", "SSGround_Straight", 0.04f);
	PlayCuphead->CreateAnimation("SSGround_Down", "SSGround_Down", 0.04f);
	PlayCuphead->CreateAnimation("SSGround_DiagonalUp", "SSGround_DiagonalUp", 0.04f);
	PlayCuphead->CreateAnimation("SSGround_DiagonalDown", "SSGround_DiagonalDown", 0.04f);
	PlayCuphead->CreateAnimation("SSGround_Up", "SSGround_Up", 0.04f);

	PlayCuphead->CreateAnimation("Aim_Straight", "Aim_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Aim_DiagonalDown", "Aim_DiagonalDown", 0.05f);
	PlayCuphead->CreateAnimation("Aim_Down", "Aim_Down", 0.05f);
	PlayCuphead->CreateAnimation("Aim_DiagonalUp", "Aim_DiagonalUp", 0.05f);

	PlayCuphead->CreateAnimation("Shoot_DiagonalUp", "Shoot_DiagonalUp", 0.05f);
	PlayCuphead->CreateAnimation("Shoot_Down", "Shoot_Down", 0.05f);
	PlayCuphead->CreateAnimation("Shoot_DiagonalDown", "Shoot_DiagonalDown", 0.05f);


	Effect->CreateAnimation("ParryEffect", "ParryEffect", 0.055f);
	Effect->ChangeAnimation("ParryEffect");

	BulletStart->CreateAnimation("Peashot_Spawn", "Peashot_Spawn", 0.05f);

	BulletStart->ChangeAnimation("Peashot_Spawn");


	StateInit();
	PlayCuphead->SetAutoSize(1.0f, true);
	BulletStart->SetAutoSize(1.0f, true);
	Effect->SetAutoSize(1.0f, true);
	Dir = EDir::Right;
	
	BulletStart->SetActive(false);
	Effect->SetActive(false);

	Guage.resize(5);
	Guageint.resize(5);
	for (int i = 0; i < Guage.size(); i++)
	{
		Guage[i]= CreateWidget<UImage>(GetWorld(), "skillBar");
		Guage[i]->AddToViewPort(ERenderOrder::skiilBar);
		Guage[i]->SetSprite("SuperMeterCard.png");
		Guage[i]->SetAutoSize(1.0f, true);
		Guage[i]->SetActive(false);
		Guageint[i] = 0;
	}

	Guage[0]->SetPosition({ -510.0f, -310.0f });
	Guage[1]->SetPosition({ -490.0f, -310.0f });
	Guage[2]->SetPosition({ -470.0f, -310.0f });
	Guage[3]->SetPosition({ -450.0f, -310.0f });
	Guage[4]->SetPosition({ -430.0f, -310.0f });


	HpBar = CreateWidget<UImage>(GetWorld(), "HpBar");
	HpBar->AddToViewPort(ERenderOrder::HPBar);

	HpBar->SetSprite("HP3.png");

	HpBar->SetAutoSize(1.0f, true);

	HpBar->SetPosition({ -570.0f, -310.0f });


	BaseBulletSound= UEngineSound::SoundPlay("sfx_player_default_fire_loop_01.wav");
	BaseBulletSound.Loop();
	BaseBulletSound.Off();

	GrountSound = UEngineSound::SoundPlay("sfx_player_land_ground_01.wav");
	GrountSound.Loop();
	GrountSound.Off();

	MainPlayer = this;
	Hp = 3;
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
	
	State.Update(_DeltaTime);

	if (false == PlayerCollision->IsActive())
	{
		ColOnTime -= _DeltaTime;
		if (ColOnTime < 0)
		{
			PlayerCollision->SetActive(true);
			ColOnTime = 1.5f;
		}
	}

	CalHp(_DeltaTime);
	CalGuage();



	PlayerPos = GetActorLocation();
	DebugMessageFunction();
}



