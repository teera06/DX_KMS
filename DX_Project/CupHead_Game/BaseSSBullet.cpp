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
	// �ݸ����� ������ ������ ��������� �Ѵ�.
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
}
