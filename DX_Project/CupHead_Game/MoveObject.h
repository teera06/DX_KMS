#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject(); // ����Ʈ ������
	~AMoveObject(); // ����Ʈ �Ҹ���

	// delete Function
	AMoveObject(const AMoveObject& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject(AMoveObject&& _Other) noexcept = delete; 
	AMoveObject& operator=(const AMoveObject& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject& operator=(AMoveObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ObjectRender = nullptr;
	UCollision* TopCollision = nullptr;
	UCollision* LRCollision = nullptr;

	float Speed = 500.0f;

	void Collisiongather(float _DeltaTime);
};

