#include "PreCompile.h"
#include "BossBackMap1.h"
#include "ContentsENum.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "DemonMonster.h"
#include "Boss2Common.h"
#include "ContentsHelper.h"


ABossBackMap1::ABossBackMap1()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("BossBackMap1");
	BossBackMap1 = CreateDefaultSubObject<USpriteRenderer>("BossBackMap1");

	BossBackMap1->SetupAttachment(Root);


	BossBackMap1->SetOrder(ERenderOrder::Boss1_back2);
	BossBackMap1->SetSprite("BossDevil_Phase1Background2.png");
	BossBackMap1->SetSamplering(ETextureSampling::LINEAR);
	BossBackMap1->SetAutoSize(1.0f, true);

	Front = CreateDefaultSubObject<USpriteRenderer>("Front");
	
	Front->SetupAttachment(Root);

	Front->SetOrder(ERenderOrder::Boss1_crowd2);
	Front->SetSprite("BossDevil_Phase1BackgroundChair.png");
	Front->SetSamplering(ETextureSampling::LINEAR);
	Front->SetAutoSize(1.0f, true);

	SetRoot(Root);
}

ABossBackMap1::~ABossBackMap1()
{
}

void ABossBackMap1::BeginPlay()
{
	Super::BeginPlay();
	Front->SetPosition(FVector(0.0f, 60.0f, -150.0f));
	//SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(0.0f, 0.0f, 200.0f));
}


void ABossBackMap1::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	CoolDownTime -= _DeltaTime;
	if (CoolDownTime<0 && ABoss2Common::phasecheck==1)
	{
		GetWorld()->SpawnActor<ADemonMonster>("DemonMonster")->SetLRStart(LRCheck);
		if (false == LRCheck)
		{
			LRCheck = true;
		}
		else
		{
			LRCheck = false;
		}
		CoolDownTime = 8.0f;
	}

	if (true == UContentsHelper::DelMapCheck)
	{
		Destroy();
	}
}
