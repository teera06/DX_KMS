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
	BulletCollision->SetCollisionGroup(ECollisionOrder::Player);
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
}

void ABaseBullet::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
