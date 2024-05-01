#pragma once
#include <EngineCore/Actor.h>

#include "Boss2Common.h"

class USpriteRenderer;

class ARamArms : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARamArms(); // 디폴트 생성자
	~ARamArms(); // 디폴트 소멸자

	// delete Function
	ARamArms(const ARamArms& _Other) = delete; // 디폴트 복사 생성자
	ARamArms(ARamArms&& _Other) noexcept = delete; 
	ARamArms& operator=(const ARamArms& _Other) = delete; // 디폴트 대입 연산자
	ARamArms& operator=(ARamArms&& _Other) noexcept = delete;

	inline void SetSmallSkillDir(const FVector& _MoveLR)
	{
		MoveLR = _MoveLR;
	}

	USpriteRenderer* GetRamArms()
	{
		return RamArms;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;

	void AniCreate() override;
private:
	USpriteRenderer* RamArms = nullptr;

	FVector MoveLR = FVector::Zero;

	float speed = 800.0f;


	void RamArmsStart(float _DeltaTime);
	void RamArmsEnd(float _DeltaTime);
};

