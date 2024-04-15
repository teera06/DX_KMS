#pragma once

#include <Enginecore/Actor.h>

class USpriteRenderer;
class ABaseBullet : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABaseBullet(); // 디폴트 생성자
	~ABaseBullet(); // 디폴트 소멸자

	// delete Function
	ABaseBullet(const ABaseBullet& _Other) = delete; // 디폴트 복사 생성자
	ABaseBullet(ABaseBullet&& _Other) noexcept = delete; 
	ABaseBullet& operator=(const ABaseBullet& _Other) = delete; // 디폴트 대입 연산자
	ABaseBullet& operator=(ABaseBullet&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BulletRender = nullptr;
	UCollision* BulletCollision = nullptr;
};

