#pragma once
#include <Enginecore/Actor.h>


class USpriteRenderer;
class ARunDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARunDust(); // ����Ʈ ������
	~ARunDust(); // ����Ʈ �Ҹ���

	// delete Function
	ARunDust(const ARunDust& _Other) = delete; // ����Ʈ ���� ������
	ARunDust(ARunDust&& _Other) noexcept = delete; 
	ARunDust& operator=(const ARunDust& _Other) = delete; // ����Ʈ ���� ������
	ARunDust& operator=(ARunDust&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;
};

