#pragma once
class ABossBackMap1
{
public:
	// constrcuter destructer
	ABossBackMap1(); // ����Ʈ ������
	~ABossBackMap1(); // ����Ʈ �Ҹ���

	// delete Function
	ABossBackMap1(const ABossBackMap1& _Other) = delete; // ����Ʈ ���� ������
	ABossBackMap1(ABossBackMap1&& _Other) noexcept = delete; 
	ABossBackMap1& operator=(const ABossBackMap1& _Other) = delete; // ����Ʈ ���� ������
	ABossBackMap1& operator=(ABossBackMap1&& _Other) noexcept = delete;

protected:

private:
};

