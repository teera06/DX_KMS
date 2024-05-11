#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;

class ABombBat : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABombBat(); // 디폴트 생성자
	~ABombBat(); // 디폴트 소멸자

	// delete Function
	ABombBat(const ABombBat& _Other) = delete; // 디폴트 복사 생성자
	ABombBat(ABombBat&& _Other) noexcept = delete; 
	ABombBat& operator=(const ABombBat& _Other) = delete; // 디폴트 대입 연산자
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

