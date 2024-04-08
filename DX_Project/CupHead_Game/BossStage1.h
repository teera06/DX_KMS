#pragma once
#include <EngineCore/GameMode.h>

class BossStage1 : public AGameMode
{
public:
	// constrcuter destructer
	BossStage1(); // 디폴트 생성자
	~BossStage1(); // 디폴트 소멸자

	// delete Function
	BossStage1(const BossStage1& _Other) = delete; // 디폴트 복사 생성자
	BossStage1(BossStage1&& _Other) noexcept = delete; 
	BossStage1& operator=(const BossStage1& _Other) = delete; // 디폴트 대입 연산자
	BossStage1& operator=(BossStage1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

