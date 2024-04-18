#include "PreCompile.h"
#include "BossStage1GameMode.h"

#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>

#include "Boss1Map.h"
#include "Boss2Map.h"
#include "Boss3Map.h"
#include "ScreenEffect.h"
#include "Play_Cuphead.h"
#include "Boss1_Monster1.h"
#include "Boss1_Monster2.h"
#include "ContentsHelper.h"

#include "Coin.h"




ABossStage1GameMode::ABossStage1GameMode()
{
}

ABossStage1GameMode::~ABossStage1GameMode()
{
}

void ABossStage1GameMode::BeginPlay()
{
	Super::BeginPlay();
	UContentsHelper::MapTex = UEngineTexture::FindRes("back3back.png");
	UContentsHelper::MapTexScale = UContentsHelper::MapTex->GetScale();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<ABoss1Map>("Boss1Map");
	GetWorld()->SpawnActor<ABoss2Map>("Boss2Map");
	GetWorld()->SpawnActor<ABoss3Map>("Boss3Map");
	GetWorld()->SpawnActor<APlay_Cuphead>("Play_Cuphead");
	GetWorld()->SpawnActor<ABoss1_Monster1>("Boss1_Monster1");
	GetWorld()->SpawnActor<ABoss1_Monster2>("Boss1_Monster2");
	GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");

	GetWorld()->SpawnActor<ACoin>("Coin");

	{
		// UI를 만들겠다.
		std::shared_ptr<UImage> Image = CreateWidget<UImage>(GetWorld(), "HpBar");

		// 언리얼 따라한것
		// 언리얼 안나옵니다.
		Image->AddToViewPort();
		Image->SetSprite("HP3.png");
		Image->SetAutoSize(1.0f, true);
		Image->SetPosition({ -570.0f, -310.0f });

		

		
		// Image->SetScale({200, 200});

		// 화면에 떠야 한다.
		// Image->SetSprite("HPBar");
		// Image->SetScale();
	}
}

void ABossStage1GameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ABossStage1GameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ABossStage1GameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
