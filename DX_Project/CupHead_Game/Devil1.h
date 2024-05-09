#pragma once

#include <EngineCore/Actor.h>

#include "Boss2Common.h"

class USpriteRenderer;
class AHeadAtt;
class ARamArms;
class ADevilBall;
class ASpiderHead;
class AOrb_Fire;
class AOrb_Fire2;

class ADevil1 : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevil1(); // 디폴트 생성자
	~ADevil1(); // 디폴트 소멸자

	// delete Function
	ADevil1(const ADevil1& _Other) = delete; // 디폴트 복사 생성자
	ADevil1(ADevil1&& _Other) noexcept = delete; 
	ADevil1& operator=(const ADevil1& _Other) = delete; // 디폴트 대입 연산자
	ADevil1& operator=(ADevil1&& _Other) noexcept = delete;

	USpriteRenderer* GetBoss2Render()
	{
		return Boss2;
	}

	USpriteRenderer* GetBossHead()
	{
		return BossHead;
	}

	USpriteRenderer* GetBossBody()
	{
		return BossBody;
	}

	USpriteRenderer* Getspear()
	{
		return spear;
	}

	void SetDieTime(const float& _DieTime)
	{
		DieTime = _DieTime;
	}
	

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void Phase1StateInit() override;

	void AniCreate() override;
private:
	UEngineSoundPlayer BossStage1BGM;

	std::shared_ptr<AHeadAtt> NewHeadAtt = nullptr;
	std::shared_ptr<ARamArms> NewRamArmsL = nullptr;
	std::shared_ptr<ARamArms> NewRamArmsR = nullptr;
	std::shared_ptr<ASpiderHead> NewSpiderHead = nullptr;

	std::vector<std::shared_ptr<ADevilBall>>  NewDevilBalls;
	std::vector<std::shared_ptr<AOrb_Fire>> NewFireS;

	std::shared_ptr<AOrb_Fire2> NewFire2;

	USpriteRenderer* IntroAni = nullptr;
	USpriteRenderer* PhaseChange2 = nullptr;
	USpriteRenderer* Boss2 = nullptr;
	USpriteRenderer* BossHead = nullptr;
	USpriteRenderer* BossBody = nullptr;
	USpriteRenderer* spear = nullptr;

	UCollision* Devil1 = nullptr;
	UCollision* Boss2Phase2 = nullptr;

	float DieTime = -2.0f;

	int OrbOrder = 1;
	int attcount = 0;

	bool OneCheck = false;
	bool Die=false;

	void CreateHeadAtt();
	void CreateRamArms();
	void CreateSpider();
	void CreateBall();
	void CreateFire();
	void CreateFire2();

	// 여기서부터는 상태 함수들 
	void Phase1Intro(float _DeltaTime);
	void Phase1Idle(float _DeltaTime);
	void DragonTransform(float _DeltaTime);
	void DragonIdle(float _DeltaTime);
	void DragonReverse(float _DeltaTime);

	void RamTransform(float _DeltaTime);
	void RamIdle(float _DeltaTime);
	void RamReverse(float _DeltaTime);

	void SpiderTransform(float _DeltaTime);
	void SpiderIdle(float _DeltaTime);
	void SpiderReverse(float _DeltaTime);

	void CreateOrbsIntro(float _DeltaTime);
	void CreateOrbsIntro2(float _DeltaTime);
	void CreateOrbsReverse(float _DeltaTime);

	void Phase1Death(float _DeltaTime);
	void Phase2Change(float _DeltaTime);

};

