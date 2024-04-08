#pragma once
#include <EngineCore/GameMode.h>

class BossStage1 : public AGameMode
{
public:
	// constrcuter destructer
	BossStage1(); // ����Ʈ ������
	~BossStage1(); // ����Ʈ �Ҹ���

	// delete Function
	BossStage1(const BossStage1& _Other) = delete; // ����Ʈ ���� ������
	BossStage1(BossStage1&& _Other) noexcept = delete; 
	BossStage1& operator=(const BossStage1& _Other) = delete; // ����Ʈ ���� ������
	BossStage1& operator=(BossStage1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

