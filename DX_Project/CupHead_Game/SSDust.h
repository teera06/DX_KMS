#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class ASSDust : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ASSDust(); // ����Ʈ ������
	~ASSDust(); // ����Ʈ �Ҹ���

	// delete Function
	ASSDust(const ASSDust& _Other) = delete; // ����Ʈ ���� ������
	ASSDust(ASSDust&& _Other) noexcept = delete; 
	ASSDust& operator=(const ASSDust& _Other) = delete; // ����Ʈ ���� ������
	ASSDust& operator=(ASSDust&& _Other) noexcept = delete;
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

