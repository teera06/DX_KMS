#pragma once
class EngineEditorWindow
{
public:
	// constrcuter destructer
	EngineEditorWindow(); // ����Ʈ ������
	~EngineEditorWindow(); // ����Ʈ �Ҹ���

	// delete Function
	EngineEditorWindow(const EngineEditorWindow& _Other) = delete; // ����Ʈ ���� ������
	EngineEditorWindow(EngineEditorWindow&& _Other) noexcept = delete; 
	EngineEditorWindow& operator=(const EngineEditorWindow& _Other) = delete; // ����Ʈ ���� ������
	EngineEditorWindow& operator=(EngineEditorWindow&& _Other) noexcept = delete;

protected:

private:
};

