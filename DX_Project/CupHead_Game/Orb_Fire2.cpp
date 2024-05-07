#include "PreCompile.h"

#include "Orb_Fire2.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"

AOrb_Fire2::AOrb_Fire2()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Orb_Fire2");

	MainRender = CreateDefaultSubObject<USpriteRenderer>("MainRender");
	MainRender->SetupAttachment(Root);

	Orb_Fire2Render = CreateDefaultSubObject<USpriteRenderer>("Orb_Fire2");

	Orb_Fire2Render->SetupAttachment(Root);

	Orb_Fire2Render2 = CreateDefaultSubObject<USpriteRenderer>("Orb_Fire21");

	Orb_Fire2Render2->SetupAttachment(Root);

	Orb_Fire2Render3 = CreateDefaultSubObject<USpriteRenderer>("Orb_Fire22");

	Orb_Fire2Render3->SetupAttachment(Root);

	Orb_Fire2Render4 = CreateDefaultSubObject<USpriteRenderer>("Orb_Fire23");

	Orb_Fire2Render4->SetupAttachment(Root);

	Orb_Fire2Col = CreateDefaultSubObject<UCollision>("Orb_Fire2");
	Orb_Fire2Col->SetupAttachment(Root);
	Orb_Fire2Col->SetScale(FVector(100.0f, 100.0f, 100.0f));
	Orb_Fire2Col->SetCollisionGroup(ECollisionOrder::Orb_Fire2_Parry);
	Orb_Fire2Col->SetCollisionType(ECollisionType::RotRect);

	subCols.resize(4);

	for (int i = 0; i < subCols.size(); i++)
	{
		subCols[i]= CreateDefaultSubObject<UCollision>("subCol"); 
		subCols[i]->SetupAttachment(Root);
		subCols[i]->SetScale(FVector(100.0f, 100.0f, 100.0f));
		subCols[i]->SetCollisionGroup(ECollisionOrder::Orb_Fire2_Sub);
		subCols[i]->SetCollisionType(ECollisionType::RotRect);
	}

	

	SetRoot(Root);
}

AOrb_Fire2::~AOrb_Fire2()
{
	FireSound.Off();
	subCols.clear();
}

void AOrb_Fire2::BeginPlay()
{
	Super::BeginPlay();

	MainRender->SetOrder(ERenderOrder::skilleffect);
	MainRender->SetSprite("devil_ph1_fire_spark_0001.png");
	MainRender->SetSamplering(ETextureSampling::LINEAR);
	MainRender->SetAutoSize(1.0f, true);

	MainRender->CreateAnimation("OrbsSpawn_Fire_Parry", "OrbsSpawn_Fire_Parry", 0.1f);
	MainRender->CreateAnimation("Orb_Dance_Parry", "Orb_Dance_Parry", 0.055f);

	MainRender->ChangeAnimation("OrbsSpawn_Fire_Parry");

	Orb_Fire2Render->SetOrder(ERenderOrder::skilleffect);
	Orb_Fire2Render->SetSprite("devil_ph1_fire_spark_0001.png");
	Orb_Fire2Render->SetSamplering(ETextureSampling::LINEAR);
	Orb_Fire2Render->SetAutoSize(1.0f, true);

	Orb_Fire2Render->CreateAnimation("OrbsSpawn_Fire", "OrbsSpawn_Fire", 0.1f);
	Orb_Fire2Render->CreateAnimation("Orb_Dance", "Orb_Dance", 0.055f);

	Orb_Fire2Render->ChangeAnimation("OrbsSpawn_Fire");

	Orb_Fire2Render2->SetOrder(ERenderOrder::skilleffect);
	Orb_Fire2Render2->SetSprite("devil_ph1_fire_spark_0001.png");
	Orb_Fire2Render2->SetSamplering(ETextureSampling::LINEAR);
	Orb_Fire2Render2->SetAutoSize(1.0f, true);

	Orb_Fire2Render2->CreateAnimation("OrbsSpawn_Fire", "OrbsSpawn_Fire", 0.1f);
	Orb_Fire2Render2->CreateAnimation("Orb_Dance", "Orb_Dance", 0.055f);

	Orb_Fire2Render2->ChangeAnimation("OrbsSpawn_Fire");

	Orb_Fire2Render3->SetOrder(ERenderOrder::skilleffect);
	Orb_Fire2Render3->SetSprite("devil_ph1_fire_spark_0001.png");
	Orb_Fire2Render3->SetSamplering(ETextureSampling::LINEAR);
	Orb_Fire2Render3->SetAutoSize(1.0f, true);

	Orb_Fire2Render3->CreateAnimation("OrbsSpawn_Fire", "OrbsSpawn_Fire", 0.1f);
	Orb_Fire2Render3->CreateAnimation("Orb_Dance", "Orb_Dance", 0.055f);

	Orb_Fire2Render3->ChangeAnimation("OrbsSpawn_Fire");

	Orb_Fire2Render4->SetOrder(ERenderOrder::skilleffect);
	Orb_Fire2Render4->SetSprite("devil_ph1_fire_spark_0001.png");
	Orb_Fire2Render4->SetSamplering(ETextureSampling::LINEAR);
	Orb_Fire2Render4->SetAutoSize(1.0f, true);

	Orb_Fire2Render4->CreateAnimation("OrbsSpawn_Fire", "OrbsSpawn_Fire", 0.1f);
	Orb_Fire2Render4->CreateAnimation("Orb_Dance", "Orb_Dance", 0.055f);

	Orb_Fire2Render4->ChangeAnimation("OrbsSpawn_Fire");

	Orb_Fire2Render->SetPosition(FVector(200.0f, 150.0f, 0.0f));
	Orb_Fire2Render2->SetPosition(FVector(200.0f, -200.0f, 0.0f));
	Orb_Fire2Render3->SetPosition(FVector(-200.0f, -150.0f, 0.0f));
	Orb_Fire2Render4->SetPosition(FVector(-200.0f, 200.0f, 0.0f));

	subCols[0]->SetPosition(FVector(200.0f, 150.0f, 0.0f));
	subCols[1]->SetPosition(FVector(200.0f, -200.0f, 0.0f));
	subCols[2]->SetPosition(FVector(-200.0f, -150.0f, 0.0f));
	subCols[3]->SetPosition(FVector(-200.0f, 200.0f, 0.0f));

	FireSound = UEngineSound::SoundPlay("devil_projectile_fireball_loop.wav");
	FireSound.Loop();
	FireSound.On();

	patternInit();

}

void AOrb_Fire2::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == Orb_Fire2Render->IsCurAnimationEnd() && false==EndAni)
	{
		EndAni = true;

		Orb_Fire2Render->ChangeAnimation("Orb_Dance");
		Orb_Fire2Render2->ChangeAnimation("Orb_Dance");
		Orb_Fire2Render3->ChangeAnimation("Orb_Dance");
		Orb_Fire2Render4->ChangeAnimation("Orb_Dance");
		MainRender->ChangeAnimation("Orb_Dance_Parry");

	}

	if (true == EndAni)
	{
		pattern.Update(_DeltaTime);
	}

}

void AOrb_Fire2::RotMove(float _DeltaTime)
{
	FMatrix RotationMat, RotationXMat, RotationYMat, RotationZMat;
	RotationXMat.RotationXDeg(GetActorTransform().GetRotation().X);
	RotationYMat.RotationYDeg(GetActorTransform().GetRotation().Y);
	RotationZMat.RotationZDeg(GetActorTransform().GetRotation().Z);
	RotationMat = RotationXMat * RotationYMat * RotationZMat;

	AddActorRotation(FVector(0.0f, 0.0f, UEngineMath::DToR * RotSpeed * _DeltaTime));
	AddActorLocation(RotationMat.RightVector() * MoveSpeed * _DeltaTime);
	MainRender->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
	Orb_Fire2Render->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
	Orb_Fire2Render2->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
	Orb_Fire2Render3->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
	Orb_Fire2Render4->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
}

void AOrb_Fire2::patternInit()
{
	pattern.CreateState("MoveR");
	pattern.CreateState("MoveL");
	

	pattern.SetUpdateFunction("MoveR", std::bind(&AOrb_Fire2::MoveR, this, std::placeholders::_1));

	pattern.SetUpdateFunction("MoveL", std::bind(&AOrb_Fire2::MoveL, this, std::placeholders::_1));

	pattern.ChangeState("MoveR");
	
}

void AOrb_Fire2::MoveL(float _DeltaTime)
{
	RotMove(_DeltaTime);
	AddActorLocation(FVector::Left* MoveLR * _DeltaTime);
	if (GetActorLocation().iX() <= -800)
	{
		FireSound.Off();
		Destroy();
	}
}

void AOrb_Fire2::MoveR(float _DeltaTime)
{
	RotMove(_DeltaTime);
	AddActorLocation(FVector::Right * MoveLR * _DeltaTime);
	{
		if (true == Orb_Fire2Render->IsCurAnimationEnd())
		{
			pattern.ChangeState("MoveL");
		}
	}

}





