#pragma once

#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevil1 : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevil1(); // ����Ʈ ������
	~ADevil1(); // ����Ʈ �Ҹ���

	// delete Function
	ADevil1(const ADevil1& _Other) = delete; // ����Ʈ ���� ������
	ADevil1(ADevil1&& _Other) noexcept = delete; 
	ADevil1& operator=(const ADevil1& _Other) = delete; // ����Ʈ ���� ������
	ADevil1& operator=(ADevil1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Boss2 = nullptr;
};

