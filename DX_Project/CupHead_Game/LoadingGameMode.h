#pragma once
#include <EngineCore/GameMode.h>
class ALoadingGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	ALoadingGameMode(); // 디폴트 생성자
	~ALoadingGameMode(); // 디폴트 소멸자

	// delete Function
	ALoadingGameMode(const ALoadingGameMode& _Other) = delete; // 디폴트 복사 생성자
	ALoadingGameMode(ALoadingGameMode&& _Other) noexcept = delete; 
	ALoadingGameMode& operator=(const ALoadingGameMode& _Other) = delete; // 디폴트 대입 연산자
	ALoadingGameMode& operator=(ALoadingGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	float coolDowntime = 6.0f;
};

