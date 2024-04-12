#pragma once
#include <EngineCore/Actor.h>
class USpriteRenderer;
class ABoss1_Monster2 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss1_Monster2(); // ����Ʈ ������
	~ABoss1_Monster2(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss1_Monster2(const ABoss1_Monster2& _Other) = delete; // ����Ʈ ���� ������
	ABoss1_Monster2(ABoss1_Monster2&& _Other) noexcept = delete; 
	ABoss1_Monster2& operator=(const ABoss1_Monster2& _Other) = delete; // ����Ʈ ���� ������
	ABoss1_Monster2& operator=(ABoss1_Monster2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Boss1_1 = nullptr;
};

