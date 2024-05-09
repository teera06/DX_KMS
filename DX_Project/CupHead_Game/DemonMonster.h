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

	void IsDieCheck(const bool& _DieCheck)
	{
		DieCheck = _DieCheck;
	}

	UStateManager State;
	UStateManager State2;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Demon = nullptr;
	UCollision* MonsterCollision = nullptr;

	FVector MoveL = FVector::Left;
	FVector MoveR = FVector::Right;

	float speed = 300.0f;

	bool OneCheck = false;
	bool LRStart = false;
	bool DieCheck = false;
	// false -> ���� 1
	// true -> ������ 2

	void AniCreate();
	void PlayerCollision();

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

	void RealDie(float _DeltaTime);
};

