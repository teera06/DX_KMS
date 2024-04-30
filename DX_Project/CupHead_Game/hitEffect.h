#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class AhitEffect : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AhitEffect(); // 디폴트 생성자
	~AhitEffect(); // 디폴트 소멸자

	// delete Function
	AhitEffect(const AhitEffect& _Other) = delete; // 디폴트 복사 생성자
	AhitEffect(AhitEffect&& _Other) noexcept = delete; 
	AhitEffect& operator=(const AhitEffect& _Other) = delete; // 디폴트 대입 연산자
	AhitEffect& operator=(AhitEffect&& _Other) noexcept = delete;

	inline void SethitDir(const FVector& _hitDir)
	{
		hitDir = _hitDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;

	FVector hitDir = FVector::Zero;
};

