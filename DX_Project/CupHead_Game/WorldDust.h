#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class AWorldDust : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AWorldDust(); // 디폴트 생성자
	~AWorldDust(); // 디폴트 소멸자

	// delete Function
	AWorldDust(const AWorldDust& _Other) = delete; // 디폴트 복사 생성자
	AWorldDust(AWorldDust&& _Other) noexcept = delete; 
	AWorldDust& operator=(const AWorldDust& _Other) = delete; // 디폴트 대입 연산자
	AWorldDust& operator=(AWorldDust&& _Other) noexcept = delete;

protected:

private:
};

