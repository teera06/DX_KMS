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

	UStateManager State;
protected:
private:
};

