#pragma once
#include <EngineCore/StateManager.h>

class ABoss1Common
{
public:
	// constrcuter destructer
	ABoss1Common(); // ����Ʈ ������
	~ABoss1Common(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss1Common(const ABoss1Common& _Other) = delete; // ����Ʈ ���� ������
	ABoss1Common(ABoss1Common&& _Other) noexcept = delete;
	ABoss1Common& operator=(const ABoss1Common& _Other) = delete; // ����Ʈ ���� ������
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

