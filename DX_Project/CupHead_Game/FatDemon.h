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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UStateManager pattern;
private:
	USpriteRenderer* FatDemon = nullptr;

	FVector MoveVector = FVector::Up;

	float Speed = 200.0f;
	float Delay = 3.0f;

	void patternInit();
	void FatDemonIdle(float _DeltaTime);
	void FatDemonAttack(float _DeltaTime);
};

