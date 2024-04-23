#pragma once
#include <EngineCore/Actor.h>

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BombBat = nullptr;
};

