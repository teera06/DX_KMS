#pragma once
#include <EngineCore/GameMode.h>
#include <map>

class UEngineDirectory;
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

	static std::map<std::string, bool> LoadMap;

	static bool CreateLevelCheck1;
	static bool CreateLevelCheck2;
	static bool CreateLevelCheck3;

	void WorldLoad();
	void Boss1Load();
	void Boss2Load();
};

