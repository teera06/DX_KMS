#pragma once

#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;
class ADemonMonster : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADemonMonster(); // ����Ʈ ������
	~ADemonMonster(); // ����Ʈ �Ҹ���

	// delete Function
	ADemonMonster(const ADemonMonster& _Other) = delete; // ����Ʈ ���� ������
	ADemonMonster(ADemonMonster&& _Other) noexcept = delete; 
	ADemonMonster& operator=(const ADemonMonster& _Other) = delete; // ����Ʈ ���� ������
	ADemonMonster& operator=(ADemonMonster&& _Other) noexcept = delete;

	void SetLRStart(const bool& _LRStart)
	{
		LRStart = _LRStart;
	}

	UStateManager State;
	UStateManager State2;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Demon = nullptr;

	FVector MoveL = FVector::Left;

	float speed = 300.0f;

	bool OneCheck = false;
	bool LRStart = false;

	void AniCreate();

	void StateInit();
	void DemonIntro1(float _DeltaTime);
	void DemonJump(float _DeltaTime);
	void DemonAttack1(float _DeltaTime);
	void DemonAttack2(float _DeltaTime);

	void StateInit2();
	void DemonIntro2(float _DeltaTime);
	void Demon2Jump(float _DeltaTime);
	void Demon2Attack1(float _DeltaTime);
	void Demon2Attack2(float _DeltaTime);
};

