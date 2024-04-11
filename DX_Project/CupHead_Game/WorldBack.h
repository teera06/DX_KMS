#pragma once
#include <EngineCore/Actor.h>
class USpriteRenderer;
class AWorldBack : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldBack(); // ����Ʈ ������
	~AWorldBack(); // ����Ʈ �Ҹ���

	// delete Function
	AWorldBack(const AWorldBack& _Other) = delete; // ����Ʈ ���� ������
	AWorldBack(AWorldBack&& _Other) noexcept = delete; 
	AWorldBack& operator=(const AWorldBack& _Other) = delete; // ����Ʈ ���� ������
	AWorldBack& operator=(AWorldBack&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ColRenderer;
	float4 Color;
};

