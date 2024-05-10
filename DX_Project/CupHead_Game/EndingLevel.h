#pragma once
#include <EngineCore/GameMode.h>

class AEndingLevel : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	AEndingLevel(); // 디폴트 생성자
	~AEndingLevel(); // 디폴트 소멸자

	// delete Function
	AEndingLevel(const AEndingLevel& _Other) = delete; // 디폴트 복사 생성자
	AEndingLevel(AEndingLevel&& _Other) noexcept = delete; 
	AEndingLevel& operator=(const AEndingLevel& _Other) = delete; // 디폴트 대입 연산자
	AEndingLevel& operator=(AEndingLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	UEngineSoundPlayer BGM;
};

