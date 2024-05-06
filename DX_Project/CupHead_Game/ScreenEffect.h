#pragma once
#include <Enginecore/Actor.h>

#include "ContentsENum.h"
class USpriteRenderer;
class AScreenEffect : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AScreenEffect(); // ����Ʈ ������
	~AScreenEffect(); // ����Ʈ �Ҹ���

	// delete Function
	AScreenEffect(const AScreenEffect& _Other) = delete; // ����Ʈ ���� ������
	AScreenEffect(AScreenEffect&& _Other) noexcept = delete; 
	AScreenEffect& operator=(const AScreenEffect& _Other) = delete; // ����Ʈ ���� ������
	AScreenEffect& operator=(AScreenEffect&& _Other) noexcept = delete;

	USpriteRenderer* GetFilterEffect()
	{
		return FilterEffect;
	}

	void SetScreenEffect(const EScreenEffect& _Effect)
	{
		Effect = _Effect;
	}

	void SetBossZone(const int& _BossZone)
	{
		BossZone = _BossZone;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* FilterEffect = nullptr;

	EScreenEffect Effect = EScreenEffect::None;

	int BossZone = 0;
};

