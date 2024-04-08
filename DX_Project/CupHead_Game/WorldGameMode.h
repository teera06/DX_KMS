#pragma once
#include <EngineCore/GameMode.h>
class WorldGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	WorldGameMode(); // 디폴트 생성자
	~WorldGameMode(); // 디폴트 소멸자

	// delete Function
	WorldGameMode(const WorldGameMode& _Other) = delete; // 디폴트 복사 생성자
	WorldGameMode(WorldGameMode&& _Other) noexcept = delete; 
	WorldGameMode& operator=(const WorldGameMode& _Other) = delete; // 디폴트 대입 연산자
	WorldGameMode& operator=(WorldGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

