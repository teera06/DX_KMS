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

	Orb_Fire2Renders.resize(4);

	for (int i = 0; i < Orb_Fire2Renders.size(); i++)
	{
		Orb_Fire2Renders[i]= CreateDefaultSubObject<USpriteRenderer>("Orb_Fire2");

		Orb_Fire2Renders[i]->SetupAttachment(Root);
	}


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
	Orb_Fire2Renders.clear();
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

	for (int i = 0; i < Orb_Fire2Renders.size(); i++)
	{
		Orb_Fire2Renders[i]->SetOrder(ERenderOrder::skilleffect);
		Orb_Fire2Renders[i]->SetSprite("devil_ph1_fire_spark_0001.png");
		Orb_Fire2Renders[i]->SetSamplering(ETextureSampling::LINEAR);
		Orb_Fire2Renders[i]->SetAutoSize(1.0f, true);
		
		Orb_Fire2Renders[i]->CreateAnimation("OrbsSpawn_Fire", "OrbsSpawn_Fire", 0.1f);
		Orb_Fire2Renders[i]->CreateAnimation("Orb_Dance", "Orb_Dance", 0.055f);
		
		Orb_Fire2Renders[i]->ChangeAnimation("OrbsSpawn_Fire");
	}
	
	

	Orb_Fire2Renders[0]->SetPosition(FVector(200.0f, 150.0f, 0.0f));
	Orb_Fire2Renders[1]->SetPosition(FVector(200.0f, -200.0f, 0.0f));
	Orb_Fire2Renders[2]->SetPosition(FVector(-200.0f, -150.0f, 0.0f));
	Orb_Fire2Renders[3]->SetPosition(FVector(-200.0f, 200.0f, 0.0f));

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

	if (true == Orb_Fire2Renders[0]->IsCurAnimationEnd() && false == EndAni)
	{
		EndAni = true;

		for (int i = 0; i < Orb_Fire2Renders.size(); i++)
		{
			Orb_Fire2Renders[i]->ChangeAnimation("Orb_Dance");
		}
		MainRender->ChangeAnimation("Orb_Dance_Parry");

	}

	if (true == EndAni)
	{
		pattern.Update(_DeltaTime);
		Collisiongather();
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
	Orb_Fire2Renders[0]->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
	Orb_Fire2Renders[1]->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
	Orb_Fire2Renders[2]->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
	Orb_Fire2Renders[3]->AddRotationDeg(FVector(0.0f, 0.0f, (UEngineMath::DToR * RotSpeed * _DeltaTime) * -1.0f));
}

void AOrb_Fire2::Collisiongather()
{
	for (int i = 0; i < subCols.size(); i++)
	{
		subCols[i]->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

			Player->AddActorLocation(FVector::Up * 100.0f);
			Player->State.ChangeState("hit");
		});
	}

	Orb_Fire2Col->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		Player->AddActorLocation(FVector::Up * 100.0f);
		Player->State.ChangeState("hit");
	});
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
		if (true == Orb_Fire2Renders[0]->IsCurAnimationEnd())
		{
			pattern.ChangeState("MoveL");
		}
	}

}





