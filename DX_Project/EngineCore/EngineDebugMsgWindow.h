#pragma once
class EngineDebugMsgWindow
{
public:
	// constrcuter destructer
	EngineDebugMsgWindow(); // ����Ʈ ������
	~EngineDebugMsgWindow(); // ����Ʈ �Ҹ���

	// delete Function
	EngineDebugMsgWindow(const EngineDebugMsgWindow& _Other) = delete; // ����Ʈ ���� ������
	EngineDebugMsgWindow(EngineDebugMsgWindow&& _Other) noexcept = delete; 
	EngineDebugMsgWindow& operator=(const EngineDebugMsgWindow& _Other) = delete; // ����Ʈ ���� ������
	EngineDebugMsgWindow& operator=(EngineDebugMsgWindow&& _Other) noexcept = delete;

protected:

private:
};

