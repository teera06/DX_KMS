#pragma once
class EngineEditorWindow
{
public:
	// constrcuter destructer
	EngineEditorWindow(); // 디폴트 생성자
	~EngineEditorWindow(); // 디폴트 소멸자

	// delete Function
	EngineEditorWindow(const EngineEditorWindow& _Other) = delete; // 디폴트 복사 생성자
	EngineEditorWindow(EngineEditorWindow&& _Other) noexcept = delete; 
	EngineEditorWindow& operator=(const EngineEditorWindow& _Other) = delete; // 디폴트 대입 연산자
	EngineEditorWindow& operator=(EngineEditorWindow&& _Other) noexcept = delete;

protected:

private:
};

