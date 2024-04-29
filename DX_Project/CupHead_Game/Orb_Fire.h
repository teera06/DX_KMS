#pragma once

#include <EngineCore/Actor.h>

class USpriteRenderer;

class AOrb_Fire : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AOrb_Fire(); // ����Ʈ ������
	~AOrb_Fire(); // ����Ʈ �Ҹ���

	// delete Function
	AOrb_Fire(const AOrb_Fire& _Other) = delete; // ����Ʈ ���� ������
	AOrb_Fire(AOrb_Fire&& _Other) noexcept = delete; 
	AOrb_Fire& operator=(const AOrb_Fire& _Other) = delete; // ����Ʈ ���� ������
	AOrb_Fire& operator=(AOrb_Fire&& _Other) noexcept = delete;
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

	float Speed = 600.0f;
	float Delay = 1.5f;

	int WallHitCount = 0;

	int HitCount = 0;

	bool ParryCheck = false;

	void Collisiongather(float _DeltaTime);
};

