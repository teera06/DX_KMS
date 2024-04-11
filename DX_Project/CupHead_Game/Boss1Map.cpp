#include "PreCompile.h"
#include "Boss1Map.h"
#include "ContentsENum.h"

ABoss1Map::ABoss1Map()
{
	back1Map = CreateDefaultSubObject<USpriteRenderer>("back1");
	//back3Map = CreateDefaultSubObject<USpriteRenderer>("back3");
}

ABoss1Map::~ABoss1Map()
{
}

void ABoss1Map::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(0.0f, 70.0f,200.0f));
	//DelayCallBack(1.0f, std::bind(&ATitleLogo::RendererOff, this));
	

	back1Map->SetOrder(ERenderOrder::Boss1_back1);
	back1Map->SetSprite("back1.png");
	back1Map->SetSamplering(ETextureSampling::LINEAR);
	back1Map->SetAutoSize(2.0f, true);


	//back3Map->SetOrder(ERenderOrder::Boss1_Back3);
	///back3Map->SetSprite("back3.png");
	//back3Map->SetSamplering(ETextureSampling::LINEAR);
	//back3Map->SetAutoSize(4.0f, true);


	//MapRenderer->CreateAnimation("Hourglass", "Hourglass", 0.05f);

	//MapRenderer->ChangeAnimation("Hourglass");
}

void ABoss1Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
