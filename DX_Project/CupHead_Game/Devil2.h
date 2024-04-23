#pragma once
#include <EngineCore/Actor.h>

#include "Boss2Common.h"

class USpriteRenderer;
class ADevil2 : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevil2(); // ����Ʈ ������
	~ADevil2(); // ����Ʈ �Ҹ���

	// delete Function
	ADevil2(const ADevil2& _Other) = delete; // ����Ʈ ���� ������
	ADevil2(ADevil2&& _Other) noexcept = delete; 
	ADevil2& operator=(const ADevil2& _Other) = delete; // ����Ʈ ���� ������
	ADevil2& operator=(ADevil2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;

	void AniCreate() override;
private:
	USpriteRenderer* Boss2 = nullptr;
	USpriteRenderer* DevilNeck = nullptr;

	void CreateBombBat();

	void DevilPhase2Idle(float _DeltaTime);
	void BombAttack(float _DeltaTime);
	void SpiralAttack(float _DeltaTime);
};

