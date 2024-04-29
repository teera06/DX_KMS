#pragma once
#include <Enginecore/Actor.h>

#include "BulletCommon.h"

class ABaseSSBullet : public AActor, public ABulletCommon
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABaseSSBullet(); // 디폴트 생성자
	~ABaseSSBullet(); // 디폴트 소멸자

	// delete Function
	ABaseSSBullet(const ABaseSSBullet& _Other) = delete; // 디폴트 복사 생성자
	ABaseSSBullet(ABaseSSBullet&& _Other) noexcept = delete; 
	ABaseSSBullet& operator=(const ABaseSSBullet& _Other) = delete; // 디폴트 대입 연산자
	ABaseSSBullet& operator=(ABaseSSBullet&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Collisiongather() override;
private:

	float Speed = 500.0f;
};

