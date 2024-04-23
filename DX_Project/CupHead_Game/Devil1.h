#pragma once

#include <EngineCore/Actor.h>

#include "Boss2Common.h"
class USpriteRenderer;
class AHeadAtt;
class ARamArms;
class ASpiderHead;

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void Phase1StateInit() override;

	void AniCreate() override;
private:
	std::shared_ptr<AHeadAtt> NewHeadAtt = nullptr;
	std::shared_ptr<ARamArms> NewRamArmsL = nullptr;
	std::shared_ptr<ARamArms> NewRamArmsR = nullptr;
	std::shared_ptr<ASpiderHead> NewSpiderHead = nullptr;

	USpriteRenderer* Boss2 = nullptr;
	USpriteRenderer* BossHead = nullptr;
	USpriteRenderer* BossBody = nullptr;


	void CreateHeadAtt();
	void CreateRamArms();
	void CreateSpider();

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

};

