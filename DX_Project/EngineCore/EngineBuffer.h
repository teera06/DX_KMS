#pragma once
class EngineBuffer
{
public:
	// constrcuter destructer
	EngineBuffer(); // ����Ʈ ������
	~EngineBuffer(); // ����Ʈ �Ҹ���

	// delete Function
	EngineBuffer(const EngineBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineBuffer(EngineBuffer&& _Other) noexcept = delete; 
	EngineBuffer& operator=(const EngineBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineBuffer& operator=(EngineBuffer&& _Other) noexcept = delete;

protected:

private:
};

