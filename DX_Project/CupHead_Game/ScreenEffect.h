#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AScreenEffect : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AScreenEffect(); // 디폴트 생성자
	~AScreenEffect(); // 디폴트 소멸자

	// delete Function
	AScreenEffect(const AScreenEffect& _Other) = delete; // 디폴트 복사 생성자
	AScreenEffect(AScreenEffect&& _Other) noexcept = delete; 
	AScreenEffect& operator=(const AScreenEffect& _Other) = delete; // 디폴트 대입 연산자
	AScreenEffect& operator=(AScreenEffect&& _Other) noexcept = delete;

	USpriteRenderer* GetFilterEffect()
	{
		return FilterEffect;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* OldFilter = nullptr;
	USpriteRenderer* FilterEffect = nullptr;
};

