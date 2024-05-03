#pragma once
#include <EngineCore/GameMode.h>

class UEngineSoundPlayer;
class AWorldGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	AWorldGameMode(); // ����Ʈ ������
	~AWorldGameMode(); // ����Ʈ �Ҹ���

	// delete Function
	AWorldGameMode(const AWorldGameMode& _Other) = delete; // ����Ʈ ���� ������
	AWorldGameMode(AWorldGameMode&& _Other) noexcept = delete; 
	AWorldGameMode& operator=(const AWorldGameMode& _Other) = delete; // ����Ʈ ���� ������
	AWorldGameMode& operator=(AWorldGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	UEngineSoundPlayer WorldBGM;
};

