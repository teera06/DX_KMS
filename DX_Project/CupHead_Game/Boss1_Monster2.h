#pragma once
#include <EngineCore/Actor.h>

#include "Boss1Common.h"
class USpriteRenderer;
class AFirefly;

class ABoss1_Monster2 : public AActor, public ABoss1Common
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss1_Monster2(); // 디폴트 생성자
	~ABoss1_Monster2(); // 디폴트 소멸자

	// delete Function
	ABoss1_Monster2(const ABoss1_Monster2& _Other) = delete; // 디폴트 복사 생성자
	ABoss1_Monster2(ABoss1_Monster2&& _Other) noexcept = delete; 
	ABoss1_Monster2& operator=(const ABoss1_Monster2& _Other) = delete; // 디폴트 대입 연산자
	ABoss1_Monster2& operator=(ABoss1_Monster2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;
	void Phase2StateInit() override;
private:
	std::shared_ptr<AFirefly> NewFirefly = nullptr;

	USpriteRenderer* BigBoss1 = nullptr;

	USpriteRenderer* WindSkill = nullptr;

	UCollision* BigBossCollision = nullptr;
	UCollision* WindCollision = nullptr;

	float RandomSkillDelay = 0;


	int Bigattcount = 0;
	int phase3changecount = 0;


	bool Change3 = false;

	void createSkill();

	void Collisioncheck();

	// 상태
	void bigintro(float _DeltaTime);
	void bigIdle(float _DeltaTime);

	void bigatt(float _DeltaTime);

	void bigatt2Ready(float _DeltaTime);
	void bigatt2Ready2(float _DeltaTime);
	void bigatt2(float _DeltaTime);
	void bigatt2end(float _DeltaTime);

	void phase3changeReady1(float _DeltaTime);
	void phase3changeReady2(float _DeltaTime);


	void phase3Intro(float _DeltaTime);
	void phase3Idle(float _DeltaTime);

};

