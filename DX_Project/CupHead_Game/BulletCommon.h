#pragma once

class USpriteRenderer;
class ABulletCommon
{
public:
	// constrcuter destructer
	ABulletCommon(); // ����Ʈ ������
	~ABulletCommon(); // ����Ʈ �Ҹ���

	// delete Function
	ABulletCommon(const ABulletCommon& _Other) = delete; // ����Ʈ ���� ������
	ABulletCommon(ABulletCommon&& _Other) noexcept = delete; 
	ABulletCommon& operator=(const ABulletCommon& _Other) = delete; // ����Ʈ ���� ������
	ABulletCommon& operator=(ABulletCommon&& _Other) noexcept = delete;

	inline void SetBulletDir(const FVector& _BulletDir)
	{
		BulletDir = _BulletDir;
	}

protected:
	USpriteRenderer* BulletRender = nullptr;
	UCollision* BulletCollision = nullptr;

	FVector BulletDir = FVector::Zero;
	FVector Move = FVector::Zero;

	bool shoot = false;

	bool DestroyCheck = false;

	virtual void Collisiongather();

	void SkillDir();
private:
};

