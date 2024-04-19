#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject1 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject1(); // 디폴트 생성자
	~AMoveObject1(); // 디폴트 소멸자

	// delete Function
	AMoveObject1(const AMoveObject1& _Other) = delete; // 디폴트 복사 생성자
	AMoveObject1(AMoveObject1&& _Other) noexcept = delete; 
	AMoveObject1& operator=(const AMoveObject1& _Other) = delete; // 디폴트 대입 연산자
	AMoveObject1& operator=(AMoveObject1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* ObjectRender = nullptr;
	USpriteRenderer* ObjectFront = nullptr;
	USpriteRenderer* Fire = nullptr;
	UCollision* TopCollision = nullptr;


	float Speed = 100.0f;

	void Collisiongather(float _DeltaTime);
};

