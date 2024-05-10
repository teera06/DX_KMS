#pragma once
#include <EngineCore/StateManager.h>

class ABoss2Common
{
public:
	// constrcuter destructer
	ABoss2Common(); // ����Ʈ ������
	~ABoss2Common(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss2Common(const ABoss2Common& _Other) = delete; // ����Ʈ ���� ������
	ABoss2Common(ABoss2Common&& _Other) noexcept = delete; 
	ABoss2Common& operator=(const ABoss2Common& _Other) = delete; // ����Ʈ ���� ������
	ABoss2Common& operator=(ABoss2Common&& _Other) noexcept = delete;

	UStateManager Phase1;
	UStateManager Phase2;

	static int GetHp()
	{
		return Hp;
	}

	static void SetHp(const int _Hp)
	{
		Hp = _Hp;
	}
	
	static void addHp(const int _Hp)
	{
		Hp -= _Hp;
	}

	static int Getphasecheck()
	{
		return phasecheck;
	}

	static void SethitCheck(const bool _hitCheck)
	{
		hitCheck = _hitCheck;
	}

protected:
	virtual void Phase1StateInit();

	virtual void AniCreate();

	FVector ColorGet = FVector(0.05f, 0.05f, 0.05f);
	float DamgeColorDelay = 0.25f;

	static int phasecheck;
	static float coolDownTime;
	static int attOrder;
	static bool SkillDestory;

	static bool hitCheck;
private:
	static int Hp;
};

