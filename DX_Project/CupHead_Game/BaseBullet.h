#pragma once

#include <Enginecore/Actor.h>

#include "BulletCommon.h"

class ABaseBullet : public AActor, public ABulletCommon
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Collisiongather() override;
private:
	
	float Speed = 2000.0f;

};

