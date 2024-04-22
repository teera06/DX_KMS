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

	static int phasecheck;
	static float coolDownTime;
	static bool attOrder;
	static bool SkillDestory;
protected:
	virtual void Phase1StateInit();

	virtual void AniCreate();
private:
};

