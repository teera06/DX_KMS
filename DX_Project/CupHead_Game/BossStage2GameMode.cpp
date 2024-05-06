#include "PreCompile.h"
#include "BossStage2GameMode.h"


#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>
#include <EngineCore/BlurEffect.h>

#include "ScreenEffect.h"
#include "BossBackMap1.h"
#include "BossBackMap2.h"
#include "PhaseChangeBack.h"

#include "Play_Cuphead.h"
#include "Devil1.h"

#include "DevilTear.h"

#include "Orb_Fire.h"


#include "ContentsENum.h"

ABossStage2GameMode::ABossStage2GameMode()
{
}

ABossStage2GameMode::~ABossStage2GameMode()
{
}

void ABossStage2GameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ABossBackMap1>("BossBackMap1");
	GetWorld()->SpawnActor<ABossBackMap2>("BossBackMap2");
	GetWorld()->SpawnActor<APlay_Cuphead>("Play_Cuphead")->SetGrounYCheck(-300);
	NewDevil1=GetWorld()->SpawnActor<ADevil1>("Devil1");
	//GetWorld()->SpawnActor<ADevilTear>("aaaa");
	//GetWorld()->SpawnActor<AOrb_Fire>("PhaseChangeBack");

	GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect")->SetScreenEffect(EScreenEffect::Iris2);
	GetWorld()->GetLastTarget()->AddEffect<UBlurEffect>();

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



		// Image->SetScale({200, 200});

		// ȭ�鿡 ���� �Ѵ�.
		// Image->SetSprite("HPBar");
		// Image->SetScale();
	}

}

void ABossStage2GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UEngineSound::Update();
}

void ABossStage2GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	BossStageBGM.Off();
	GEngine->DestroyLevel("BossStage2GameMode"); // ����Ǵ� ���� ���� ���� (�� ���� ���� ���� ���� ����)
}

void ABossStage2GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
	BossStageBGM = UEngineSound::SoundPlay("MUS_DevilPhase3.wav");
	BossStageBGM.Loop();
}
