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

	inline void SetSmallSkillDir(const FVector& _SmallSkillDir)
	{
		SmallSkillDir = _SmallSkillDir;
	}

	UStateManager pattern;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* FireflyRender = nullptr;
	UCollision* FireflyCollision = nullptr;

	FVector SmallSkillDir = FVector::Zero;

	float MoveCoolDonwTime = 0.0f;
	float Delay = 3.0f;

	float Speed = 600.0f;
	// ����
	void patternStateInit();

	void Intro(float _DeltaTime);
	void bigSkillIdle(float _DeltaTime);
	void bigskillLRMove(float _DeltaTime);
};

