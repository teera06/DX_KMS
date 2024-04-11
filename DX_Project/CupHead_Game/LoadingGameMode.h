#pragma once
#include <EngineCore/GameMode.h>
class ALoadingGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	ALoadingGameMode(); // ����Ʈ ������
	~ALoadingGameMode(); // ����Ʈ �Ҹ���

	// delete Function
	ALoadingGameMode(const ALoadingGameMode& _Other) = delete; // ����Ʈ ���� ������
	ALoadingGameMode(ALoadingGameMode&& _Other) noexcept = delete; 
	ALoadingGameMode& operator=(const ALoadingGameMode& _Other) = delete; // ����Ʈ ���� ������
	ALoadingGameMode& operator=(ALoadingGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	float coolDowntime = 6.0f;
};

