#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* OldFilter = nullptr;
	USpriteRenderer* FilterEffect = nullptr;
};

