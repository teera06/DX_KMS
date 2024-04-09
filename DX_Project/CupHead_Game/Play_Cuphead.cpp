#include "PreCompile.h"
#include "Play_Cuphead.h"
#include "ContentsENum.h"
#include <EngineCore/Renderer.h>


APlay_Cuphead::APlay_Cuphead()
{
	PlayCuphead = CreateDefaultSubObject<USpriteRenderer>("WorldPlayer");
	InputOn();
}

APlay_Cuphead::~APlay_Cuphead()
{
}

void APlay_Cuphead::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
	//SetActorLocation(FVector(0.0f, 0.0f, -50.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	PlayCuphead->SetOrder(ERenderOrder::kirby);
	PlayCuphead->SetSprite("cuphead_intro_a_0001.png");
	PlayCuphead->SetSamplering(ETextureSampling::LINEAR);
	PlayCuphead->CreateAnimation("Intro", "Intro", 0.05f);

	PlayCuphead->ChangeAnimation("Intro");
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	
}



