#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class AHole : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AHole(); // 디폴트 생성자
	~AHole(); // 디폴트 소멸자

	// delete Function
	AHole(const AHole& _Other) = delete; // 디폴트 복사 생성자
	AHole(AHole&& _Other) noexcept = delete; 
	AHole& operator=(const AHole& _Other) = delete; // 디폴트 대입 연산자
	AHole& operator=(AHole&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* HoleBack = nullptr;
	USpriteRenderer* HoleFront = nullptr;
	USpriteRenderer* HoleSign = nullptr;

	UCollision* HoleCollision = nullptr;
};

