#pragma once
#include <EngineCore/GameMode.h>
class MainTitleGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	MainTitleGameMode(); // ����Ʈ ������
	~MainTitleGameMode(); // ����Ʈ �Ҹ���

	// delete Function
	MainTitleGameMode(const MainTitleGameMode& _Other) = delete; // ����Ʈ ���� ������
	MainTitleGameMode(MainTitleGameMode&& _Other) noexcept = delete; 
	MainTitleGameMode& operator=(const MainTitleGameMode& _Other) = delete; // ����Ʈ ���� ������
	MainTitleGameMode& operator=(MainTitleGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
};

