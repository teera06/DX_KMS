#pragma once
#include <EngineCore/GameMode.h>

class ADevil1;
class UEngineSoundPlayer;

class ABossStage2GameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	ABossStage2GameMode(); // 디폴트 생성자
	~ABossStage2GameMode(); // 디폴트 소멸자

	// delete Function
	ABossStage2GameMode(const ABossStage2GameMode& _Other) = delete; // 디폴트 복사 생성자
	ABossStage2GameMode(ABossStage2GameMode&& _Other) noexcept = delete; 
	ABossStage2GameMode& operator=(const ABossStage2GameMode& _Other) = delete; // 디폴트 대입 연산자
	ABossStage2GameMode& operator=(ABossStage2GameMode&& _Other) noexcept = delete;

protected:
	std::shared_ptr<ADevil1> NewDevil1 = nullptr;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	UEngineSoundPlayer BossStageBGM;
};

