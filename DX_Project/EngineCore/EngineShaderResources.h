#pragma once
class EngineShaderResources
{
public:
	// constrcuter destructer
	EngineShaderResources(); // ����Ʈ ������
	~EngineShaderResources(); // ����Ʈ �Ҹ���

	// delete Function
	EngineShaderResources(const EngineShaderResources& _Other) = delete; // ����Ʈ ���� ������
	EngineShaderResources(EngineShaderResources&& _Other) noexcept = delete; 
	EngineShaderResources& operator=(const EngineShaderResources& _Other) = delete; // ����Ʈ ���� ������
	EngineShaderResources& operator=(EngineShaderResources&& _Other) noexcept = delete;

protected:

private:
};

