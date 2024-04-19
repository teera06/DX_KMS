#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject2 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject2(); // 디폴트 생성자
	~AMoveObject2(); // 디폴트 소멸자

	// delete Function
	AMoveObject2(const AMoveObject2& _Other) = delete; // 디폴트 복사 생성자
	AMoveObject2(AMoveObject2&& _Other) noexcept = delete; 
	AMoveObject2& operator=(const AMoveObject2& _Other) = delete; // 디폴트 대입 연산자
	AMoveObject2& operator=(AMoveObject2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* ObjectRender = nullptr;
	USpriteRenderer* ObjectFront = nullptr;
	USpriteRenderer* ObjectBallRender = nullptr;
	UCollision* BoxCollision = nullptr;

	FVector GravityVector = FVector::Zero; // 중력값 받기

	FVector JumpVector = FVector::Up * 1600.0f; // 최종 점프력

	float Speed = 100.0f;

	float Gravity = 3000.0f;

	void Collisiongather(float _DeltaTime);
	void BallMove(float _DeltaTime);
};

