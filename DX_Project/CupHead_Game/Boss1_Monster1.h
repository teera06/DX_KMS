#pragma once
#include <EngineCore/Actor.h>
class USpriteRenderer;
class ABoss1_Monster1 : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ABoss1_Monster1(); // 디폴트 생성자
	~ABoss1_Monster1(); // 디폴트 소멸자

	// delete Function
	ABoss1_Monster1(const ABoss1_Monster1& _Other) = delete; // 디폴트 복사 생성자
	ABoss1_Monster1(ABoss1_Monster1&& _Other) noexcept = delete; 
	ABoss1_Monster1& operator=(const ABoss1_Monster1& _Other) = delete; // 디폴트 대입 연산자
	ABoss1_Monster1& operator=(ABoss1_Monster1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* Boss1 = nullptr;

	float coolDownTime = 3.0f;

	bool att = false;
};

