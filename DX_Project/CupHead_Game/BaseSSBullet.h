#pragma once
#include <Enginecore/Actor.h>

#include "BulletCommon.h"

class ABaseSSBullet : public AActor, public ABulletCommon
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABaseSSBullet(); // ����Ʈ ������
	~ABaseSSBullet(); // ����Ʈ �Ҹ���

	// delete Function
	ABaseSSBullet(const ABaseSSBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseSSBullet(ABaseSSBullet&& _Other) noexcept = delete; 
	ABaseSSBullet& operator=(const ABaseSSBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseSSBullet& operator=(ABaseSSBullet&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Collisiongather() override;
private:

	float Speed = 500.0f;
};

