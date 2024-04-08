#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AWorldMap : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldMap(); // 디폴트 생성자
	~AWorldMap(); // 디폴트 소멸자

	// delete Function
	AWorldMap(const AWorldMap& _Other) = delete; // 디폴트 복사 생성자
	AWorldMap(AWorldMap&& _Other) noexcept = delete; 
	AWorldMap& operator=(const AWorldMap& _Other) = delete; // 디폴트 대입 연산자
	AWorldMap& operator=(AWorldMap&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* MapRenderer = nullptr;
};

