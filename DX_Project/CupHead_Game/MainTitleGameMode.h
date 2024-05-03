#pragma once
#include <EngineCore/GameMode.h>

class AScreenEffect;
class UEngineSoundPlayer;

class AMainTitleGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	AMainTitleGameMode(); // ����Ʈ ������
	~AMainTitleGameMode(); // ����Ʈ �Ҹ���

	// delete Function
	AMainTitleGameMode(const AMainTitleGameMode& _Other) = delete; // ����Ʈ ���� ������
	AMainTitleGameMode(AMainTitleGameMode&& _Other) noexcept = delete; 
	AMainTitleGameMode& operator=(const AMainTitleGameMode& _Other) = delete; // ����Ʈ ���� ������
	AMainTitleGameMode& operator=(AMainTitleGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	 
	void LevelEnd(ULevel* _NextLevel);
	void LevelStart(ULevel* _PrevLevel);
private:

	UEngineSoundPlayer titleBGM;
	std::shared_ptr<AScreenEffect> NewScreenEffect = nullptr;


	bool onecheck = false;
	void CreateActor();
};

