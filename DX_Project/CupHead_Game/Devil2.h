#pragma once
#include <EngineCore/Actor.h>

#include "Boss2Common.h"

class USpriteRenderer;
class ADevil2 : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevil2(); // 디폴트 생성자
	~ADevil2(); // 디폴트 소멸자

	// delete Function
	ADevil2(const ADevil2& _Other) = delete; // 디폴트 복사 생성자
	ADevil2(ADevil2&& _Other) noexcept = delete; 
	ADevil2& operator=(const ADevil2& _Other) = delete; // 디폴트 대입 연산자
	ADevil2& operator=(ADevil2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;

	void AniCreate() override;
private:
	USpriteRenderer* Boss2 = nullptr;
};

