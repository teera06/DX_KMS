#pragma once
class Orb_Fire
{
public:
	// constrcuter destructer
	Orb_Fire(); // ����Ʈ ������
	~Orb_Fire(); // ����Ʈ �Ҹ���

	// delete Function
	Orb_Fire(const Orb_Fire& _Other) = delete; // ����Ʈ ���� ������
	Orb_Fire(Orb_Fire&& _Other) noexcept = delete; 
	Orb_Fire& operator=(const Orb_Fire& _Other) = delete; // ����Ʈ ���� ������
	Orb_Fire& operator=(Orb_Fire&& _Other) noexcept = delete;

protected:

private:
};

