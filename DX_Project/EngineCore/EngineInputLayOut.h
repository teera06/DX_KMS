#pragma once
class EngineInputLayOut
{
public:
	// constrcuter destructer
	EngineInputLayOut(); // ����Ʈ ������
	~EngineInputLayOut(); // ����Ʈ �Ҹ���

	// delete Function
	EngineInputLayOut(const EngineInputLayOut& _Other) = delete; // ����Ʈ ���� ������
	EngineInputLayOut(EngineInputLayOut&& _Other) noexcept = delete; 
	EngineInputLayOut& operator=(const EngineInputLayOut& _Other) = delete; // ����Ʈ ���� ������
	EngineInputLayOut& operator=(EngineInputLayOut&& _Other) noexcept = delete;

protected:

private:
};

