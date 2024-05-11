#include "PreCompile.h"
#include "EndingLevel.h"
#include "EndingActor.h"

#include <EngineCore/BlurEffect.h>

AEndingLevel::AEndingLevel()
{
}

AEndingLevel::~AEndingLevel()
{
}

void AEndingLevel::BeginPlay()
{
	Super::BeginPlay();
	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	GetWorld()->SpawnActor<AEndingActor>("Ending");
	GetWorld()->GetLastTarget()->AddEffect<UBlurEffect>();
}

void AEndingLevel::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	UEngineSound::Update();
}

void AEndingLevel::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	GEngine->DestroyLevel("EndingLevel"); // ����Ǵ� ���� ���� ���� (�� ���� ���� ���� ���� ����)
}

void AEndingLevel::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
