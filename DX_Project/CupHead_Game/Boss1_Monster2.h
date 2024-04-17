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
private:
	std::shared_ptr<AFirefly> NewFirefly = nullptr;

	USpriteRenderer* BigBoss1 = nullptr;

	int Bigattcount = 0;
	float RandomSkillDelay = 0;


	void createSkill();

	void bigintro(float _DeltaTime);
	void bigIdle(float _DeltaTime);
	void bigatt(float _DeltaTime);
};

