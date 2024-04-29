#pragma once
#include <Enginecore/Actor.h>


class USpriteRenderer;
class ADashDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADashDust(); // ����Ʈ ������
	~ADashDust(); // ����Ʈ �Ҹ���

	// delete Function
	ADashDust(const ADashDust& _Other) = delete; // ����Ʈ ���� ������
	ADashDust(ADashDust&& _Other) noexcept = delete; 
	ADashDust& operator=(const ADashDust& _Other) = delete; // ����Ʈ ���� ������
	ADashDust& operator=(ADashDust&& _Other) noexcept = delete;

	inline void SetDushDir(const FVector& _DushDir)
	{
		DushDir = _DushDir;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;

	FVector DushDir = FVector::Zero;
};

