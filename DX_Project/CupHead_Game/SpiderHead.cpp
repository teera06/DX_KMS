#include "PreCompile.h"
#include "SpiderHead.h"
#include <EngineBase\EngineRandom.h>


#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ASpiderHead::ASpiderHead()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("SpiderHead");
	SpiderHead = CreateDefaultSubObject<USpriteRenderer>("SpiderHead");
	SpiderHead->SetupAttachment(Root);

	SetRoot(Root);

	SpiderHead->SetOrder(ERenderOrder::backSkill);
	SpiderHead->SetSprite("devil_ph1_spider_attack_0001.png");
	SpiderHead->SetSamplering(ETextureSampling::LINEAR);
	SpiderHead->SetAutoSize(1.0f, true);
}

ASpiderHead::~ASpiderHead()
{
}

void ASpiderHead::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 450.0f, 0.0f));
	AniCreate();

	Phase1StateInit();
}

void ASpiderHead::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Phase1.Update(_DeltaTime);
}

void ASpiderHead::Phase1StateInit()
{
	Phase1.CreateState("SpiderHead_FallFromSky");
	Phase1.CreateState("SpiderHead_FallToFloor");
	Phase1.CreateState("SpiderHead_FlyToSky");
	Phase1.CreateState("SpiderHead_FlyToSky2");
	
	Phase1.SetUpdateFunction("SpiderHead_FallFromSky", std::bind(&ASpiderHead::SpiderHead_FallFromSky, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderHead_FallFromSky", [=] {SpiderHead->ChangeAnimation("SpiderHead_FallFromSky"); });

	Phase1.SetUpdateFunction("SpiderHead_FallToFloor", std::bind(&ASpiderHead::SpiderHead_FallToFloor, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderHead_FallToFloor", [=] {SpiderHead->ChangeAnimation("SpiderHead_FallToFloor"); });

	Phase1.SetUpdateFunction("SpiderHead_FlyToSky", std::bind(&ASpiderHead::SpiderHead_FlyToSky, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderHead_FlyToSky", [=] {SpiderHead->ChangeAnimation("SpiderHead_FlyToSky"); });

	Phase1.SetUpdateFunction("SpiderHead_FlyToSky2", std::bind(&ASpiderHead::SpiderHead_FlyToSky2, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderHead_FlyToSky2", [=] {SpiderHead->ChangeAnimation("SpiderHead_FlyToSky2"); });

	Phase1.ChangeState("SpiderHead_FallFromSky");
}

void ASpiderHead::AniCreate()
{
	SpiderHead->CreateAnimation("SpiderHead_FallFromSky", "SpiderHead_FallFromSky", 0.075f);
	SpiderHead->CreateAnimation("SpiderHead_FallToFloor", "SpiderHead_FallToFloor", 0.085f,false);
	SpiderHead->CreateAnimation("SpiderHead_FlyToSky", "SpiderHead_FlyToSky", 0.075f,false);
	SpiderHead->CreateAnimation("SpiderHead_FlyToSky2", "SpiderHead_FlyToSky2", 0.075f);
}


void ASpiderHead::SpiderHead_FallFromSky(float _DeltaTime)
{

	if (Attcount == 4)
	{
		SkillDestory = true;
		Destroy();
		return;
	}

	if (false == XPos)
	{
		//RandomXpos = UEngineRandom::MainRandom.RandomFloat(200.0f, -200.0f);
		SetActorLocation(FVector(0.0f, 450.0f, 0.0f));
		Attcount++;
		XPos = true;
	}
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // 중력은 계속 가해진다.

	if (GetActorLocation().iY() <= -10)
	{
		GravityVector = FVector::Zero;
		Phase1.ChangeState("SpiderHead_FallToFloor");
		return;
	}

	AddActorLocation(GravityVector* _DeltaTime);
}

void ASpiderHead::SpiderHead_FallToFloor(float _DeltaTime)
{
	Gravity = 2000.0f;
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // 중력은 계속 가해진다.

	if (GetActorLocation().iY() <= -100)
	{
		Gravity = 800.0f;
		GravityVector = FVector::Zero;
		Phase1.ChangeState("SpiderHead_FlyToSky");
		return;
	}
	AddActorLocation(GravityVector* _DeltaTime);
}

void ASpiderHead::SpiderHead_FlyToSky(float _DeltaTime)
{
	
	UpVector += (FVector::Up * speed * _DeltaTime); // 중력은 계속 가해진다.

	if (GetActorLocation().iY() >= 0)
	{
		UpVector = FVector::Zero;
		Phase1.ChangeState("SpiderHead_FlyToSky2");
		return;
	}

	AddActorLocation(UpVector * _DeltaTime);
}

void ASpiderHead::SpiderHead_FlyToSky2(float _DeltaTime)
{
	speed = 2000;
	UpVector += (FVector::Up * speed * _DeltaTime); // 중력은 계속 가해진다.

	if (GetActorLocation().iY() >= 600)
	{
		speed = 800;
		UpVector = FVector::Zero;
		XPos = false;
		Phase1.ChangeState("SpiderHead_FallFromSky");
		return;
	}

	AddActorLocation(UpVector * _DeltaTime);
}
