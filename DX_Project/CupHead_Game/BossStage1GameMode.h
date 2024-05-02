#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/Image.h>


class ABossStage1GameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	ABossStage1GameMode(); // 디폴트 생성자
	~ABossStage1GameMode(); // 디폴트 소멸자

	// delete Function
	ABossStage1GameMode(const ABossStage1GameMode& _Other) = delete; // 디폴트 복사 생성자
	ABossStage1GameMode(ABossStage1GameMode&& _Other) noexcept = delete; 
	ABossStage1GameMode& operator=(const ABossStage1GameMode& _Other) = delete; // 디폴트 대입 연산자
	ABossStage1GameMode& operator=(ABossStage1GameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:

};

