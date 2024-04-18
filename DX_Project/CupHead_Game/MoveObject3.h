#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject3 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject3(); // 디폴트 생성자
	~AMoveObject3(); // 디폴트 소멸자

	// delete Function
	AMoveObject3(const AMoveObject3& _Other) = delete; // 디폴트 복사 생성자
	AMoveObject3(AMoveObject3&& _Other) noexcept = delete; 
	AMoveObject3& operator=(const AMoveObject3& _Other) = delete; // 디폴트 대입 연산자
	AMoveObject3& operator=(AMoveObject3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* ObjectRender = nullptr;
	UCollision* TopCollision = nullptr;


	float Speed = 500.0f;

	void Collisiongather(float _DeltaTime);
};

