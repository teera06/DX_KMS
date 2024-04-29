#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class ASSDust : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ASSDust(); // 디폴트 생성자
	~ASSDust(); // 디폴트 소멸자

	// delete Function
	ASSDust(const ASSDust& _Other) = delete; // 디폴트 복사 생성자
	ASSDust(ASSDust&& _Other) noexcept = delete; 
	ASSDust& operator=(const ASSDust& _Other) = delete; // 디폴트 대입 연산자
	ASSDust& operator=(ASSDust&& _Other) noexcept = delete;
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

