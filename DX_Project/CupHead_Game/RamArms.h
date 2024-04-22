#pragma once
#include <EngineCore/Actor.h>

#include <EngineCore/StateManager.h>

class USpriteRenderer;

class ARamArms : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARamArms(); // 디폴트 생성자
	~ARamArms(); // 디폴트 소멸자

	// delete Function
	ARamArms(const ARamArms& _Other) = delete; // 디폴트 복사 생성자
	ARamArms(ARamArms&& _Other) noexcept = delete; 
	ARamArms& operator=(const ARamArms& _Other) = delete; // 디폴트 대입 연산자
	ARamArms& operator=(ARamArms&& _Other) noexcept = delete;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* RamArms = nullptr;

	float speed = 500.0f;

	void AniCreate();

	void StateInit();

	void RamArmsStart(float _DeltaTime);
	void RamArmsEnd(float _DeltaTime);
};

