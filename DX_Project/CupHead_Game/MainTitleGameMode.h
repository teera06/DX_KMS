#pragma once
#include <EngineCore/GameMode.h>

class AScreenEffect;
class UEngineSoundPlayer;

class AMainTitleGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)
public:
	// constrcuter destructer
	AMainTitleGameMode(); // 디폴트 생성자
	~AMainTitleGameMode(); // 디폴트 소멸자

	// delete Function
	AMainTitleGameMode(const AMainTitleGameMode& _Other) = delete; // 디폴트 복사 생성자
	AMainTitleGameMode(AMainTitleGameMode&& _Other) noexcept = delete; 
	AMainTitleGameMode& operator=(const AMainTitleGameMode& _Other) = delete; // 디폴트 대입 연산자
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

