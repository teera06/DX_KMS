#pragma once
#include <EngineCore/Actor.h>
class USpriteRenderer;
class AWorldBack : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldBack(); // 디폴트 생성자
	~AWorldBack(); // 디폴트 소멸자

	// delete Function
	AWorldBack(const AWorldBack& _Other) = delete; // 디폴트 복사 생성자
	AWorldBack(AWorldBack&& _Other) noexcept = delete; 
	AWorldBack& operator=(const AWorldBack& _Other) = delete; // 디폴트 대입 연산자
	AWorldBack& operator=(AWorldBack&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ColRenderer;
	float4 Color;
};

