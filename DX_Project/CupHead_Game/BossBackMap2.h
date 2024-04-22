#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class ABossBackMap2 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABossBackMap2(); // 디폴트 생성자
	~ABossBackMap2(); // 디폴트 소멸자

	// delete Function
	ABossBackMap2(const ABossBackMap2& _Other) = delete; // 디폴트 복사 생성자
	ABossBackMap2(ABossBackMap2&& _Other) noexcept = delete; 
	ABossBackMap2& operator=(const ABossBackMap2& _Other) = delete; // 디폴트 대입 연산자
	ABossBackMap2& operator=(ABossBackMap2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BossBackMap2 = nullptr;
};

