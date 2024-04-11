#pragma once
class EngineDebugMsgWindow
{
public:
	// constrcuter destructer
	EngineDebugMsgWindow(); // 디폴트 생성자
	~EngineDebugMsgWindow(); // 디폴트 소멸자

	// delete Function
	EngineDebugMsgWindow(const EngineDebugMsgWindow& _Other) = delete; // 디폴트 복사 생성자
	EngineDebugMsgWindow(EngineDebugMsgWindow&& _Other) noexcept = delete; 
	EngineDebugMsgWindow& operator=(const EngineDebugMsgWindow& _Other) = delete; // 디폴트 대입 연산자
	EngineDebugMsgWindow& operator=(EngineDebugMsgWindow&& _Other) noexcept = delete;

protected:

private:
};

