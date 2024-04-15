#include "PreCompile.h"
#include "Boss2Map.h"


#include <EngineCore/DefaultSceneComponent.h>

#include <EngineCore/SpriteRenderer.h>
ABoss2Map::ABoss2Map()
{

	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("ScreenEffect");
	back2Map = CreateDefaultSubObject<USpriteRenderer>("back2");
	crowd2 = CreateDefaultSubObject<USpriteRenderer>("crowd2");
	JazzGirls = CreateDefaultSubObject<USpriteRenderer>("JazzGirls");
	Waiter = CreateDefaultSubObject<USpriteRenderer>("Waiter");

	back2Map->SetupAttachment(Root);
	crowd2->SetupAttachment(Root);
	JazzGirls->SetupAttachment(Root);
	Waiter->SetupAttachment(Root);

	crowd2->AddPosition({ -350.0f,-150.0f,0.0f });
	JazzGirls->AddPosition({ 20.0f,-78.0f,0.0f });
	Waiter->AddPosition({ 500.0f,-151.0f,0.0f });
	SetRoot(Root);

	back2Map->SetOrder(ERenderOrder::Boss1_back2);
	back2Map->SetSprite("back2.png");
	back2Map->SetSamplering(ETextureSampling::LINEAR);
	back2Map->SetAutoSize(1.0f, true);

	crowd2->SetOrder(ERenderOrder::Boss1_crowd2);
	crowd2->SetSprite("jazz_crowdB_0001.png");
	crowd2->SetSamplering(ETextureSampling::LINEAR);
	crowd2->SetAutoSize(1.0f, true);

	JazzGirls->SetOrder(ERenderOrder::Boss1_crowd2);
	JazzGirls->SetSprite("jazz_girls_0001.png");
	JazzGirls->SetSamplering(ETextureSampling::LINEAR);
	JazzGirls->SetAutoSize(1.0f, true);

	Waiter->SetOrder(ERenderOrder::Boss1_Waiter);
	Waiter->SetSprite("jazz_girls_0001.png");
	Waiter->SetSamplering(ETextureSampling::LINEAR);
	Waiter->SetAutoSize(1.0f, true);
}

ABoss2Map::~ABoss2Map()
{
}

void ABoss2Map::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(0.0f, 180.0f, 160.0f));

	crowd2->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
	JazzGirls->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
	Waiter->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));
	
	crowd2->CreateAnimation("B", "B", 0.1f);
	crowd2->ChangeAnimation("B");

	JazzGirls->CreateAnimation("Jazz Girls", "Jazz Girls", 0.1f);
	JazzGirls->ChangeAnimation("Jazz Girls");

	Waiter->CreateAnimation("Waiter", "Waiter", 0.1f);
	Waiter->ChangeAnimation("Waiter");
}

void ABoss2Map::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector CheckPos = Waiter->GetWorldPosition(); // Kirby

	switch (checkLR)
	{

	case EDir::Left:
		CheckPos.X -= 30.0f;
		break;
	case EDir::Right:
		CheckPos.X += 30.0f;
		break;
	default:
		break;
	}

	if (CheckPos.iX()<= -700 || CheckPos.iX() >= 700) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		switch (checkLR)
		{

		case EDir::Left:
			checkLR = EDir::Right;
			Dir = FVector::Right;
			Waiter->SetDir(EEngineDir::Left);
			break;
		case EDir::Right:
			checkLR = EDir::Left;
			Dir = FVector::Left;
			Waiter->SetDir(EEngineDir::Right);
			break;
		default:
			break;
		}
	}

	Waiter->AddPosition(Dir * _DeltaTime * speed);
}
