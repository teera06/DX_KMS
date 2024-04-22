#pragma once

#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;
class ADemonMonster : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADemonMonster(); // ����Ʈ ������
	~ADemonMonster(); // ����Ʈ �Ҹ���

	// delete Function
	ADemonMonster(const ADemonMonster& _Other) = delete; // ����Ʈ ���� ������
	ADemonMonster(ADemonMonster&& _Other) noexcept = delete; 
	ADemonMonster& operator=(const ADemonMonster& _Other) = delete; // ����Ʈ ���� ������
	ADemonMonster& operator=(ADemonMonster&& _Other) noexcept = delete;

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Demon = nullptr;

	float speed = 500.0f;
};

