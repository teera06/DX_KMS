#pragma once
class EngineEditorGUI
{
public:
	// constrcuter destructer
	EngineEditorGUI(); // 디폴트 생성자
	~EngineEditorGUI(); // 디폴트 소멸자

	// delete Function
	EngineEditorGUI(const EngineEditorGUI& _Other) = delete; // 디폴트 복사 생성자
	EngineEditorGUI(EngineEditorGUI&& _Other) noexcept = delete; 
	EngineEditorGUI& operator=(const EngineEditorGUI& _Other) = delete; // 디폴트 대입 연산자
	EngineEditorGUI& operator=(EngineEditorGUI&& _Other) noexcept = delete;

protected:

private:
};

