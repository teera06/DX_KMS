#include "PreCompile.h"
#include "PhaseChangeBack.h"

#include "ContentsENum.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>


APhaseChangeBack::APhaseChangeBack()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("BossBackMap1");
	PhaseChangeBack = CreateDefaultSubObject<USpriteRenderer>("BossBackMap1");

	PhaseChangeBack->SetupAttachment(Root);
	
	PhaseChangeBack->SetOrder(ERenderOrder::FilterEffect);
	PhaseChangeBack->SetSprite("BossDevil_Phase1ToPhase2Background.png");
	PhaseChangeBack->SetSamplering(ETextureSampling::LINEAR);
	PhaseChangeBack->SetAutoSize(1.2f, true);

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

	if (GetActorLocation().iY() >= 600)
	{
		DelCheck = true;
	}

	if (GetActorLocation().iY() >= 1200)
	{
		Destroy();
	}
	AddActorLocation(FVector::Up * Speed * _DeltaTime);
}
