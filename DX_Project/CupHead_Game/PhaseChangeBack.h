#pragma once
#include <Enginecore/Actor.h>
#include "Boss2MapCommon.h"

class USpriteRenderer;

class APhaseChangeBack : public AActor, public ABoss2MapCommon
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	APhaseChangeBack(); // ����Ʈ ������
	~APhaseChangeBack(); // ����Ʈ �Ҹ���

	// delete Function
	APhaseChangeBack(const APhaseChangeBack& _Other) = delete; // ����Ʈ ���� ������
	APhaseChangeBack(APhaseChangeBack&& _Other) noexcept = delete; 
	APhaseChangeBack& operator=(const APhaseChangeBack& _Other) = delete; // ����Ʈ ���� ������
	APhaseChangeBack& operator=(APhaseChangeBack&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* PhaseChangeBack = nullptr;

	float Speed = 800.0f;

	bool OneCheck = false;
};

