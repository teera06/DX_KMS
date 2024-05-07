#pragma once
#include <EngineCore/Actor.h>

#include "Boss1Common.h"
class USpriteRenderer;
class AFirefly;
class ACoin;
class AMoveObject1;
class AMoveObject2;
class AMoveObject3;

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

	USpriteRenderer* GetRender()
	{
		return BigBoss1;
	}

	USpriteRenderer* GetSlotMouse()
	{
		return SlotMouse;
	}

	USpriteRenderer* GetFrontSlot()
	{
		return FrontSlot;
	}

	void SetSlotTouch(const bool& _SlotTouch)
	{
		SlotTouch = _SlotTouch;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;
	void Phase2StateInit() override;
	void AniCreate() override;
private:
	UEngineSoundPlayer windAttSound;
	UEngineSoundPlayer SlotSound;


	std::shared_ptr<AFirefly> NewFirefly = nullptr;
	std::shared_ptr<ACoin> NewCoin = nullptr;
	std::shared_ptr<AMoveObject1> NewMoveObject1 = nullptr;
	std::shared_ptr<AMoveObject2> NewMoveObject2 = nullptr;
	std::shared_ptr<AMoveObject3> NewMoveObject3 = nullptr;

	USpriteRenderer* BigBoss1 = nullptr;
	USpriteRenderer* SlotMouse = nullptr;
	USpriteRenderer* FrontSlot = nullptr;

	USpriteRenderer* SlotImage1 = nullptr;
	USpriteRenderer* SlotImage2 = nullptr;
	USpriteRenderer* SlotImage3 = nullptr;

	USpriteRenderer* WindSkill = nullptr;

	UCollision* BigBossCollision = nullptr;
	UCollision* HandCollision = nullptr;
	UCollision* WindCollision = nullptr;

	float4 VertexY = float4::Zero;
	float4 VertexY1 = float4::Zero;
	float4 VertexY2 = float4::Zero;

	float RandomSkillDelay = 0;

	float att1Delay = 0.4f;

	float WindSpeed = 350.0f;

	float SlotSpeed = 3.0f;
	float SlotSpeed2 = 6.0f;
	float SlotSpeed3 = 9.0f;

	float DamgeColorDelay = 0.35f;

	int Bigattcount = 0;

	int SlotAttCount = 0;
	bool ISSlotSpeed = 0;


	bool Change3 = false;

	bool SlotTouch = false;

	void createSkill();

	void createCoinAtt();

	void createObject();

	void WindCollisioncheck(float _DeltaTime);
	void Phase3Collisioncheck();

	void SlotStartImage(float _DeltaTime);

	// 상태
	void bigintro(float _DeltaTime);
	void bigIdle(float _DeltaTime);

	void bigattReady1(float _DeltaTime);
	void bigattReady2(float _DeltaTime);
	void bigatt(float _DeltaTime);
	void bigattEnd(float _DeltaTime);

	void bigatt2Ready(float _DeltaTime);
	void bigatt2Ready2(float _DeltaTime);
	void bigatt2(float _DeltaTime);
	void bigatt2end(float _DeltaTime);

	void phase3changeReady1(float _DeltaTime);
	void phase3changeReady2(float _DeltaTime);


	void phase3Intro(float _DeltaTime);
	void phase3Intro2(float _DeltaTime);
	void phase3Idle(float _DeltaTime);
	void CoinAtt(float _DeltaTime);

	void Phase3SlotReady(float _DeltaTime);

	void Phase3Slot(float _DeltaTime);
	void Phase3SlotCoinAtt(float _DeltaTime);
	void Phase3SlotStart(float _DeltaTime);

	void Phase3AttReady(float _DeltaTime);
	void Phase3Att(float _DeltaTime);
	void Phase3AttEnd(float _DeltaTime);

	void DieTransition(float _DeltaTime);
	void LastDie(float _DeltaTime);

};

