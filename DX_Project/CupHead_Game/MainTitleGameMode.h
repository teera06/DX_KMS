#pragma once
#include <EngineCore/GameMode.h>
class MainTitleGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	MainTitleGameMode(); // 디폴트 생성자
	~MainTitleGameMode(); // 디폴트 소멸자

	// delete Function
	MainTitleGameMode(const MainTitleGameMode& _Other) = delete; // 디폴트 복사 생성자
	MainTitleGameMode(MainTitleGameMode&& _Other) noexcept = delete; 
	MainTitleGameMode& operator=(const MainTitleGameMode& _Other) = delete; // 디폴트 대입 연산자
	MainTitleGameMode& operator=(MainTitleGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

