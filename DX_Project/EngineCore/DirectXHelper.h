#pragma once
class DirectXHelper
{
public:
	// constrcuter destructer
	DirectXHelper(); // ����Ʈ ������
	~DirectXHelper(); // ����Ʈ �Ҹ���

	// delete Function
	DirectXHelper(const DirectXHelper& _Other) = delete; // ����Ʈ ���� ������
	DirectXHelper(DirectXHelper&& _Other) noexcept = delete; 
	DirectXHelper& operator=(const DirectXHelper& _Other) = delete; // ����Ʈ ���� ������
	DirectXHelper& operator=(DirectXHelper&& _Other) noexcept = delete;

protected:

private:
};

