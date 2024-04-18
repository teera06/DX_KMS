#include "PreCompile.h"
#include "MoveObject.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

MoveObject::MoveObject()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("smallskill");

	ObjectRender = CreateDefaultSubObject<USpriteRenderer>("ObjectRender");

	ObjectRender->SetupAttachment(Root);

	TopCollision = CreateDefaultSubObject<UCollision>("TopCollision ");
	TopCollision->SetupAttachment(Root);
	TopCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	
	TopCollision->SetCollisionGroup(ECollisionOrder::Boss1Top);
	TopCollision->SetCollisionType(ECollisionType::RotRect);

	LRCollision = CreateDefaultSubObject<UCollision>("LRCollision");
	LRCollision->SetupAttachment(Root);
	LRCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));
	
	LRCollision->SetCollisionGroup(ECollisionOrder::Boss1LR);
	LRCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);
}

MoveObject::~MoveObject()
{
}

void MoveObject::BeginPlay()
{
	Super::BeginPlay();

	ObjectRender->SetOrder(ERenderOrder::skilleffect);
	ObjectRender->SetSprite("shortfrog_fist_0001.png");
	ObjectRender->SetSamplering(ETextureSampling::LINEAR);
	ObjectRender->SetAutoSize(1.0f, true);
	
	ObjectRender->SetDir(EEngineDir::Left);
	
	ObjectRender->CreateAnimation("smallskill", "smallskill", 0.1f);
	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	ObjectRender->ChangeAnimation("smallskill");
}

void MoveObject::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void MoveObject::Collisiongather(float _DeltaTime)
{

}
