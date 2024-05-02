#include "PreCompile.h"
#include "Boss2Phase2Map.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>


#include "ContentsENum.h"

#include "PokerChip.h"
#include "DevilPlatform.h"

ABoss2Phase2Map::ABoss2Phase2Map()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Boss2Phase2Map");
	Boss2Phase2Map = CreateDefaultSubObject<USpriteRenderer>("Boss2Phase2Map");
	
	Boss2Phase2Map->SetupAttachment(Root);
	
	Boss2Phase2Map->SetOrder(ERenderOrder::Boss1_back3);
	Boss2Phase2Map->SetSprite("BossDevil_Phase1Background.png");
	Boss2Phase2Map->SetSamplering(ETextureSampling::LINEAR);
	Boss2Phase2Map->SetAutoSize(1.2f, true);

	
	SetRoot(Root);
}

ABoss2Phase2Map::~ABoss2Phase2Map()
{
}

void ABoss2Phase2Map::BeginPlay()
{
	Super::BeginPlay();

	Boss2Phase2Map->SetScale(FVector(1280.0f, 720.0f, 0.0f));
	Boss2Phase2Map->CreateAnimation("LastMap", "BossDevil_Phase1Background.png", 0.01f,false, 4, 5);

	Boss2Phase2Map->ChangeAnimation("LastMap");


	SetActorLocation(FVector(0.0f, 0.0f, 200.0f));
}

void ABoss2Phase2Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (ADevilPlatform::GetPhaseCount() == 1)
	{
		CreateChip1(_DeltaTime);
	}
	else if (ADevilPlatform::GetPhaseCount() == 2)
	{
		if (false == OneCheck1)
		{
			OneCheck1 = true;
			order = 1;
		}
		CreateChip2(_DeltaTime);
	}
	else if (ADevilPlatform::GetPhaseCount() == 3)
	{
		CreateChip3(_DeltaTime);
	}
}

void ABoss2Phase2Map::CreateChip1(float _DeltaTime)
{
	Delay -= _DeltaTime;

	if (Delay < 0)
	{
		if (order == 1)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(580.0f, 500.0f, 10.0f));
		}
		else if (order == 2)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(290.0f, 500.0f, 10.0f));
		}
		else if (order == 3)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(0.0f, 500.0f, 10.0f));
		}
		else if (order == 4)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(-290.0f, 500.0f, 10.0f));
		}
		else if (order == 5)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(-580.0f, 500.0f, 10.0f));
		}
		else if (order == 6 || order == 0) {
			Add *= -1;
		}

		order += Add;
		Delay = 4.0f;
	}
}

void ABoss2Phase2Map::CreateChip2(float _DeltaTime)
{
	Delay -= _DeltaTime;

	if (Delay < 0)
	{
		if (order == 1)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(290.0f, 500.0f, 10.0f));
		}
		else if (order == 2)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(0.0f, 500.0f, 10.0f));
		}
		else if (order == 3)
		{
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(-290.0f, 500.0f, 10.0f));
		}
		else if (order == 4 || order == 0) {
			Add *= -1;
		}

		order += Add;
		Delay = 4.0f;
	}

}

void ABoss2Phase2Map::CreateChip3(float _DeltaTime)
{
	Delay -= _DeltaTime;

	if (Delay < 0)
	{
		GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(0.0f, 500.0f, 10.0f));
		Delay = 4.0f;
	}
}
