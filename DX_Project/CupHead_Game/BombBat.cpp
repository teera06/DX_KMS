#include "PreCompile.h"
#include "BombBat.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ABombBat::ABombBat()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("BombBat");
	BombBat = CreateDefaultSubObject<USpriteRenderer>("BombBat");
	BombBat->SetupAttachment(Root);

	BombBat->SetOrder(ERenderOrder::FrontSkillMonster);
	BombBat->SetSprite("devil_ph3_attack_bomb_bat_0001.png");
	BombBat->SetSamplering(ETextureSampling::LINEAR);
	BombBat->SetAutoSize(0.85f, true);

	ColBat = CreateDefaultSubObject<UCollision>("ColBat");
	ColBat->SetupAttachment(Root);

	ColBat->SetScale(FVector(70.0f, 70.0f, 100.0f));

	ColBat->SetCollisionGroup(ECollisionOrder::BombBat);
	ColBat->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

ABombBat::~ABombBat()
{
}

void ABombBat::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(200.0f, 200.0f, 5.0f));

	BombBat->CreateAnimation("BombBat", "BombBat", 0.075f);
	BombBat->CreateAnimation("BombExplosion", "BombExplosion", 0.075f);

	//BombBat->ChangeAnimation("BombBat");
	UEngineSound::SoundPlay("devil_head_devil_bomb_appear.wav");
	patternInit();
}

void ABombBat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	BoomTime -= _DeltaTime;
	pattern.Update(_DeltaTime);
}

void ABombBat::patternInit()
{
	pattern.CreateState("LeftMove");
	pattern.CreateState("UpMove");
	pattern.CreateState("RightMove");
	pattern.CreateState("BombExplosion");

	pattern.SetUpdateFunction("LeftMove", std::bind(&ABombBat::LeftMove, this, std::placeholders::_1));
	pattern.SetStartFunction("LeftMove", [=] {BombBat->ChangeAnimation("BombBat"); });

	pattern.SetUpdateFunction("UpMove", std::bind(&ABombBat::UpMove, this, std::placeholders::_1));
	

	pattern.SetUpdateFunction("RightMove", std::bind(&ABombBat::RightMove, this, std::placeholders::_1));
	
	pattern.SetUpdateFunction("BombExplosion", std::bind(&ABombBat::BombExplosion, this, std::placeholders::_1));
	pattern.SetStartFunction("BombExplosion", [=] {BombBat->ChangeAnimation("BombExplosion"); });

	pattern.ChangeState("LeftMove");
}

void ABombBat::LeftMove(float _DeltaTime)
{
	if (BoomTime < 0)
	{
		pattern.ChangeState("BombExplosion");
		return;
	}

	AddActorLocation((FVector::Left + FVector::Down * 0.2f) * speed * _DeltaTime);
	if (true == BombBat->IsCurAnimationEnd())
	{
		pattern.ChangeState("UpMove");
		return;
	}
}

void ABombBat::UpMove(float _DeltaTime)
{
	if (BoomTime < 0)
	{
		pattern.ChangeState("BombExplosion");
		return;
	}
	AddActorLocation((FVector::Up * 0.2f) * speed * _DeltaTime);
	if (true == BombBat->IsCurAnimationEnd())
	{
		pattern.ChangeState("RightMove");
		return;
	}
}

void ABombBat::RightMove(float _DeltaTime)
{
	if (BoomTime < 0)
	{
		pattern.ChangeState("BombExplosion");
		return;
	}
	AddActorLocation((FVector::Right + FVector::Down * 0.2f) * speed * _DeltaTime);
	if (true == BombBat->IsCurAnimationEnd())
	{
		pattern.ChangeState("LeftMove");
		return;
	}
}

void ABombBat::BombExplosion(float _DeltaTime)
{
	if (true == BombBat->IsCurAnimationEnd())
	{
		Destroy();
		return;
	}
}
