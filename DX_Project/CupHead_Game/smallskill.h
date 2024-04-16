#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;

class Asmallskill : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	Asmallskill(); // ����Ʈ ������
	~Asmallskill(); // ����Ʈ �Ҹ���

	// delete Function
	Asmallskill(const Asmallskill& _Other) = delete; // ����Ʈ ���� ������
	Asmallskill(Asmallskill&& _Other) noexcept = delete; 
	Asmallskill& operator=(const Asmallskill& _Other) = delete; // ����Ʈ ���� ������
	Asmallskill& operator=(Asmallskill&& _Other) noexcept = delete;

	inline void SetSmallSkillDir(const FVector& _SmallSkillDir)
	{
		SmallSkillDir = _SmallSkillDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* smallskillRender = nullptr;
	UCollision* smallskillCollision = nullptr;

	FVector SmallSkillDir = FVector::Zero;
	FVector Move = FVector::Zero;
	float Speed = 900.0f;

	void Collisiongather();
};
