#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class MoveObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	MoveObject(); // 디폴트 생성자
	~MoveObject(); // 디폴트 소멸자

	// delete Function
	MoveObject(const MoveObject& _Other) = delete; // 디폴트 복사 생성자
	MoveObject(MoveObject&& _Other) noexcept = delete; 
	MoveObject& operator=(const MoveObject& _Other) = delete; // 디폴트 대입 연산자
	MoveObject& operator=(MoveObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ObjectRender = nullptr;
	UCollision* TopCollision = nullptr;
};

