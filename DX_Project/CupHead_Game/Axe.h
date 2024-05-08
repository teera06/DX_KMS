#pragma once
#include <EngineCore/Actor.h>

#include <EngineCore/StateManager.h>

class USpriteRenderer;

class AAxe: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AAxe(); // ����Ʈ ������
	~AAxe(); // ����Ʈ �Ҹ���

	// delete Function
	AAxe(const AAxe& _Other) = delete; // ����Ʈ ���� ������
	AAxe(AAxe&& _Other) noexcept = delete; 
	AAxe& operator=(const AAxe& _Other) = delete; // ����Ʈ ���� ������
	AAxe& operator=(AAxe&& _Other) noexcept = delete;

	UStateManager pattern;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Axe= nullptr;
	UCollision* AxeCollision = nullptr;
	float RotSpeed = 6000.0f;
	float MoveSpeed =200.0f;

	float Delay = 1.0f;

	void CalDir(float _DeltaTime);
	void CollisionCheck();

	void patternInit();
	void Start(float _DeltaTime);
	void StartMove(float _DeltaTime);
	void AttMove(float _DeltaTime);
};

