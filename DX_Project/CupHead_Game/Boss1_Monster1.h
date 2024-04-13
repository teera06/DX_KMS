#pragma once
#include <EngineCore/Actor.h>

#include "Boss1Common.h"
class USpriteRenderer;
class ABoss1_Monster1 : public AActor, public ABoss1Common
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ABoss1_Monster1(); // ����Ʈ ������
	~ABoss1_Monster1(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss1_Monster1(const ABoss1_Monster1& _Other) = delete; // ����Ʈ ���� ������
	ABoss1_Monster1(ABoss1_Monster1&& _Other) noexcept = delete; 
	ABoss1_Monster1& operator=(const ABoss1_Monster1& _Other) = delete; // ����Ʈ ���� ������
	ABoss1_Monster1& operator=(ABoss1_Monster1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;
private:

	USpriteRenderer* SmallBoss1 = nullptr;

	float coolDownTime = 6.0f;

	int count = 0;
	bool att = false;

	// ���� 

	void smallIdle(float _DeltaTime);
	void smallatt(float _DeltaTime);
};

