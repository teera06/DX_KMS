#pragma once

#include <Enginecore/Actor.h>

class USpriteRenderer;
class ABaseBullet : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABaseBullet(); // ����Ʈ ������
	~ABaseBullet(); // ����Ʈ �Ҹ���

	// delete Function
	ABaseBullet(const ABaseBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseBullet(ABaseBullet&& _Other) noexcept = delete; 
	ABaseBullet& operator=(const ABaseBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseBullet& operator=(ABaseBullet&& _Other) noexcept = delete;

	inline void SetBulletDir(const FVector& _BulletDir)
	{
		BulletDir = _BulletDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BulletRender = nullptr;
	UCollision* BulletCollision = nullptr;

	FVector BulletDir = FVector::Zero;
	FVector Move = FVector::Zero;
	float Speed = 2000.0f;

	bool shoot = false;

	bool DestroyCheck = false;

	void SkillDir();
	void Collisiongather();
};

