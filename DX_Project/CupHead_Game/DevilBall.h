#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevilBall : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADevilBall(); // 디폴트 생성자
	~ADevilBall(); // 디폴트 소멸자

	// delete Function
	ADevilBall(const ADevilBall& _Other) = delete; // 디폴트 복사 생성자
	ADevilBall(ADevilBall&& _Other) noexcept = delete; 
	ADevilBall& operator=(const ADevilBall& _Other) = delete; // 디폴트 대입 연산자
	ADevilBall& operator=(ADevilBall&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* DevilBall = nullptr;
};

