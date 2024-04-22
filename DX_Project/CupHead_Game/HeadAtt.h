#pragma once

#include <EngineCore/Actor.h>

#include "Boss2Common.h"
class USpriteRenderer;

class AHeadAtt : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AHeadAtt(); // 디폴트 생성자
	~AHeadAtt(); // 디폴트 소멸자

	// delete Function
	AHeadAtt(const AHeadAtt& _Other) = delete; // 디폴트 복사 생성자
	AHeadAtt(AHeadAtt&& _Other) noexcept = delete; 
	AHeadAtt& operator=(const AHeadAtt& _Other) = delete; // 디폴트 대입 연산자
	AHeadAtt& operator=(AHeadAtt&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* headatt = nullptr;
};

