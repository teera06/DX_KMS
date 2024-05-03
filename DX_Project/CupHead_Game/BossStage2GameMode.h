#pragma once
#include <EngineCore/GameMode.h>

class ADevil1;
class UEngineSoundPlayer;

class ABossStage2GameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	ABossStage2GameMode(); // ����Ʈ ������
	~ABossStage2GameMode(); // ����Ʈ �Ҹ���

	// delete Function
	ABossStage2GameMode(const ABossStage2GameMode& _Other) = delete; // ����Ʈ ���� ������
	ABossStage2GameMode(ABossStage2GameMode&& _Other) noexcept = delete; 
	ABossStage2GameMode& operator=(const ABossStage2GameMode& _Other) = delete; // ����Ʈ ���� ������
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

