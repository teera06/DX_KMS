#pragma once
class EngineOption
{
public:
	// constrcuter destructer
	EngineOption(); // ����Ʈ ������
	~EngineOption(); // ����Ʈ �Ҹ���

	// delete Function
	EngineOption(const EngineOption& _Other) = delete; // ����Ʈ ���� ������
	EngineOption(EngineOption&& _Other) noexcept = delete; 
	EngineOption& operator=(const EngineOption& _Other) = delete; // ����Ʈ ���� ������
	EngineOption& operator=(EngineOption&& _Other) noexcept = delete;

protected:

private:
};

