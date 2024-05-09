#pragma once
#include <EngineCore/StateManager.h>

class ABoss2Common
{
public:
	// constrcuter destructer
	ABoss2Common(); // 디폴트 생성자
	~ABoss2Common(); // 디폴트 소멸자

	// delete Function
	ABoss2Common(const ABoss2Common& _Other) = delete; // 디폴트 복사 생성자
	ABoss2Common(ABoss2Common&& _Other) noexcept = delete; 
	ABoss2Common& operator=(const ABoss2Common& _Other) = delete; // 디폴트 대입 연산자
	ABoss2Common& operator=(ABoss2Common&& _Other) noexcept = delete;

	UStateManager Phase1;
	UStateManager Phase2;

	static int GetHp()
	{
		return Hp;
	}

	static void SetHp(int _Hp)
	{
		Hp = _Hp;
	}

	static int Getphasecheck()
	{
		return phasecheck;
	}

	static void SethitCheck(bool _hitCheck)
	{
		hitCheck = _hitCheck;
	}

protected:
	virtual void Phase1StateInit();

	virtual void AniCreate();

	float DamgeColorDelay = 0.25f;

	static int phasecheck;
	static float coolDownTime;
	static int attOrder;
	static bool SkillDestory;

	static bool hitCheck;
private:
	static int Hp;
};

