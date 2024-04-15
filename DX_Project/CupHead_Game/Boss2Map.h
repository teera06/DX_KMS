#pragma once
#include <Enginecore/Actor.h>
#include "ContentsENum.h"
class USpriteRenderer;

class ABoss2Map : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss2Map(); // 디폴트 생성자
	~ABoss2Map(); // 디폴트 소멸자

	// delete Function
	ABoss2Map(const ABoss2Map& _Other) = delete; // 디폴트 복사 생성자
	ABoss2Map(ABoss2Map&& _Other) noexcept = delete; 
	ABoss2Map& operator=(const ABoss2Map& _Other) = delete; // 디폴트 대입 연산자
	ABoss2Map& operator=(ABoss2Map&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* back2Map = nullptr;
	USpriteRenderer* crowd2 = nullptr;
	USpriteRenderer* JazzGirls = nullptr;
	USpriteRenderer* Waiter = nullptr;

	FVector Dir = FVector::Left;

	EDir checkLR = EDir::Left;

	float speed = 300.0f;
};

