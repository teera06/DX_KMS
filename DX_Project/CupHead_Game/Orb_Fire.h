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

	
	inline void SetDelay(const float& _Delay)
	{
		Delay = _Delay;
	}

	inline void SetParryCheck(const bool& _ParryCheck)
	{
		ParryCheck = _ParryCheck;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Orb_Fire = nullptr;

	FVector StartPos = FVector::Zero;
	FVector PlayerPos = FVector::Zero;
	FVector MoveNorMalize = FVector::Zero;

	

	float Speed = 350.0f;

	float Delay = 1.5f;

	bool EndAni = false;
	bool ParryCheck=false;
	bool OneCheck = false;
	bool OneCheck2 = false;
	bool att = false;

	void CalDir(float _DeltaTime);
	void Collisiongather();
};

