#pragma once
#include <EngineCore/GameMode.h>

class BossStage2GameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	BossStage2GameMode(); // 디폴트 생성자
	~BossStage2GameMode(); // 디폴트 소멸자

	// delete Function
	BossStage2GameMode(const BossStage2GameMode& _Other) = delete; // 디폴트 복사 생성자
	BossStage2GameMode(BossStage2GameMode&& _Other) noexcept = delete; 
	BossStage2GameMode& operator=(const BossStage2GameMode& _Other) = delete; // 디폴트 대입 연산자
	BossStage2GameMode& operator=(BossStage2GameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

