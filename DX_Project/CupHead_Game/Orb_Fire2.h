#pragma once
class Orb_Fire2
{
public:
	// constrcuter destructer
	Orb_Fire2(); // ����Ʈ ������
	~Orb_Fire2(); // ����Ʈ �Ҹ���

	// delete Function
	Orb_Fire2(const Orb_Fire2& _Other) = delete; // ����Ʈ ���� ������
	Orb_Fire2(Orb_Fire2&& _Other) noexcept = delete; 
	Orb_Fire2& operator=(const Orb_Fire2& _Other) = delete; // ����Ʈ ���� ������
	Orb_Fire2& operator=(Orb_Fire2&& _Other) noexcept = delete;

protected:

private:
};

