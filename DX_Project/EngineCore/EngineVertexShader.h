#pragma once
class EngineVertexShader
{
public:
	// constrcuter destructer
	EngineVertexShader(); // ����Ʈ ������
	~EngineVertexShader(); // ����Ʈ �Ҹ���

	// delete Function
	EngineVertexShader(const EngineVertexShader& _Other) = delete; // ����Ʈ ���� ������
	EngineVertexShader(EngineVertexShader&& _Other) noexcept = delete; 
	EngineVertexShader& operator=(const EngineVertexShader& _Other) = delete; // ����Ʈ ���� ������
	EngineVertexShader& operator=(EngineVertexShader&& _Other) noexcept = delete;

protected:

private:
};

