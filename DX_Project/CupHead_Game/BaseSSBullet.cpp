#include "PreCompile.h"

#include "BaseSSBullet.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Firefly.h"

ABaseSSBullet::ABaseSSBullet()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Bullet");

	BulletRender = CreateDefaultSubObject<USpriteRenderer>("Bullet");

	BulletRender->SetupAttachment(Root);

	BulletCollision = CreateDefaultSubObject<UCollision>("BulletCollision");
	BulletCollision->SetupAttachment(Root);
	BulletCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	BulletCollision->SetCollisionGroup(ECollisionOrder::SuperBullet);
	BulletCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

ABaseSSBullet::~ABaseSSBullet()
{
}

void ABaseSSBullet::BeginPlay()
{
	Super::BeginPlay();

	BulletRender->SetOrder(ERenderOrder::Bullet);
	BulletRender->SetSprite("EX_Spawn01.png");
	BulletRender->SetSamplering(ETextureSampling::LINEAR);
	BulletRender->SetAutoSize(1.0f, true);

	BulletRender->CreateAnimation("PeaEX_Spawn", "PeaEX_Spawn", 0.02f);
	BulletRender->CreateAnimation("PeaEX_Loop", "PeaEX_Loop", 0.05f);
	BulletRender->CreateAnimation("PeaEX_Death", "PeaEX_Death", 0.03f);

	BulletRender->ChangeAnimation("PeaEX_Spawn");
}

void ABaseSSBullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == BulletRender->IsCurAnimationEnd() && true == DestroyCheck)
	{
		Destroy();
	}


	if (BulletDir.iX() != 0 || BulletDir.iroundY() != 0)
	{
		SkillDir();
		Move = BulletDir * Speed * _DeltaTime;

		if (true == BulletRender->IsCurAnimationEnd())
		{
			shoot = true;
			BulletRender->ChangeAnimation("PeaEX_Loop");
		}

		if (true == shoot)
		{
			AddActorLocation(Move);
		}

		Collisiongather();

	}

}

void ABaseSSBullet::Collisiongather()
{
	BulletCollision->CollisionEnter(ECollisionOrder::Boss1Monster1, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_weapon_peashoot_ex_impact_01.wav");
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		//Destroy();
		//_Collison->GetActor()->Destroy();
	});

	BulletCollision->CollisionEnter(ECollisionOrder::Boss1SkillMonster, [=](std::shared_ptr<UCollision> _Collison)
	{

		AActor* Ptr = _Collison->GetActor();
		AFirefly* Monster = dynamic_cast<AFirefly*>(Ptr);
		Monster->SetDie(true);
	});

	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600 || GetActorLocation().iY() >= 360 || GetActorLocation().iY() <= -500  ) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}
