#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AWind : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWind(); // 디폴트 생성자
	~AWind(); // 디폴트 소멸자

	// delete Function
	AWind(const AWind& _Other) = delete; // 디폴트 복사 생성자
	AWind(AWind&& _Other) noexcept = delete; 
	AWind& operator=(const AWind& _Other) = delete; // 디폴트 대입 연산자
	AWind& operator=(AWind&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* WindRender = nullptr;
	UCollision* WindCollision = nullptr;

	float Speed = 200.0f;
};

