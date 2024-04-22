#pragma once

#include <EngineCore/Actor.h>

#include "Boss2Common.h"
class USpriteRenderer;

class ADevil1 : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevil1(); // 디폴트 생성자
	~ADevil1(); // 디폴트 소멸자

	// delete Function
	ADevil1(const ADevil1& _Other) = delete; // 디폴트 복사 생성자
	ADevil1(ADevil1&& _Other) noexcept = delete; 
	ADevil1& operator=(const ADevil1& _Other) = delete; // 디폴트 대입 연산자
	ADevil1& operator=(ADevil1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void Phase1StateInit() override;

	void AniCreate() override;
private:
	USpriteRenderer* Boss2 = nullptr;
	USpriteRenderer* BossHead = nullptr;
	USpriteRenderer* BossBody = nullptr;


	// 여기서부터는 상태 함수들 
	void Phase1Intro(float _DeltaTime);
	void Phase1Idle(float _DeltaTime);
	void DragonTransform(float _DeltaTime);
};

