#pragma once

#include <EngineCore/Actor.h>


class USpriteRenderer;

class ACommonStart : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ACommonStart(); // ����Ʈ ������
	~ACommonStart(); // ����Ʈ �Ҹ���

	// delete Function
	ACommonStart(const ACommonStart& _Other) = delete; // ����Ʈ ���� ������
	ACommonStart(ACommonStart&& _Other) noexcept = delete; 
	ACommonStart& operator=(const ACommonStart& _Other) = delete; // ����Ʈ ���� ������
	ACommonStart& operator=(ACommonStart&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	virtual void AniCreate() = 0; // ���� �����Լ�

	USpriteRenderer* startRender = nullptr;
	UCollision* startCollision = nullptr;
private:
};

