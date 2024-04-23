#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevilBall : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADevilBall(); // ����Ʈ ������
	~ADevilBall(); // ����Ʈ �Ҹ���

	// delete Function
	ADevilBall(const ADevilBall& _Other) = delete; // ����Ʈ ���� ������
	ADevilBall(ADevilBall&& _Other) noexcept = delete; 
	ADevilBall& operator=(const ADevilBall& _Other) = delete; // ����Ʈ ���� ������
	ADevilBall& operator=(ADevilBall&& _Other) noexcept = delete;

	inline void SetStartPos(const FVector& _StartPos)
	{
		StartPos = _StartPos;
	}

	inline void SetWallHitCount(const int& _WallHitCount)
	{
		WallHitCount = _WallHitCount;
	}

	inline void SetParryCheck(const bool& _ParryCheck)
	{
		ParryCheck = _ParryCheck;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* DevilBall = nullptr;

	FVector StartPos = FVector::Zero;

	float Speed = 500.0f;
	float Delay = 1.5f;

	int WallHitCount = 0;

	int HitCount = 0;

	bool ParryCheck=false;

	void Collisiongather(float _DeltaTime);
};

