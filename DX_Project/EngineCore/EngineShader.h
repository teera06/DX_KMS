#pragma once
class EngineShader
{
public:
	// constrcuter destructer
	EngineShader(); // ����Ʈ ������
	~EngineShader(); // ����Ʈ �Ҹ���

	// delete Function
	EngineShader(const EngineShader& _Other) = delete; // ����Ʈ ���� ������
	EngineShader(EngineShader&& _Other) noexcept = delete; 
	EngineShader& operator=(const EngineShader& _Other) = delete; // ����Ʈ ���� ������
	EngineShader& operator=(EngineShader&& _Other) noexcept = delete;

protected:

private:
};

