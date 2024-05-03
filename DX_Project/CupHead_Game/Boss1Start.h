#pragma once
#include <EngineCore/Actor.h>


class USpriteRenderer;

class ABoss1Start : public AActor
{
public:
	// constrcuter destructer
	ABoss1Start(); // 디폴트 생성자
	~ABoss1Start(); // 디폴트 소멸자

	// delete Function
	ABoss1Start(const ABoss1Start& _Other) = delete; // 디폴트 복사 생성자
	ABoss1Start(ABoss1Start&& _Other) noexcept = delete; 
	ABoss1Start& operator=(const ABoss1Start& _Other) = delete; // 디폴트 대입 연산자
	ABoss1Start& operator=(ABoss1Start&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	
private:
	USpriteRenderer* StartRender = nullptr;
};

