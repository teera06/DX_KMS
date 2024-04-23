#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ABombBat : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABombBat(); // 디폴트 생성자
	~ABombBat(); // 디폴트 소멸자

	// delete Function
	ABombBat(const ABombBat& _Other) = delete; // 디폴트 복사 생성자
	ABombBat(ABombBat&& _Other) noexcept = delete; 
	ABombBat& operator=(const ABombBat& _Other) = delete; // 디폴트 대입 연산자
	ABombBat& operator=(ABombBat&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BombBat = nullptr;
};

