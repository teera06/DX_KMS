#include "PreCompile.h"

#include "BaseBullet.h"


#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Firefly.h"
#include "DemonMonster.h"

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
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
		//Destroy();
		//_Collison->GetActor()->Destroy();
	});

	BulletCollision->CollisionEnter(ECollisionOrder::Boss1SkillMonster, [=](std::shared_ptr<UCollision> _Collison)
	{

		AActor* Ptr = _Collison->GetActor();
		AFirefly* Monster = dynamic_cast<AFirefly*>(Ptr);
		Monster->SetDie(true);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
	});

	BulletCollision->CollisionEnter(ECollisionOrder::Demon, [=](std::shared_ptr<UCollision> _Collison)
	{

		AActor* Ptr = _Collison->GetActor();
		ADemonMonster* Monster = dynamic_cast<ADemonMonster*>(Ptr);
		Monster->IsDieCheck(true);
		DestroyCheck = true;
		BulletRender->ChangeAnimation("Peashot_Death");
	});

	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600 || GetActorLocation().iY() >= 360) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}
