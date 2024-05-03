#pragma once
#include <EngineCore/GameMode.h>

class UEngineSoundPlayer;
class AWorldGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	AWorldGameMode(); // 디폴트 생성자
	~AWorldGameMode(); // 디폴트 소멸자

	// delete Function
	AWorldGameMode(const AWorldGameMode& _Other) = delete; // 디폴트 복사 생성자
	AWorldGameMode(AWorldGameMode&& _Other) noexcept = delete; 
	AWorldGameMode& operator=(const AWorldGameMode& _Other) = delete; // 디폴트 대입 연산자
	AWorldGameMode& operator=(AWorldGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	UEngineSoundPlayer WorldBGM;
};

