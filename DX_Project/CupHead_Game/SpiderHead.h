#pragma once
#include <EngineCore/Actor.h>

#include "Boss2Common.h"

class USpriteRenderer;

class ASpiderHead : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ASpiderHead(); // ����Ʈ ������
	~ASpiderHead(); // ����Ʈ �Ҹ���

	// delete Function
	ASpiderHead(const ASpiderHead& _Other) = delete; // ����Ʈ ���� ������
	ASpiderHead(ASpiderHead&& _Other) noexcept = delete; 
	ASpiderHead& operator=(const ASpiderHead& _Other) = delete; // ����Ʈ ���� ������
	ASpiderHead& operator=(ASpiderHead&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;

	void AniCreate() override;
private:
	USpriteRenderer* SpiderHead = nullptr;

	//FVector MoveLR = FVector::Zero;
	FVector GravityVector = FVector::Zero; // �߷°� �ޱ�
	FVector UpVector = FVector::Zero; // �߷°� �ޱ�

	float speed = 300.0f;
	float Gravity =150.0f;


	void SpiderHead_FallFromSky(float _DeltaTime);
	void SpiderHead_FallToFloor(float _DeltaTime);
	void SpiderHead_FlyToSky(float _DeltaTime);
	void SpiderHead_FlyToSky2(float _DeltaTime);
};

