#pragma once
#include <EngineCore/Actor.h>

#include "Boss1Common.h"
class USpriteRenderer;
class ACoin;
class AMoveObject1;
class AMoveObject2;
class AMoveObject3;

class ASlotBoss1 : public AActor, public ABoss1Common
{
public:
	// constrcuter destructer
	ASlotBoss1(); // 디폴트 생성자
	~ASlotBoss1(); // 디폴트 소멸자

	// delete Function
	ASlotBoss1(const ASlotBoss1& _Other) = delete; // 디폴트 복사 생성자
	ASlotBoss1(ASlotBoss1&& _Other) noexcept = delete; 
	ASlotBoss1& operator=(const ASlotBoss1& _Other) = delete; // 디폴트 대입 연산자
	ASlotBoss1& operator=(ASlotBoss1&& _Other) noexcept = delete;

	void SetSlotTouch(const bool& _SlotTouch)
	{
		SlotTouch = _SlotTouch;
	}
protected:
	void Phase1StateInit()override;
private:
	std::shared_ptr<AMoveObject1> NewMoveObject1 = nullptr;
	std::shared_ptr<AMoveObject2> NewMoveObject2 = nullptr;
	std::shared_ptr<AMoveObject3> NewMoveObject3 = nullptr;

	USpriteRenderer* SlotMouse = nullptr;

	USpriteRenderer* SlotImage1 = nullptr;
	USpriteRenderer* SlotImage2 = nullptr;
	USpriteRenderer* SlotImage3 = nullptr;

	USpriteRenderer* SlotBoss1 = nullptr;

	int SlotAttCount = 0;

	bool SlotTouch = false;

	void createObject();

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
};

