#include "PreCompile.h"
#include "BossStage1GameMode.h"

#include <EngineCore/Camera.h>
#include <EngineCore/BlurEffect.h>
#include "Boss1Map.h"
#include "Boss2Map.h"
#include "Boss3Map.h"
#include "ScreenEffect.h"
#include "Play_Cuphead.h"
#include "Boss1_Monster1.h"
#include "Boss1_Monster2.h"
#include "ContentsHelper.h"

#include "MoveObject1.h"
#include "MoveObject2.h"
#include "MoveObject3.h"


#include "ContentsENum.h"
ABossStage1GameMode::ABossStage1GameMode()
{
}

ABossStage1GameMode::~ABossStage1GameMode()
{
}

void ABossStage1GameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ABoss1Map>("Boss1Map");
	GetWorld()->SpawnActor<ABoss2Map>("Boss2Map");
	GetWorld()->SpawnActor<ABoss3Map>("Boss3Map");
	GetWorld()->SpawnActor<APlay_Cuphead>("Play_Cuphead")->SetGrounYCheck(-270);
	GetWorld()->SpawnActor<ABoss1_Monster1>("Boss1_Monster1");
	GetWorld()->SpawnActor<ABoss1_Monster2>("Boss1_Monster2");
	GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect")->SetScreenEffect(EScreenEffect::Iris);

	//GetWorld()->SpawnActor<AMoveObject>("AMoveObject");
	//GetWorld()->SpawnActor<AMoveObject2>("AMoveObject2");
	//GetWorld()->SpawnActor<AMoveObject1>("AMoveObject1")->SetUpDownSet(FVector::Up);
	//GetWorld()->SpawnActor<AMoveObject1>("AMoveObject1")->SetUpDownSet(FVector::Down);

	GetWorld()->GetLastTarget()->AddEffect<UBlurEffect>();

	{
		// UI�� ����ڴ�.
		HpImage = CreateWidget<UImage>(GetWorld(), "HpBar");

		// �𸮾� �����Ѱ�
		// �𸮾� �ȳ��ɴϴ�.
		HpImage->AddToViewPort(ERenderOrder::HPBar);
		HpImage->SetSprite("HP3.png");
		HpImage->SetAutoSize(1.0f, true);
		HpImage->SetPosition({ -570.0f, -310.0f });

		HpImage ->CreateAnimation("HP1", "HP1", 0.05f);
		HpImage->CreateAnimation("HP0", "HP0", 0.05f);
		

		
		// Image->SetScale({200, 200});

		// ȭ�鿡 ���� �Ѵ�.
		// Image->SetSprite("HPBar");
		// Image->SetScale();
	}

	{
		// UI�� ����ڴ�.
		UImage* Image = CreateWidget<UImage>(GetWorld(), "OldFilter");

		// �𸮾� �����Ѱ�
		// �𸮾� �ȳ��ɴϴ�.
		Image->AddToViewPort(ERenderOrder::Filter);
		Image->SetSprite("cuphead_screen_fx_0000.png");
		Image->SetScale(FVector(1280.0f, 720.0f, 0.0f));
		//Image->SetAutoSize(1.0f, true);

		Image->CreateAnimation("OldFilmEffect", "OldFilmEffect", 0.05f);
		//Image->SetPosition({ -570.0f, -310.0f });
		Image->ChangeAnimation("OldFilmEffect");

	}
}

void ABossStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (APlay_Cuphead::GetHp() == 2)
	{
		HpImage->SetSprite("HP2.png");
	}
	else if (APlay_Cuphead::GetHp() == 1)
	{
		HpImage->ChangeAnimation("HP1");
	}
	else if (APlay_Cuphead::GetHp() <= 0)
	{
		HpImage->ChangeAnimation("HP0");
	}
}

void ABossStage1GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ABossStage1GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
