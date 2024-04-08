#pragma once
#include <EngineCore/GameMode.h>
class WorldGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	WorldGameMode(); // ����Ʈ ������
	~WorldGameMode(); // ����Ʈ �Ҹ���

	// delete Function
	WorldGameMode(const WorldGameMode& _Other) = delete; // ����Ʈ ���� ������
	WorldGameMode(WorldGameMode&& _Other) noexcept = delete; 
	WorldGameMode& operator=(const WorldGameMode& _Other) = delete; // ����Ʈ ���� ������
	WorldGameMode& operator=(WorldGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

