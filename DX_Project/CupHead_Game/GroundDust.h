#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class AGroundDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AGroundDust(); // 디폴트 생성자
	~AGroundDust(); // 디폴트 소멸자

	// delete Function
	AGroundDust(const AGroundDust& _Other) = delete; // 디폴트 복사 생성자
	AGroundDust(AGroundDust&& _Other) noexcept = delete; 
	AGroundDust& operator=(const AGroundDust& _Other) = delete; // 디폴트 대입 연산자
	AGroundDust& operator=(AGroundDust&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;
};

