#pragma once
#include <EngineCore/GameMode.h>


class AMainMenuMode : public AGameMode
{
public:
	// constrcuter destructer
	AMainMenuMode(); // 디폴트 생성자
	~AMainMenuMode(); // 디폴트 소멸자

	// delete Function
	AMainMenuMode(const AMainMenuMode& _Other) = delete; // 디폴트 복사 생성자
	AMainMenuMode(AMainMenuMode&& _Other) noexcept = delete; 
	AMainMenuMode& operator=(const AMainMenuMode& _Other) = delete; // 디폴트 대입 연산자
	AMainMenuMode& operator=(AMainMenuMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

