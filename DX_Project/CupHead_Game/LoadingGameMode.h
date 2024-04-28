#pragma once
#include <EngineCore/GameMode.h>
#include <map>

class UEngineDirectory;
class ALoadingGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	ALoadingGameMode(); // 디폴트 생성자
	~ALoadingGameMode(); // 디폴트 소멸자

	// delete Function
	ALoadingGameMode(const ALoadingGameMode& _Other) = delete; // 디폴트 복사 생성자
	ALoadingGameMode(ALoadingGameMode&& _Other) noexcept = delete; 
	ALoadingGameMode& operator=(const ALoadingGameMode& _Other) = delete; // 디폴트 대입 연산자
	ALoadingGameMode& operator=(ALoadingGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:
	float coolDowntime = 6.0f;

	static std::map<std::string, bool> LoadMap;

	std::atomic_int CommonCount1 = -1;
	std::atomic_int CommonCount2 = -1;

	std::atomic_int CommonSubLoad1 = -1;
	std::atomic_int CommonSubLoad2 = -1;



	std::atomic_int MainLoadCount=-1;
	std::atomic_int MainLoadCount2 = -1;
	std::atomic_int MainLoadCount3 = -1;

	std::atomic_int SubWorldCount = -1;

	// Boss1
	std::atomic_int SubFolderCount=-1;
	std::atomic_int SubFolderCount2 = -1;
	std::atomic_int SubFolderCount3 = -1;
	std::atomic_int SubFolderCount4 = -1;

	// Boss2
	std::atomic_int SubFolder2Count = -1;
	std::atomic_int SubFolder2Count2 = -1;
	std::atomic_int SubFolder2Count3 = -1;

	static bool CreatePlayer;
	static bool CreateLevelCheck1;
	static bool CreateLevelCheck2;
	static bool CreateLevelCheck3;

	// 공통 로드 목록
	void MainPlayerLoad();
	void PlayerFolderLoad();

	// World Map Load
	void MainWorldLoad();
	void FolderWorldLoad();

	// Boss1 Load
	void MainBoss1Load();
	void FolderBoss1Load();
	
	// Boss2 Load
	void MainBoss2Load();
	void FolderBoss2Load();

	void LastPlayerLoad();
	void LastWorldLoad();
	void LastBoss1Load();
	void LastBoss2Load();

};

