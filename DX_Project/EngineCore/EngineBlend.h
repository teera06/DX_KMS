#pragma once
class EngineBlend
{
public:
	// constrcuter destructer
	EngineBlend(); // ����Ʈ ������
	~EngineBlend(); // ����Ʈ �Ҹ���

	// delete Function
	EngineBlend(const EngineBlend& _Other) = delete; // ����Ʈ ���� ������
	EngineBlend(EngineBlend&& _Other) noexcept = delete; 
	EngineBlend& operator=(const EngineBlend& _Other) = delete; // ����Ʈ ���� ������
	EngineBlend& operator=(EngineBlend&& _Other) noexcept = delete;

protected:

private:
};

