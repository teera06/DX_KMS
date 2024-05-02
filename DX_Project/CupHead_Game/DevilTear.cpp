#include "PreCompile.h"
#include "DevilTear.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"


ADevilTear::ADevilTear()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Tear");
	Tear = CreateDefaultSubObject<USpriteRenderer>("Tear");
	Tear->SetupAttachment(Root);

	Tear->SetOrder(ERenderOrder::backSkill);
	Tear->SetSprite("devil_ph3_tear_drop_bb_0001.png");
	Tear->SetSamplering(ETextureSampling::LINEAR);
	Tear->SetAutoSize(0.85f, true);
	Tear->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	SetRoot(Root);
}

ADevilTear::~ADevilTear()
{
}

void ADevilTear::BeginPlay()
{
	Super::BeginPlay();

	//SetActorLocation(FVector(0.0f, 500.0f, 5.0f));

	Tear->CreateAnimation("DevilTear1", "DevilTear1", 0.075f);
	
	Tear->ChangeAnimation("DevilTear1");
}

void ADevilTear::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	GroundCheck(_DeltaTime);
}

void ADevilTear::GroundCheck(float _DeltaTime)
{
	GravityVector += FVector::Down * Speed * _DeltaTime;

	AddActorLocation(GravityVector * _DeltaTime);

	if (GetActorLocation().iY() <= -300)
	{
		Destroy();
	}
}
