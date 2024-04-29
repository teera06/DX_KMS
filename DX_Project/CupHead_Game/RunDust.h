#pragma once
#include <Enginecore/Actor.h>


class USpriteRenderer;
class ARunDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARunDust(); // 디폴트 생성자
	~ARunDust(); // 디폴트 소멸자

	// delete Function
	ARunDust(const ARunDust& _Other) = delete; // 디폴트 복사 생성자
	ARunDust(ARunDust&& _Other) noexcept = delete; 
	ARunDust& operator=(const ARunDust& _Other) = delete; // 디폴트 대입 연산자
	ARunDust& operator=(ARunDust&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;
};

