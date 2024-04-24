#pragma once
#include <EngineCore/Actor.h>

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Axe= nullptr;
	UCollision* AxeCollision = nullptr;
	float OneSpeed = 6000.0f;
	float MoveSpeed =200.0f;

	float Delay = 1.0f;
};

