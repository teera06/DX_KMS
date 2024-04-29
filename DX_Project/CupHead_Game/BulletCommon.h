#pragma once

class USpriteRenderer;
class ABulletCommon
{
public:
	// constrcuter destructer
	ABulletCommon(); // 디폴트 생성자
	~ABulletCommon(); // 디폴트 소멸자

	// delete Function
	ABulletCommon(const ABulletCommon& _Other) = delete; // 디폴트 복사 생성자
	ABulletCommon(ABulletCommon&& _Other) noexcept = delete; 
	ABulletCommon& operator=(const ABulletCommon& _Other) = delete; // 디폴트 대입 연산자
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

