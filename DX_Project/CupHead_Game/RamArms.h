#pragma once
#include <EngineCore/Actor.h>

#include <EngineCore/StateManager.h>

class USpriteRenderer;

class ARamArms : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARamArms(); // ����Ʈ ������
	~ARamArms(); // ����Ʈ �Ҹ���

	// delete Function
	ARamArms(const ARamArms& _Other) = delete; // ����Ʈ ���� ������
	ARamArms(ARamArms&& _Other) noexcept = delete; 
	ARamArms& operator=(const ARamArms& _Other) = delete; // ����Ʈ ���� ������
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

