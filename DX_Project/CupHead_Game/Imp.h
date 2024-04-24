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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UStateManager pattern;
private:
	USpriteRenderer* Imp = nullptr;

	FVector MoveNorMalize = FVector::Zero;

	float Speed = 300.0f;
	float Delay = 1.0f;

	void CalDir(float _DeltaTime);

	void patternInit();
	void Start(float _DeltaTime);
	void ImpFlying(float _DeltaTime);
	void ImpAttack(float _DeltaTime);
	void ImpAttackEnd(float _DeltaTime);
};

