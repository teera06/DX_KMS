#pragma once
class Actor
{
public:
	// constrcuter destructer
	Actor(); // ����Ʈ ������
	~Actor(); // ����Ʈ �Ҹ���

	// delete Function
	Actor(const Actor& _Other) = delete; // ����Ʈ ���� ������
	Actor(Actor&& _Other) noexcept = delete; 
	Actor& operator=(const Actor& _Other) = delete; // ����Ʈ ���� ������
	Actor& operator=(Actor&& _Other) noexcept = delete;

protected:

private:
};

