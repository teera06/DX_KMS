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
	UCollision* TopCollision = nullptr;
	UCollision* LRCollision = nullptr;

	float Speed = 200.0f;

	void Collisiongather(float _DeltaTime);
};

