#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject3 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject3(); // ����Ʈ ������
	~AMoveObject3(); // ����Ʈ �Ҹ���

	// delete Function
	AMoveObject3(const AMoveObject3& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject3(AMoveObject3&& _Other) noexcept = delete; 
	AMoveObject3& operator=(const AMoveObject3& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject3& operator=(AMoveObject3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* ObjectRender = nullptr;
	USpriteRenderer* ObjectFront = nullptr;
	USpriteRenderer* ObjectBallRender = nullptr;
	UCollision* BoxCollision = nullptr;
	UCollision* ballCollision = nullptr;

	FVector GravityVector = FVector::Zero; // �߷°� �ޱ�

	FVector JumpVector = FVector::Up * 1800.0f; // ���� ������

	FVector DownPower = FVector::Zero;

	float Speed = 500.0f;

	float Gravity = 3000.0f;

	void Collisiongather(float _DeltaTime);
	void BallMove(float _DeltaTime);

	void PlayerCollisionCheck();
};

