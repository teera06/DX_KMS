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

	int GetHp() const
	{
		return Hp;
	}

protected:
	virtual void Phase1StateInit();
private:

	int Hp = 100;
};

