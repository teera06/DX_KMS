
#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class Aball : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	Aball(); // ����Ʈ ������
	~Aball(); // ����Ʈ �Ҹ���

	// delete Function
	Aball(const Aball& _Other) = delete; // ����Ʈ ���� ������
	Aball(Aball&& _Other) noexcept = delete; 
	Aball& operator=(const Aball& _Other) = delete; // ����Ʈ ���� ������
	Aball& operator=(Aball&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ballRender = nullptr;
	UCollision* ballCollision = nullptr;

	float Speed =200.0f;

	FVector StartPos = FVector::Right + (FVector::Up*2.0f);

	float XPos = 0.0f;
	float YPos = 0.0f;

	float diameter = 100.0f;

	float VectorX = -0.1f;
	float VectorY = 0.36f;

	void Collisiongather(float _DeltaTime);
};

