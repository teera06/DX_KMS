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

	float speed = 500.0f;


	//void RamArmsStart(float _DeltaTime);
	//void RamArmsEnd(float _DeltaTime);
};

