#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject(); // 디폴트 생성자
	~AMoveObject(); // 디폴트 소멸자

	// delete Function
	AMoveObject(const AMoveObject& _Other) = delete; // 디폴트 복사 생성자
	AMoveObject(AMoveObject&& _Other) noexcept = delete; 
	AMoveObject& operator=(const AMoveObject& _Other) = delete; // 디폴트 대입 연산자
	AMoveObject& operator=(AMoveObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ObjectRender = nullptr;
	UCollision* TopCollision = nullptr;
	UCollision* LRCollision = nullptr;

	float Speed = 500.0f;

	void Collisiongather(float _DeltaTime);
};

