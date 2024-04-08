#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AWorldPlayer : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldPlayer(); // ����Ʈ ������
	~AWorldPlayer(); // ����Ʈ �Ҹ���

	// delete Function
	AWorldPlayer(const AWorldPlayer& _Other) = delete; // ����Ʈ ���� ������
	AWorldPlayer(AWorldPlayer&& _Other) noexcept = delete; 
	AWorldPlayer& operator=(const AWorldPlayer& _Other) = delete; // ����Ʈ ���� ������
	AWorldPlayer& operator=(AWorldPlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* WorldPlayerRenderer = nullptr;
};

