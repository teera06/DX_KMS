#pragma once

#include <EngineCore/Actor.h>

#include <EngineCore/StateManager.h>

class USpriteRenderer;

class AImp : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AImp(); // ����Ʈ ������
	~AImp(); // ����Ʈ �Ҹ���

	// delete Function
	AImp(const AImp& _Other) = delete; // ����Ʈ ���� ������
	AImp(AImp&& _Other) noexcept = delete; 
	AImp& operator=(const AImp& _Other) = delete; // ����Ʈ ���� ������
	AImp& operator=(AImp&& _Other) noexcept = delete;

	void IsDieCheck(const bool& _DieCheck)
	{
		DieCheck = _DieCheck;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UStateManager pattern;
private:
	UEngineSoundPlayer spinSound;
	USpriteRenderer* Imp = nullptr;

	UCollision* ImpCollision = nullptr;

	FVector MoveNorMalize = FVector::Zero;

	float Speed = 200.0f;
	float Delay = 0.8f;

	int RandomMove = 0;

	bool DieCheck = false;

	void CalDir(float _DeltaTime);
	void PlayerCollisionCheck();

	void patternInit();
	void Start(float _DeltaTime);
	void ImpFlying(float _DeltaTime);
	void ImpRandomMove(float _DeltaTime);
	void ImpAttack(float _DeltaTime);
	void ImpAttackEnd(float _DeltaTime);

	void RealDie(float _DeltaTime);
};

