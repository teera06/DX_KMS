#pragma once
#include <EngineCore/Actor.h>

#include "Boss2Common.h"

class USpriteRenderer;

class ARamArms : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ARamArms(); // ����Ʈ ������
	~ARamArms(); // ����Ʈ �Ҹ���

	// delete Function
	ARamArms(const ARamArms& _Other) = delete; // ����Ʈ ���� ������
	ARamArms(ARamArms&& _Other) noexcept = delete; 
	ARamArms& operator=(const ARamArms& _Other) = delete; // ����Ʈ ���� ������
	ARamArms& operator=(ARamArms&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Phase1StateInit() override;

	void AniCreate() override;
private:
	USpriteRenderer* RamArms = nullptr;

	float speed = 500.0f;

	void RamArmsStart(float _DeltaTime);
	void RamArmsEnd(float _DeltaTime);
};

