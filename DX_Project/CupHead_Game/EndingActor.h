#pragma once
class EndingActor
{
public:
	// constrcuter destructer
	EndingActor(); // ����Ʈ ������
	~EndingActor(); // ����Ʈ �Ҹ���

	// delete Function
	EndingActor(const EndingActor& _Other) = delete; // ����Ʈ ���� ������
	EndingActor(EndingActor&& _Other) noexcept = delete; 
	EndingActor& operator=(const EndingActor& _Other) = delete; // ����Ʈ ���� ������
	EndingActor& operator=(EndingActor&& _Other) noexcept = delete;

protected:

private:
};

