#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class ABossBackMap1 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABossBackMap1(); // 디폴트 생성자
	~ABossBackMap1(); // 디폴트 소멸자

	// delete Function
	ABossBackMap1(const ABossBackMap1& _Other) = delete; // 디폴트 복사 생성자
	ABossBackMap1(ABossBackMap1&& _Other) noexcept = delete; 
	ABossBackMap1& operator=(const ABossBackMap1& _Other) = delete; // 디폴트 대입 연산자
	ABossBackMap1& operator=(ABossBackMap1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BossBackMap1 = nullptr;
	USpriteRenderer* Front = nullptr;

	float CoolDownTime = 3.0f;

	bool LRCheck = false;
};

