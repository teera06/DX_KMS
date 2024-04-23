#pragma once
#include <Enginecore/Actor.h>
#include "Boss2MapCommon.h"

class USpriteRenderer;
class ABossBackMap2 : public AActor, public ABoss2MapCommon
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABossBackMap2(); // ����Ʈ ������
	~ABossBackMap2(); // ����Ʈ �Ҹ���

	// delete Function
	ABossBackMap2(const ABossBackMap2& _Other) = delete; // ����Ʈ ���� ������
	ABossBackMap2(ABossBackMap2&& _Other) noexcept = delete; 
	ABossBackMap2& operator=(const ABossBackMap2& _Other) = delete; // ����Ʈ ���� ������
	ABossBackMap2& operator=(ABossBackMap2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BossBackMap2 = nullptr;
	USpriteRenderer* Boss2rontObject = nullptr;
};

