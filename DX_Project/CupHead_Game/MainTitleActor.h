#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AMainTitleActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMainTitleActor(); // 디폴트 생성자
	~AMainTitleActor(); // 디폴트 소멸자

	// delete Function
	AMainTitleActor(const AMainTitleActor& _Other) = delete; // 디폴트 복사 생성자
	AMainTitleActor(AMainTitleActor&& _Other) noexcept = delete; 
	AMainTitleActor& operator=(const AMainTitleActor& _Other) = delete; // 디폴트 대입 연산자
	AMainTitleActor& operator=(AMainTitleActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* titleRenderer = nullptr;
	USpriteRenderer* CupRenderer = nullptr;

	void DebugMessageFunction();
};

