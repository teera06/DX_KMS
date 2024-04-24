#pragma once

#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevilTear : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADevilTear(); // ����Ʈ ������
	~ADevilTear(); // ����Ʈ �Ҹ���

	// delete Function
	ADevilTear(const ADevilTear& _Other) = delete; // ����Ʈ ���� ������
	ADevilTear(ADevilTear&& _Other) noexcept = delete; 
	ADevilTear& operator=(const ADevilTear& _Other) = delete; // ����Ʈ ���� ������
	ADevilTear& operator=(ADevilTear&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Tear = nullptr;
};

