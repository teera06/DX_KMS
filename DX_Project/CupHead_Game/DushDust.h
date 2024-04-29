#pragma once
#include <Enginecore/Actor.h>


class USpriteRenderer;
class ADushDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADushDust(); // 디폴트 생성자
	~ADushDust(); // 디폴트 소멸자

	// delete Function
	ADushDust(const ADushDust& _Other) = delete; // 디폴트 복사 생성자
	ADushDust(ADushDust&& _Other) noexcept = delete; 
	ADushDust& operator=(const ADushDust& _Other) = delete; // 디폴트 대입 연산자
	ADushDust& operator=(ADushDust&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;
};

