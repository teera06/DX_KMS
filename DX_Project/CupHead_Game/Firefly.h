#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/StateManager.h>


class USpriteRenderer;

class AFirefly : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AFirefly(); // ����Ʈ ������
	~AFirefly(); // ����Ʈ �Ҹ���

	// delete Function
	AFirefly(const AFirefly& _Other) = delete; // ����Ʈ ���� ������
	AFirefly(AFirefly&& _Other) noexcept = delete; 
	AFirefly& operator=(const AFirefly& _Other) = delete; // ����Ʈ ���� ������
	AFirefly& operator=(AFirefly&& _Other) noexcept = delete;

	

	void SetDie(bool _Die)
	{
		Die = _Die;
	}

	void SetDelay(float _Delay)
	{
		Delay = _Delay;
	}

	UStateManager pattern;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* FireflyRender = nullptr;
	UCollision* FireflyCollision = nullptr;

	FVector SmallSkillDir = FVector::Zero;

	float Delay = 0.0f;

	float Speed = 500.0f;

	bool Die = false;

	void CalDir(float _DeltaTime);

	// ����
	void patternStateInit();

	void Intro(float _DeltaTime);
	void bigSkillIdle(float _DeltaTime);
	void bigskillLRMove(float _DeltaTime);
	void Death(float _DeltaTime);
};

