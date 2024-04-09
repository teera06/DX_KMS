#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/StateManager.h>

class AWorldPlayer : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldPlayer(); // ����Ʈ ������
	~AWorldPlayer(); // ����Ʈ �Ҹ���

	// delete Function
	AWorldPlayer(const AWorldPlayer& _Other) = delete; // ����Ʈ ���� ������
	AWorldPlayer(AWorldPlayer&& _Other) noexcept = delete; 
	AWorldPlayer& operator=(const AWorldPlayer& _Other) = delete; // ����Ʈ ���� ������
	AWorldPlayer& operator=(AWorldPlayer&& _Other) noexcept = delete;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* WorldPlayerRenderer = nullptr;

	///////////////////////// State
	void StateInit();

	void Die(float _DeltaTime);

	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);

	void RunStart();
	void Run(float _DeltaTime);
};

