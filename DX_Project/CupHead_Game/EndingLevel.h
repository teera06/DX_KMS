#pragma once
class EndingLevel
{
public:
	// constrcuter destructer
	EndingLevel(); // ����Ʈ ������
	~EndingLevel(); // ����Ʈ �Ҹ���

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete; // ����Ʈ ���� ������
	EndingLevel(EndingLevel&& _Other) noexcept = delete; 
	EndingLevel& operator=(const EndingLevel& _Other) = delete; // ����Ʈ ���� ������
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

protected:

private:
};

