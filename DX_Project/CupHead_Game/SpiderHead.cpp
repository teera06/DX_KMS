#include "PreCompile.h"
#include "SpiderHead.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ASpiderHead::ASpiderHead()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("SpiderHead");
	SpiderHead = CreateDefaultSubObject<USpriteRenderer>("SpiderHead");
	SpiderHead->SetupAttachment(Root);

	SetRoot(Root);

	SpiderHead->SetOrder(ERenderOrder::backSkill);
	SpiderHead->SetSprite("devil_ph1_spider_attack_0001.png");
	SpiderHead->SetSamplering(ETextureSampling::LINEAR);
	SpiderHead->SetAutoSize(1.0f, true);
}

ASpiderHead::~ASpiderHead()
{
}

void ASpiderHead::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 0.0f, 0.0f));
	AniCreate();

	Phase1StateInit();
}

void ASpiderHead::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	Phase1.Update(_DeltaTime);
}

void ASpiderHead::Phase1StateInit()
{
	Phase1.CreateState("SpiderHead_FallFromSky");
	
	Phase1.SetUpdateFunction("SpiderHead_FallFromSky", std::bind(&ASpiderHead::SpiderHead_FallFromSky, this, std::placeholders::_1));
	Phase1.SetStartFunction("SpiderHead_FallFromSky", [=] {SpiderHead->ChangeAnimation("SpiderHead_FallFromSky"); });

	Phase1.ChangeState("SpiderHead_FallFromSky");
}

void ASpiderHead::AniCreate()
{
	SpiderHead->CreateAnimation("SpiderHead_FallFromSky", "SpiderHead_FallFromSky", 0.075f);
}

void ASpiderHead::GroundCheck(float _DeltaTime)
{
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // 중력은 계속 가해진다.

	if (GetActorLocation().iY() <= -300)
	{
		GravityVector = FVector::Zero;
	}
}

void ASpiderHead::SpiderHead_FallFromSky(float _DeltaTime)
{
	
}
