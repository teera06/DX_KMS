#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;

class ABombBat : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABombBat(); // ����Ʈ ������
	~ABombBat(); // ����Ʈ �Ҹ���

	// delete Function
	ABombBat(const ABombBat& _Other) = delete; // ����Ʈ ���� ������
	ABombBat(ABombBat&& _Other) noexcept = delete; 
	ABombBat& operator=(const ABombBat& _Other) = delete; // ����Ʈ ���� ������
	ABombBat& operator=(ABombBat&& _Other) noexcept = delete;

	UStateManager pattern;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BombBat = nullptr;

	UCollision* ColBat = nullptr;

	float BoomTime = 8.0f;

	float speed = 500.0f;

	void PlayerCollision();

	void patternInit();
	void LeftMove(float _DeltaTime);
	void UpMove(float _DeltaTime);
	void RightMove(float _DeltaTime);

	void BombExplosion(float _DeltaTime);
};

