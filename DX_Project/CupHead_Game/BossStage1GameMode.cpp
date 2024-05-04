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
		// UI를 만들겠다.
		UImage* Image = CreateWidget<UImage>(GetWorld(), "OldFilter");

		// 언리얼 따라한것
		// 언리얼 안나옵니다.
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
	UEngineSound::Update();
}

void ABossStage1GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	BossStageBGM.Off();
}

void ABossStage1GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	UEngineSound::SoundPlay("sfx_level_announcer_0001_a.wav");
	BossStageBGM = UEngineSound::SoundPlay("Boss1BGM.mp3");
	BossStageBGM.Loop();
}
