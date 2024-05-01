#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevilPlatform : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevilPlatform(); // ����Ʈ ������
	~ADevilPlatform(); // ����Ʈ �Ҹ���

	// delete Function
	ADevilPlatform(const ADevilPlatform& _Other) = delete; // ����Ʈ ���� ������
	ADevilPlatform(ADevilPlatform&& _Other) noexcept = delete; 
	ADevilPlatform& operator=(const ADevilPlatform& _Other) = delete; // ����Ʈ ���� ������
	ADevilPlatform& operator=(ADevilPlatform&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* DevilPlatform = nullptr;
	UCollision* GroundCollision = nullptr;
	UCollision* LRCollision = nullptr;

	void PlayerCollision();
};

