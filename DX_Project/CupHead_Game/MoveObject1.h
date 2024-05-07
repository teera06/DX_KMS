#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject1 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject1(); // ����Ʈ ������
	~AMoveObject1(); // ����Ʈ �Ҹ���

	// delete Function
	AMoveObject1(const AMoveObject1& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject1(AMoveObject1&& _Other) noexcept = delete; 
	AMoveObject1& operator=(const AMoveObject1& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject1& operator=(AMoveObject1&& _Other) noexcept = delete;

	void SetUpDownSet(const FVector& _UpDownSet)
	{
		UpDownSet = _UpDownSet;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	UEngineSoundPlayer LoopSound;
	USpriteRenderer* ObjectRender = nullptr;
	USpriteRenderer* ObjectFront = nullptr;
	USpriteRenderer* Fire = nullptr;
	UCollision* TopCollision = nullptr;
	UCollision* BodyCollision = nullptr;
	UCollision* FireCollision = nullptr;

	FVector UpPower = FVector::Zero;

	FVector UpDownSet = FVector::Zero;


	float Speed = 400.0f;

	bool OneCheck = false;

	bool changeFire = false;

	void PlayerCollision();
	void Collisiongather(float _DeltaTime);

	void ChangeFirePos();
};

