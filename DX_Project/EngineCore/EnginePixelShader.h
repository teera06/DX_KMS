#pragma once
class EnginePixelShader
{
public:
	// constrcuter destructer
	EnginePixelShader(); // ����Ʈ ������
	~EnginePixelShader(); // ����Ʈ �Ҹ���

	// delete Function
	EnginePixelShader(const EnginePixelShader& _Other) = delete; // ����Ʈ ���� ������
	EnginePixelShader(EnginePixelShader&& _Other) noexcept = delete; 
	EnginePixelShader& operator=(const EnginePixelShader& _Other) = delete; // ����Ʈ ���� ������
	EnginePixelShader& operator=(EnginePixelShader&& _Other) noexcept = delete;

protected:

private:
};

