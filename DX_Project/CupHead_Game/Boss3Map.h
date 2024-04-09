#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
class ABoss3Map : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss3Map(); // 디폴트 생성자
	~ABoss3Map(); // 디폴트 소멸자

	// delete Function
	ABoss3Map(const ABoss3Map& _Other) = delete; // 디폴트 복사 생성자
	ABoss3Map(ABoss3Map&& _Other) noexcept = delete; 
	ABoss3Map& operator=(const ABoss3Map& _Other) = delete; // 디폴트 대입 연산자
	ABoss3Map& operator=(ABoss3Map&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* back3Map = nullptr;
};

