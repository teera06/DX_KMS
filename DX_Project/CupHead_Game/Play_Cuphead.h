#pragma once
#include <EngineCore/Actor.h>

class APlay_Cuphead : public AActor
{
public:
	// constrcuter destructer
	APlay_Cuphead(); // 디폴트 생성자
	~APlay_Cuphead(); // 디폴트 소멸자

	// delete Function
	APlay_Cuphead(const APlay_Cuphead& _Other) = delete; // 디폴트 복사 생성자
	APlay_Cuphead(APlay_Cuphead&& _Other) noexcept = delete; 
	APlay_Cuphead& operator=(const APlay_Cuphead& _Other) = delete; // 디폴트 대입 연산자
	APlay_Cuphead& operator=(APlay_Cuphead&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
};

