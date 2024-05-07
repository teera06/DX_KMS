#include "PreCompile.h"

#include "BaseBullet.h"


#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"


#include "Boss1_Monster1.h"
#include "Boss1_Monster2.h"

#include "Firefly.h"
#include "DemonMonster.h"
#include "Imp.h"
#include "FatDemon.h"
#include "BombBat.h"


#include "Devil1.h"



ABaseBullet::ABaseBullet()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Bullet");

	BulletRender = CreateDefaultSubObject<USpriteRenderer>("Bullet");

	BulletRender->SetupAttachment(Root);

	BulletCollision = CreateDefaultSubObject<UCollision>("BulletCollision");
	BulletCollision->SetupAttachment(Root);
	BulletCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	// 콜리전은 무조건 오더를 지정해줘야 한다.
	BulletCollision->SetCollisionGroup(ECollisionOrder::Bullet);
	BulletCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

ABaseBullet::~ABaseBullet()
{
}

void ABaseBullet::BeginPlay()
{
	Super::BeginPlay();

	BulletRender->SetOrder(ERenderOrder::Bullet);
	BulletRender->SetSprite("cuphead_idle_0001.png");
	BulletRender->SetSamplering(ETextureSampling::LINEAR);
	BulletRender->SetAutoSize(1.0f,true);

	BulletRender->CreateAnimation("Peashot_Spawn2", "Peashot_Spawn2", 0.02f);
	BulletRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);
	BulletRender->CreateAnimation("Peashot_Death", "Peashot_Death", 0.03f);

	BulletRender->ChangeAnimation("Peashot_Spawn2");

}

void ABaseBullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	
	if (true == BulletRender->IsCurAnimationEnd() && true==DestroyCheck)
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
			BulletRender->ChangeAnimation("Peashot_Loop");
		}

		if (true == shoot)
		{
			AddActorLocation(Move);
		}

		Collisiongather();

	}
}

void ABaseBullet::Collisiongather()
{
	BulletCollision->CollisionEnter(ECollisionOrder::Boss1Monster1, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster1* Monster = dynamic_cast<ABoss1_Monster1*>(Ptr);
		Monster->GetRender()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
		Monster->addHp(1);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
		//Destroy();
		//_Collison->GetActor()->Destroy();
	});

	BulletCollision->CollisionEnter(ECollisionOrder::Boss1Monster2, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster2* Monster = dynamic_cast<ABoss1_Monster2*>(Ptr);
		Monster->GetRender()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
		Monster->GetSlotMouse()->SetPlusColor({0.2f, 0.2f, 0.2f});
		Monster->GetFrontSlot()->SetPlusColor({0.2f, 0.2f, 0.2f});
		Monster->addHp(1);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
		//Destroy();
		//_Collison->GetActor()->Destroy();
	});
	

	BulletCollision->CollisionEnter(ECollisionOrder::Boss1SkillMonster, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		AFirefly* Monster = dynamic_cast<AFirefly*>(Ptr);
		Monster->SetDie(true);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
		
	});

	BulletCollision->CollisionEnter(ECollisionOrder::Demon, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ADemonMonster* Monster = dynamic_cast<ADemonMonster*>(Ptr);
		Monster->IsDieCheck(true);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::imp, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		AImp* Monster = dynamic_cast<AImp*>(Ptr);
		Monster->IsDieCheck(true);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::BombBat, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABombBat* Monster = dynamic_cast<ABombBat*>(Ptr);
		Monster->Destroy();
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::FatDemon, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		AFatDemon* Monster = dynamic_cast<AFatDemon*>(Ptr);
		Monster->AddHp(1);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
	});

	// Devil

	BulletCollision->CollisionEnter(ECollisionOrder::Devil1, [=](std::shared_ptr<UCollision> _Collison)
		{
		    UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
			AActor* Ptr = _Collison->GetActor();
			ADevil1* Monster = dynamic_cast<ADevil1*>(Ptr);
			Monster->GetBoss2Render()->SetPlusColor(FVector(0.2f, 0.2f, 0.2f));
			DestroyCheck = true;
			BulletRender->ChangeAnimation("Peashot_Death");
			BulletCollision->SetActive(false);
			//Destroy();
			//_Collison->GetActor()->Destroy();
		});

	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600 || GetActorLocation().iY() >= 360) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}
