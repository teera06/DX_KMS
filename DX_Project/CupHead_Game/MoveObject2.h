#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject2 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject2(); // ����Ʈ ������
	~AMoveObject2(); // ����Ʈ �Ҹ���

	// delete Function
	AMoveObject2(const AMoveObject2& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject2(AMoveObject2&& _Other) noexcept = delete; 
	AMoveObject2& operator=(const AMoveObject2& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject2& operator=(AMoveObject2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* ObjectRender = nullptr;
	USpriteRenderer* ObjectFront = nullptr;
	USpriteRenderer* ObjectBallRender = nullptr;
	UCollision* BoxCollision = nullptr;

	FVector GravityVector = FVector::Zero; // �߷°� �ޱ�

	FVector JumpVector = FVector::Up * 1600.0f; // ���� ������

	float Speed = 100.0f;

	float Gravity = 3000.0f;

	void Collisiongather(float _DeltaTime);
	void BallMove(float _DeltaTime);
};

