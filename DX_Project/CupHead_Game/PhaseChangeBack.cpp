#include "PreCompile.h"
#include "PhaseChangeBack.h"

#include "ContentsENum.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsHelper.h"


#include "Boss2Phase2Map.h"
#include "Devil2.h"
#include "DevilPlatform.h"



APhaseChangeBack::APhaseChangeBack()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("BossBackMap1");
	PhaseChangeBack = CreateDefaultSubObject<USpriteRenderer>("BossBackMap1");

	PhaseChangeBack->SetupAttachment(Root);
	
	PhaseChangeBack->SetOrder(ERenderOrder::FilterEffect);
	PhaseChangeBack->SetSprite("BossDevil_Phase1ToPhase2Background.png");
	PhaseChangeBack->SetSamplering(ETextureSampling::LINEAR);
	PhaseChangeBack->SetAutoSize(1.3f, true);

	SetRoot(Root);
}

APhaseChangeBack::~APhaseChangeBack()
{
}

void APhaseChangeBack::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(0.0f, -2000.0f, -70.0f));
}

void APhaseChangeBack::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	Delay -= _DeltaTime;

	if (Delay < 0)
	{
		if (GetActorLocation().iY() >= 600)
		{
			if (false == OneCheck)
			{
				CreateActor();
				OneCheck = true;

			}
			UContentsHelper::DelMapCheck = true;
		}

		if (GetActorLocation().iY() >= 2000)
		{
			Destroy();
		}
		AddActorLocation(FVector::Up * Speed * _DeltaTime);
	}
}

void APhaseChangeBack::CreateActor()
{
	GetWorld()->SpawnActor<ABoss2Phase2Map>("Boss2Phase2Map");
	GetWorld()->SpawnActor<ADevil2>("Devil2");
	GetWorld()->SpawnActor<ADevilPlatform>("DevilPlatform1")->SetActorLocation(FVector(-580.0f,-180.0f,10.0f));
	GetWorld()->SpawnActor<ADevilPlatform>("DevilPlatform2")->SetActorLocation(FVector(-290.0f, -220.0f, 10.0f));
	GetWorld()->SpawnActor<ADevilPlatform>("DevilPlatform3")->SetActorLocation(FVector(0.0f, -250.0f, 10.0f));
	GetWorld()->SpawnActor<ADevilPlatform>("DevilPlatform4")->SetActorLocation(FVector(290.0f, -220.0f, 10.0f));
	GetWorld()->SpawnActor<ADevilPlatform>("DevilPlatform5")->SetActorLocation(FVector(580.0f, -180.0f, 10.0f));

}
