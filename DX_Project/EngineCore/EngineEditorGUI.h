#pragma once
class EngineEditorGUI
{
public:
	// constrcuter destructer
	EngineEditorGUI(); // ����Ʈ ������
	~EngineEditorGUI(); // ����Ʈ �Ҹ���

	// delete Function
	EngineEditorGUI(const EngineEditorGUI& _Other) = delete; // ����Ʈ ���� ������
	EngineEditorGUI(EngineEditorGUI&& _Other) noexcept = delete; 
	EngineEditorGUI& operator=(const EngineEditorGUI& _Other) = delete; // ����Ʈ ���� ������
	EngineEditorGUI& operator=(EngineEditorGUI&& _Other) noexcept = delete;

protected:

private:
};

