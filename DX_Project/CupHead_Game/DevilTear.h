#pragma once

#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevilTear : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADevilTear(); // 디폴트 생성자
	~ADevilTear(); // 디폴트 소멸자

	// delete Function
	ADevilTear(const ADevilTear& _Other) = delete; // 디폴트 복사 생성자
	ADevilTear(ADevilTear&& _Other) noexcept = delete; 
	ADevilTear& operator=(const ADevilTear& _Other) = delete; // 디폴트 대입 연산자
	ADevilTear& operator=(ADevilTear&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Tear = nullptr;
};

