#pragma once

#include <Enginecore/Actor.h>


class USpriteRenderer;
class AWorldDust : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AWorldDust(); // ����Ʈ ������
	~AWorldDust(); // ����Ʈ �Ҹ���

	// delete Function
	AWorldDust(const AWorldDust& _Other) = delete; // ����Ʈ ���� ������
	AWorldDust(AWorldDust&& _Other) noexcept = delete; 
	AWorldDust& operator=(const AWorldDust& _Other) = delete; // ����Ʈ ���� ������
	AWorldDust& operator=(AWorldDust&& _Other) noexcept = delete;

protected:

private:
};

