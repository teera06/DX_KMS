#pragma once
#include <EngineCore/Actor.h>

#include "Boss2Common.h"

class USpriteRenderer;

class ASpiderHead : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ASpiderHead(); // 디폴트 생성자
	~ASpiderHead(); // 디폴트 소멸자

	// delete Function
	ASpiderHead(const ASpiderHead& _Other) = delete; // 디폴트 복사 생성자
	ASpiderHead(ASpiderHead&& _Other) noexcept = delete; 
	ASpiderHead& operator=(const ASpiderHead& _Other) = delete; // 디폴트 대입 연산자
	ASpiderHead& operator=(ASpiderHead&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;

	void AniCreate() override;
private:
	USpriteRenderer* SpiderHead = nullptr;

	//FVector MoveLR = FVector::Zero;
	FVector GravityVector = FVector::Zero; // 중력값 받기

	float speed = 500.0f;
	float Gravity = 3000.0f;

	void GroundCheck(float _DeltaTime);

	void SpiderHead_FallFromSky(float _DeltaTime);
	//void RamArmsEnd(float _DeltaTime);
};

