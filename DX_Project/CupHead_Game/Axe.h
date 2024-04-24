#pragma once
#include <EngineCore/Actor.h>

#include <EngineCore/StateManager.h>

class USpriteRenderer;

class AAxe: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AAxe(); // 디폴트 생성자
	~AAxe(); // 디폴트 소멸자

	// delete Function
	AAxe(const AAxe& _Other) = delete; // 디폴트 복사 생성자
	AAxe(AAxe&& _Other) noexcept = delete; 
	AAxe& operator=(const AAxe& _Other) = delete; // 디폴트 대입 연산자
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

	void patternInit();
	void Start(float _DeltaTime);
	void StartMove(float _DeltaTime);
	void AttMove(float _DeltaTime);
};

