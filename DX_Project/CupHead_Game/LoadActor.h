#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ALoadActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ALoadActor(); // 디폴트 생성자
	~ALoadActor(); // 디폴트 소멸자

	// delete Function
	ALoadActor(const ALoadActor& _Other) = delete; // 디폴트 복사 생성자
	ALoadActor(ALoadActor&& _Other) noexcept = delete; 
	ALoadActor& operator=(const ALoadActor& _Other) = delete; // 디폴트 대입 연산자
	ALoadActor& operator=(ALoadActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* timmer = nullptr;
};

