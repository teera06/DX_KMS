#pragma once
#include <EngineCore/GameMode.h>


class AMainMenuMode : public AGameMode
{
public:
	// constrcuter destructer
	AMainMenuMode(); // ����Ʈ ������
	~AMainMenuMode(); // ����Ʈ �Ҹ���

	// delete Function
	AMainMenuMode(const AMainMenuMode& _Other) = delete; // ����Ʈ ���� ������
	AMainMenuMode(AMainMenuMode&& _Other) noexcept = delete; 
	AMainMenuMode& operator=(const AMainMenuMode& _Other) = delete; // ����Ʈ ���� ������
	AMainMenuMode& operator=(AMainMenuMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

