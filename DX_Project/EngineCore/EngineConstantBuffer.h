#pragma once
class EngineConstantBuffer
{
public:
	// constrcuter destructer
	EngineConstantBuffer(); // ����Ʈ ������
	~EngineConstantBuffer(); // ����Ʈ �Ҹ���

	// delete Function
	EngineConstantBuffer(const EngineConstantBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineConstantBuffer(EngineConstantBuffer&& _Other) noexcept = delete; 
	EngineConstantBuffer& operator=(const EngineConstantBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineConstantBuffer& operator=(EngineConstantBuffer&& _Other) noexcept = delete;

protected:

private:
};

