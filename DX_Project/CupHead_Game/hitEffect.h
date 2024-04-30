#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class AhitEffect : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AhitEffect(); // ����Ʈ ������
	~AhitEffect(); // ����Ʈ �Ҹ���

	// delete Function
	AhitEffect(const AhitEffect& _Other) = delete; // ����Ʈ ���� ������
	AhitEffect(AhitEffect&& _Other) noexcept = delete; 
	AhitEffect& operator=(const AhitEffect& _Other) = delete; // ����Ʈ ���� ������
	AhitEffect& operator=(AhitEffect&& _Other) noexcept = delete;

	inline void SethitDir(const FVector& _hitDir)
	{
		hitDir = _hitDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;

	FVector hitDir = FVector::Zero;
};

