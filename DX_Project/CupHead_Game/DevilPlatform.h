#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevilPlatform : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevilPlatform(); // 디폴트 생성자
	~ADevilPlatform(); // 디폴트 소멸자

	// delete Function
	ADevilPlatform(const ADevilPlatform& _Other) = delete; // 디폴트 복사 생성자
	ADevilPlatform(ADevilPlatform&& _Other) noexcept = delete; 
	ADevilPlatform& operator=(const ADevilPlatform& _Other) = delete; // 디폴트 대입 연산자
	ADevilPlatform& operator=(ADevilPlatform&& _Other) noexcept = delete;

	inline void SetGroundOrder(const int& _GroundOrder)
	{
		GroundOrder = _GroundOrder;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* DevilPlatform = nullptr;
	UCollision* GroundCollision = nullptr;
	UCollision* LRCollision = nullptr;

	int GroundOrder = 0;

	void PlayerCollision();
};

