#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class AGroundDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AGroundDust(); // ����Ʈ ������
	~AGroundDust(); // ����Ʈ �Ҹ���

	// delete Function
	AGroundDust(const AGroundDust& _Other) = delete; // ����Ʈ ���� ������
	AGroundDust(AGroundDust&& _Other) noexcept = delete; 
	AGroundDust& operator=(const AGroundDust& _Other) = delete; // ����Ʈ ���� ������
	AGroundDust& operator=(AGroundDust&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;
};

