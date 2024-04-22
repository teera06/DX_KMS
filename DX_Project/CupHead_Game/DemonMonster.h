#pragma once

#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;
class ADemonMonster : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADemonMonster(); // 디폴트 생성자
	~ADemonMonster(); // 디폴트 소멸자

	// delete Function
	ADemonMonster(const ADemonMonster& _Other) = delete; // 디폴트 복사 생성자
	ADemonMonster(ADemonMonster&& _Other) noexcept = delete; 
	ADemonMonster& operator=(const ADemonMonster& _Other) = delete; // 디폴트 대입 연산자
	ADemonMonster& operator=(ADemonMonster&& _Other) noexcept = delete;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Demon = nullptr;

	FVector Move = FVector::Left;

	float speed = 300.0f;

	void AniCreate();

	void StateInit();
	void DemonIntro1(float _DeltaTime);
	void DemonJump(float _DeltaTime);
	void DemonAttack1(float _DeltaTime);
	void DemonAttack2(float _DeltaTime);
};

