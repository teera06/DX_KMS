#include "PreCompile.h"

#include "BaseSSBullet.h"

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
#include "Devil2.h"
#include "SpiderHead.h"
#include "RamArms.h"
#include "HeadAtt.h"

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


	if (BulletDir.iX() != 0 || BulletDir.iY() != 0)
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
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster1* Monster = dynamic_cast<ABoss1_Monster1*>(Ptr);
		Monster->GetRender()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
		Monster->addHp(Att);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
		//Destroy();
		//_Collison->GetActor()->Destroy();

	});

	BulletCollision->CollisionEnter(ECollisionOrder::Boss1Monster2, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster2* Monster = dynamic_cast<ABoss1_Monster2*>(Ptr);

		if (Monster->Getphasecheck() != 3)
		{
			Monster->GetRender()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
			Monster->GetSlotMouse()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
			Monster->GetFrontSlot()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
			Monster->addHp(Att);
		}
		else
		{
			if (true == Monster->GetPhase3ColOnOff())
			{
				Monster->GetRender()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
				Monster->GetSlotMouse()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
				Monster->GetFrontSlot()->SetPlusColor({ 0.2f, 0.2f, 0.2f });
				Monster->addHp(Att);
			}
		}
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
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
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::Demon, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ADemonMonster* Monster = dynamic_cast<ADemonMonster*>(Ptr);
		Monster->IsDieCheck(true);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::imp, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		AImp* Monster = dynamic_cast<AImp*>(Ptr);
		Monster->IsDieCheck(true);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::BombBat, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABombBat* Monster = dynamic_cast<ABombBat*>(Ptr);
		Monster->Destroy();
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::FatDemon, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		AFatDemon* Monster = dynamic_cast<AFatDemon*>(Ptr);
		Monster->AddHp(Att);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
	});

	// Devil

	BulletCollision->CollisionEnter(ECollisionOrder::Devil1, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ADevil1* Monster = dynamic_cast<ADevil1*>(Ptr);
		Monster->SethitCheck(true);
		Monster->addHp(Att);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
	});

	BulletCollision->CollisionEnter(ECollisionOrder::SpiderHeadCol, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ASpiderHead* Monster = dynamic_cast<ASpiderHead*>(Ptr);
		Monster->SethitCheck(true);
		Monster->addHp(Att);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
		//Destroy();
		//_Collison->GetActor()->Destroy();
	});

	BulletCollision->CollisionEnter(ECollisionOrder::DevilHeadCol, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		AHeadAtt* Monster = dynamic_cast<AHeadAtt*>(Ptr);
		Monster->SethitCheck(true);
		Monster->addHp(Att);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
		//_Collison->GetActor()->Destroy();
	});


	BulletCollision->CollisionEnter(ECollisionOrder::RamArmCol, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ARamArms* Monster = dynamic_cast<ARamArms*>(Ptr);
		Monster->SethitCheck(true);
		Monster->addHp(Att);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		BulletCollision->SetActive(false);
		//Destroy();
		//_Collison->GetActor()->Destroy();
	});

	BulletCollision->CollisionEnter(ECollisionOrder::Devil2, [=](std::shared_ptr<UCollision> _Collison)
	{
		UEngineSound::SoundPlay("sfx_player_shoot_hit_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ADevil2* Monster = dynamic_cast<ADevil2*>(Ptr);
		Monster->SethitCheck(true);
		Monster->addHp(Att);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("PeaEX_Death");
		BulletCollision->SetActive(false);
	});



	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600 || GetActorLocation().iY() >= 360 || GetActorLocation().iY() <= -500  ) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}
