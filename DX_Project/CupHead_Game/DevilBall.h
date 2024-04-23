#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;

class ADevilBall : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ADevilBall(); // ����Ʈ ������
	~ADevilBall(); // ����Ʈ �Ҹ���

	// delete Function
	ADevilBall(const ADevilBall& _Other) = delete; // ����Ʈ ���� ������
	ADevilBall(ADevilBall&& _Other) noexcept = delete; 
	ADevilBall& operator=(const ADevilBall& _Other) = delete; // ����Ʈ ���� ������
	ADevilBall& operator=(ADevilBall&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* DevilBall = nullptr;
};

