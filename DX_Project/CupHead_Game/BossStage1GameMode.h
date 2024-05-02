#pragma once
#include <EngineCore/GameMode.h>
#include <EngineCore/Image.h>


class ABossStage1GameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	ABossStage1GameMode(); // ����Ʈ ������
	~ABossStage1GameMode(); // ����Ʈ �Ҹ���

	// delete Function
	ABossStage1GameMode(const ABossStage1GameMode& _Other) = delete; // ����Ʈ ���� ������
	ABossStage1GameMode(ABossStage1GameMode&& _Other) noexcept = delete; 
	ABossStage1GameMode& operator=(const ABossStage1GameMode& _Other) = delete; // ����Ʈ ���� ������
	ABossStage1GameMode& operator=(ABossStage1GameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:

};

