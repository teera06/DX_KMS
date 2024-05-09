#pragma once
#include <EngineCore/Actor.h>

#include <EngineCore/StateManager.h>

class USpriteRenderer;

class AFatDemon : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AFatDemon(); // 디폴트 생성자
	~AFatDemon(); // 디폴트 소멸자

	// delete Function
	AFatDemon(const AFatDemon& _Other) = delete; // 디폴트 복사 생성자
	AFatDemon(AFatDemon&& _Other) noexcept = delete; 
	AFatDemon& operator=(const AFatDemon& _Other) = delete; // 디폴트 대입 연산자
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

