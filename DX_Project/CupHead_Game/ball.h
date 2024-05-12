
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

	void SetStartPos(const FVector& _StartPos)
	{
		StartPos = _StartPos;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ballRender = nullptr;
	USpriteRenderer* FxRender = nullptr;
	UCollision* ballCollision = nullptr;


	float Speed =450.0f;

	FVector StartPos = FVector::Zero;

	FVector RenderRot = FVector(0.0f, 0.0f, 35.0f);
	FVector Renderpox = FVector(0.0f, 70.0f, 0.0f);

	float XPos = 0.0f;
	float YPos = 0.0f;

	float diameter = 100.0f;

	float VectorX = -0.1f;
	float VectorY = 0.36f;

	bool OnePosUpDown = false;
	bool OneCheck = false;
	bool UpDown = false;
	// false== Up
	// true==Donw

	void CollisiongatherUp(float _DeltaTime);
	void CollisiongatherDown(float _DeltaTime);

	void PlayerCollisionCheck();
};

