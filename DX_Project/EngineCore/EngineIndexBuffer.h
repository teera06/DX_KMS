#pragma once
class EngineIndexBuffer
{
public:
	// constrcuter destructer
	EngineIndexBuffer(); // ����Ʈ ������
	~EngineIndexBuffer(); // ����Ʈ �Ҹ���

	// delete Function
	EngineIndexBuffer(const EngineIndexBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineIndexBuffer(EngineIndexBuffer&& _Other) noexcept = delete; 
	EngineIndexBuffer& operator=(const EngineIndexBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineIndexBuffer& operator=(EngineIndexBuffer&& _Other) noexcept = delete;

protected:

private:
};

