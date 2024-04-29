#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;

class ACoin : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ACoin(); // ����Ʈ ������
	~ACoin(); // ����Ʈ �Ҹ���

	// delete Function
	ACoin(const ACoin& _Other) = delete; // ����Ʈ ���� ������
	ACoin(ACoin&& _Other) noexcept = delete; 
	ACoin& operator=(const ACoin& _Other) = delete; // ����Ʈ ���� ������
	ACoin& operator=(ACoin&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* CoinRender = nullptr;
	UCollision* CoinCollision = nullptr;

	FVector PlayerPos = FVector::Zero;
	FVector MoveNorMalize = FVector::Zero;

	float Speed = 500.0f;

	bool OneCheck = false;
	bool OneCheck2 = false;

	void CalDir(float _DeltaTime);
	void CollisionCheck();
};

