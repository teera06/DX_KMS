#pragma once
#include <Enginecore/Actor.h>


class USpriteRenderer;
class ADashDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADashDust(); // 디폴트 생성자
	~ADashDust(); // 디폴트 소멸자

	// delete Function
	ADashDust(const ADashDust& _Other) = delete; // 디폴트 복사 생성자
	ADashDust(ADashDust&& _Other) noexcept = delete; 
	ADashDust& operator=(const ADashDust& _Other) = delete; // 디폴트 대입 연산자
	ADashDust& operator=(ADashDust&& _Other) noexcept = delete;

	inline void SetDushDir(const FVector& _DushDir)
	{
		DushDir = _DushDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;

	FVector DushDir = FVector::Zero;
};

