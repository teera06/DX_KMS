#pragma once

#include <EngineCore/Actor.h>


class USpriteRenderer;

class ACommonStart : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ACommonStart(); // 디폴트 생성자
	~ACommonStart(); // 디폴트 소멸자

	// delete Function
	ACommonStart(const ACommonStart& _Other) = delete; // 디폴트 복사 생성자
	ACommonStart(ACommonStart&& _Other) noexcept = delete; 
	ACommonStart& operator=(const ACommonStart& _Other) = delete; // 디폴트 대입 연산자
	ACommonStart& operator=(ACommonStart&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void AniCreate() = 0; // 순수 가상함수

	USpriteRenderer* startRender = nullptr;
	UCollision* startCollision = nullptr;
private:
};

