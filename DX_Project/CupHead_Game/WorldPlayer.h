#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AWorldPlayer : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldPlayer(); // 디폴트 생성자
	~AWorldPlayer(); // 디폴트 소멸자

	// delete Function
	AWorldPlayer(const AWorldPlayer& _Other) = delete; // 디폴트 복사 생성자
	AWorldPlayer(AWorldPlayer&& _Other) noexcept = delete; 
	AWorldPlayer& operator=(const AWorldPlayer& _Other) = delete; // 디폴트 대입 연산자
	AWorldPlayer& operator=(AWorldPlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* WorldPlayerRenderer = nullptr;
};

