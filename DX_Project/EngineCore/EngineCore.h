#pragma once
class EngineCore
{
public:
	// constrcuter destructer
	EngineCore(); // ����Ʈ ������
	~EngineCore(); // ����Ʈ �Ҹ���

	// delete Function
	EngineCore(const EngineCore& _Other) = delete; // ����Ʈ ���� ������
	EngineCore(EngineCore&& _Other) noexcept = delete; 
	EngineCore& operator=(const EngineCore& _Other) = delete; // ����Ʈ ���� ������
	EngineCore& operator=(EngineCore&& _Other) noexcept = delete;

protected:

private:
};

