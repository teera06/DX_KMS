#include "PreCompile.h"
#include "HeadAtt.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

AHeadAtt::AHeadAtt()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("headatt");
	headatt = CreateDefaultSubObject<USpriteRenderer>("headatt");

	headatt->SetupAttachment(Root);
	//Boss2->SetPivot(EPivot::LEFTTOP);

	SetRoot(Root);

	headatt->SetOrder(ERenderOrder::FrontSkill);
	headatt->SetSprite("devil_ph1_dragon_attack_0001.png");
	headatt->SetSamplering(ETextureSampling::LINEAR);
	headatt->SetAutoSize(1.0f, true);
}

AHeadAtt::~AHeadAtt()
{
}

void AHeadAtt::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(30.0f, 50.0f, 10.0f));
	//AniCreate();

	//Phase1StateInit();
}

void AHeadAtt::Tick(float _DeltaTime)
{
}
