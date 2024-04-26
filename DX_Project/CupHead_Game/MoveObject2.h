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
	UCollision* TopCollision = nullptr;
	UCollision* LRCollision = nullptr;

	float Speed = 200.0f;

	void Collisiongather(float _DeltaTime);
};

