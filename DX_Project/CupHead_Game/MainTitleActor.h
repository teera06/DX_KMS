#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class MainTitleActor : public AActor
{
public:
	// constrcuter destructer
	MainTitleActor(); // 디폴트 생성자
	~MainTitleActor(); // 디폴트 소멸자

	// delete Function
	MainTitleActor(const MainTitleActor& _Other) = delete; // 디폴트 복사 생성자
	MainTitleActor(MainTitleActor&& _Other) noexcept = delete; 
	MainTitleActor& operator=(const MainTitleActor& _Other) = delete; // 디폴트 대입 연산자
	MainTitleActor& operator=(MainTitleActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Renderer = nullptr;
};

