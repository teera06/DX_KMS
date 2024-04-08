#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class LoadActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	LoadActor(); // 디폴트 생성자
	~LoadActor(); // 디폴트 소멸자

	// delete Function
	LoadActor(const LoadActor& _Other) = delete; // 디폴트 복사 생성자
	LoadActor(LoadActor&& _Other) noexcept = delete; 
	LoadActor& operator=(const LoadActor& _Other) = delete; // 디폴트 대입 연산자
	LoadActor& operator=(LoadActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* timmer = nullptr;
};

