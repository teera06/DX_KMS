#include "PreCompile.h"

#include "BaseBullet.h"


#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

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
	BulletCollision->SetCollisionType(ECollisionType::Rect);


	SetRoot(Root);
}

ABaseBullet::~ABaseBullet()
{
}

void ABaseBullet::BeginPlay()
{
	Super::BeginPlay();

	BulletRender->SetOrder(ERenderOrder::Cuphead);
	BulletRender->SetSprite("cuphead_idle_0001.png");
	BulletRender->SetSamplering(ETextureSampling::LINEAR);
	BulletRender->SetAutoSize(1.0f,true);

	BulletRender->CreateAnimation("Peashot_Spawn2", "Peashot_Spawn2", 0.02f);
	BulletRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	BulletRender->ChangeAnimation("Peashot_Spawn2");

	//Destroy();
}

void ABaseBullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

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

void ABaseBullet::SkillDir()
{
	if (BulletDir.iX() == 1)
	{
		BulletRender->SetDir(EEngineDir::Right);
	}
	else if (BulletDir.iX() == -1)
	{
		BulletRender->SetDir(EEngineDir::Left);
	}
}

void ABaseBullet::Collisiongather()
{
	BulletCollision->CollisionEnter(ECollisionOrder::Monster, [=](std::shared_ptr<UCollision> _Collison)
	{
		Destroy();
		//_Collison->GetActor()->Destroy();
	});

	if (GetActorLocation().iX() <= -600 || GetActorLocation().iX() >= 600 || GetActorLocation().iY()>=360) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}
