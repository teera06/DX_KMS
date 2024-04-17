#pragma once
#include <EngineCore/StateManager.h>

class ABoss1Common
{
public:
	// constrcuter destructer
	ABoss1Common(); // 디폴트 생성자
	~ABoss1Common(); // 디폴트 소멸자

	// delete Function
	ABoss1Common(const ABoss1Common& _Other) = delete; // 디폴트 복사 생성자
	ABoss1Common(ABoss1Common&& _Other) noexcept = delete;
	ABoss1Common& operator=(const ABoss1Common& _Other) = delete; // 디폴트 대입 연산자
	ABoss1Common& operator=(ABoss1Common&& _Other) noexcept = delete;

	UStateManager Phase1;
	UStateManager Phase2;

	static int GetHp()
	{
		return Hp;
	}

	static void SetHp(const int& _Hp)
	{
		Hp=_Hp;
	}
	static int phasecheck;
	static float coolDownTime;
	static bool attOrder;
protected:
	virtual void Phase1StateInit();
	virtual void Phase2StateInit();

	virtual void AniCreate();
private:

	static int Hp;
};

