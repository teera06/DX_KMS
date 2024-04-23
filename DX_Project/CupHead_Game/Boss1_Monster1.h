#pragma once
#include <EngineCore/Actor.h>

#include "Boss1Common.h"
class USpriteRenderer;
class Asmallskill;
class Aball;

class ABoss1_Monster1 : public AActor, public ABoss1Common
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ABoss1_Monster1(); // 디폴트 생성자
	~ABoss1_Monster1(); // 디폴트 소멸자

	// delete Function
	ABoss1_Monster1(const ABoss1_Monster1& _Other) = delete; // 디폴트 복사 생성자
	ABoss1_Monster1(ABoss1_Monster1&& _Other) noexcept = delete; 
	ABoss1_Monster1& operator=(const ABoss1_Monster1& _Other) = delete; // 디폴트 대입 연산자
	ABoss1_Monster1& operator=(ABoss1_Monster1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;
	void Phase2StateInit() override;

	void AniCreate() override;
private:
	std::shared_ptr<Asmallskill> NewSkill = nullptr;
	std::shared_ptr<Aball> NewBall = nullptr;

	USpriteRenderer* SmallBoss1 = nullptr;
	UCollision* smallBossCollision = nullptr;

	int smallattcount = 0;
	int ballattcount = 0;
	int Delay = 0;
	int phase2changecount = 0;
	bool att = false;




	void createSkill();
	void SkillYMove();

	void createSkill2();

	// 상태 

	void smallintro(float _DeltaTime);
	void smallIdle(float _DeltaTime);
	void smallattready(float _DeltaTime);
	void smallatt(float _DeltaTime);
	void smallattEnd(float _DeltaTime);


	void phase2changeReady(float _DeltaTime);
	void phase2changeReady2(float _DeltaTime);
	void phase2change1(float _DeltaTime);
	void phase2change2(float _DeltaTime);

	void phase2intro(float _DeltaTime);

	void phase3changeReady(float _DeltaTime);
	void phase3changeReady2(float _DeltaTime);
	void phase3change1(float _DeltaTime);
	void phase3change2(float _DeltaTime);

	void smallatt2Ready1(float _DeltaTime);
	void smallatt2Delay(float _DeltaTime);
	void smallatt2(float _DeltaTime);
};

