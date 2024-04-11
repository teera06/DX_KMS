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

	//SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
	//SetActorLocation(FVector(0.0f, 0.0f, -50.0f));

	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	PlayCuphead->SetOrder(ERenderOrder::Cuphead);
	PlayCuphead->SetSprite("cuphead_idle_0001.png");
	PlayCuphead->SetSamplering(ETextureSampling::LINEAR);
	PlayCuphead->CreateAnimation("Idle", "Idle", 0.05f);

	PlayCuphead->CreateAnimation("Run", "Run", 0.05f);
	PlayCuphead->CreateAnimation("Dash", "Dash", 0.05f);
	PlayCuphead->CreateAnimation("Duck", "Duck", 0.05f,false);
	PlayCuphead->CreateAnimation("Shoot_Straight", "Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Run_Shoot_Straight", "Run_Shoot_Straight", 0.05f);
	PlayCuphead->CreateAnimation("Duck_Shoot", "Duck_Shoot", 0.05f);
	PlayCuphead->CreateAnimation("Jump", "Jump", 0.05f);
	//PlayCuphead->CreateAnimation("Duck", "Duck", 0.05f, false);

	StateInit();
	PlayCuphead->SetAutoSize(1.0f, true);
	//PlayCuphead->ChangeAnimation("Idle");
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);
	State.Update(_DeltaTime);
	
}




