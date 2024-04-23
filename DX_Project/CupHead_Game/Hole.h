#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class AHole : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AHole(); // ����Ʈ ������
	~AHole(); // ����Ʈ �Ҹ���

	// delete Function
	AHole(const AHole& _Other) = delete; // ����Ʈ ���� ������
	AHole(AHole&& _Other) noexcept = delete; 
	AHole& operator=(const AHole& _Other) = delete; // ����Ʈ ���� ������
	AHole& operator=(AHole&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* HoleBack = nullptr;
	USpriteRenderer* HoleFront = nullptr;
	USpriteRenderer* HoleSign = nullptr;

	UCollision* HoleCollision = nullptr;
};

