#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;

class AFirefly : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AFirefly(); // ����Ʈ ������
	~AFirefly(); // ����Ʈ �Ҹ���

	// delete Function
	AFirefly(const AFirefly& _Other) = delete; // ����Ʈ ���� ������
	AFirefly(AFirefly&& _Other) noexcept = delete; 
	AFirefly& operator=(const AFirefly& _Other) = delete; // ����Ʈ ���� ������
	AFirefly& operator=(AFirefly&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* FireflyRender = nullptr;
	UCollision* FireflyCollision = nullptr;
};
