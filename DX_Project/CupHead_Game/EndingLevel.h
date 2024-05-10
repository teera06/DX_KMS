#pragma once
#include <EngineCore/GameMode.h>

class AEndingLevel : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	AEndingLevel(); // ����Ʈ ������
	~AEndingLevel(); // ����Ʈ �Ҹ���

	// delete Function
	AEndingLevel(const AEndingLevel& _Other) = delete; // ����Ʈ ���� ������
	AEndingLevel(AEndingLevel&& _Other) noexcept = delete; 
	AEndingLevel& operator=(const AEndingLevel& _Other) = delete; // ����Ʈ ���� ������
	AEndingLevel& operator=(AEndingLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	UEngineSoundPlayer BGM;
};

