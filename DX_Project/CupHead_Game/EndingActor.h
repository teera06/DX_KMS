#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AEndingActor: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AEndingActor(); // 디폴트 생성자
	~AEndingActor(); // 디폴트 소멸자

	// delete Function
	AEndingActor(const AEndingActor& _Other) = delete; // 디폴트 복사 생성자
	AEndingActor(AEndingActor&& _Other) noexcept = delete; 
	AEndingActor& operator=(const AEndingActor& _Other) = delete; // 디폴트 대입 연산자
	AEndingActor& operator=(AEndingActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	UEngineSoundPlayer BGM;
	USpriteRenderer* end = nullptr;

};

