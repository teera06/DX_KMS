#pragma once
class AFirefly
{
public:
	// constrcuter destructer
	AFirefly(); // ����Ʈ ������
	~AFirefly(); // ����Ʈ �Ҹ���

	// delete Function
	AFirefly(const AFirefly& _Other) = delete; // ����Ʈ ���� ������
	AFirefly(AFirefly&& _Other) noexcept = delete; 
	AFirefly& operator=(const AFirefly& _Other) = delete; // ����Ʈ ���� ������
	AFirefly& operator=(AFirefly&& _Other) noexcept = delete;

protected:

private:
};

