#pragma once
#include <Enginecore/Actor.h>


class USpriteRenderer;
class ADushDust : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADushDust(); // ����Ʈ ������
	~ADushDust(); // ����Ʈ �Ҹ���

	// delete Function
	ADushDust(const ADushDust& _Other) = delete; // ����Ʈ ���� ������
	ADushDust(ADushDust&& _Other) noexcept = delete; 
	ADushDust& operator=(const ADushDust& _Other) = delete; // ����Ʈ ���� ������
	ADushDust& operator=(ADushDust&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Effect = nullptr;

	FVector PlayerPos = FVector::Zero;
};

