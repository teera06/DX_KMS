#pragma once

#include <EngineCore/Actor.h>

class USpriteRenderer;

class AFatDemonSkill
	: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AFatDemonSkill(); // 디폴트 생성자
	~AFatDemonSkill(); // 디폴트 소멸자

	// delete Function
	AFatDemonSkill(const AFatDemonSkill& _Other) = delete; // 디폴트 복사 생성자
	AFatDemonSkill(AFatDemonSkill&& _Other) noexcept = delete; 
	AFatDemonSkill& operator=(const AFatDemonSkill& _Other) = delete; // 디폴트 대입 연산자
	AFatDemonSkill& operator=(AFatDemonSkill&& _Other) noexcept = delete;

	inline void SetParryCheck(bool _ParryCheck)
	{
		ParryCheck = _ParryCheck;
	}

	bool GetParryCheck()
	{
		return ParryCheck;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	
private:
	USpriteRenderer* Skill = nullptr;
	UCollision* FatSkill = nullptr;

	FVector Move = FVector::Zero;

	float Speed = 400.0f;

	bool DirOneChek = false;
	bool ParryCheck = false;

	void PlayerCollisionCheck();
};

