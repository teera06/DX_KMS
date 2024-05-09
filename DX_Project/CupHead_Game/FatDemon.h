#pragma once
#include <EngineCore/Actor.h>

#include <EngineCore/StateManager.h>

class USpriteRenderer;

class AFatDemon : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AFatDemon(); // ����Ʈ ������
	~AFatDemon(); // ����Ʈ �Ҹ���

	// delete Function
	AFatDemon(const AFatDemon& _Other) = delete; // ����Ʈ ���� ������
	AFatDemon(AFatDemon&& _Other) noexcept = delete; 
	AFatDemon& operator=(const AFatDemon& _Other) = delete; // ����Ʈ ���� ������
	AFatDemon& operator=(AFatDemon&& _Other) noexcept = delete;

	USpriteRenderer* GetRender()
	{
		return FatDemon;
	}

	void AddHp(const int& _Hp)
	{
		Hp -= _Hp;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UStateManager pattern;
private:
	USpriteRenderer* FatDemon = nullptr;

	UCollision* MonsterCollision = nullptr;

	FVector MoveVector = FVector::Up;

	float Speed = 200.0f;
	float Delay = 3.0f;
	float DamgeColorDelay = 0.25f;
	int randomAtt = 0;
	int Hp = 10;

	bool ParryAttcheck = false;

	void CreateSkill();

	void patternInit();
	void FatDemonIntro(float _DeltaTime);
	void FatDemonIdle(float _DeltaTime);
	void FatDemonAttack(float _DeltaTime);
	void FatDemonDeath(float _DeltaTime);
	void FatDemonDeathIdle(float _DeltaTime);
};

