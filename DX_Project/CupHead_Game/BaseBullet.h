#pragma once
class ABaseBullet
{
public:
	// constrcuter destructer
	ABaseBullet(); // ����Ʈ ������
	~ABaseBullet(); // ����Ʈ �Ҹ���

	// delete Function
	ABaseBullet(const ABaseBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseBullet(ABaseBullet&& _Other) noexcept = delete; 
	ABaseBullet& operator=(const ABaseBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseBullet& operator=(ABaseBullet&& _Other) noexcept = delete;

protected:

private:
};

