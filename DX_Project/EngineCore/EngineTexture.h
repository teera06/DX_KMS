#pragma once
class EngineTexture
{
public:
	// constrcuter destructer
	EngineTexture(); // ����Ʈ ������
	~EngineTexture(); // ����Ʈ �Ҹ���

	// delete Function
	EngineTexture(const EngineTexture& _Other) = delete; // ����Ʈ ���� ������
	EngineTexture(EngineTexture&& _Other) noexcept = delete; 
	EngineTexture& operator=(const EngineTexture& _Other) = delete; // ����Ʈ ���� ������
	EngineTexture& operator=(EngineTexture&& _Other) noexcept = delete;

protected:

private:
};

