#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/StateManager.h>


class USpriteRenderer;

class AFirefly : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AFirefly(); // 디폴트 생성자
	~AFirefly(); // 디폴트 소멸자

	// delete Function
	AFirefly(const AFirefly& _Other) = delete; // 디폴트 복사 생성자
	AFirefly(AFirefly&& _Other) noexcept = delete; 
	AFirefly& operator=(const AFirefly& _Other) = delete; // 디폴트 대입 연산자
	AFirefly& operator=(AFirefly&& _Other) noexcept = delete;

	

	inline void SetDie(const bool& _Die)
	{
		Die = _Die;
	}

	inline void SetDelay(const float& _Delay)
	{
		Delay = _Delay;
	}

	inline void SetMove(const FVector& _Move)
	{
		Move = _Move;
	}

	UStateManager pattern;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* FireflyRender = nullptr;
	UCollision* FireflyCollision = nullptr;

	FVector SmallSkillDir = FVector::Zero;

	FVector Move = FVector::Zero;

	float Delay = 0.0f;

	float Speed = 500.0f;

	bool Die = false;

	void CalDir(float _DeltaTime);

	// 상태
	void patternStateInit();

	void Intro(float _DeltaTime);
	void bigSkillIdle(float _DeltaTime);
	void bigskillLRMove(float _DeltaTime);
	void Death(float _DeltaTime);
};

