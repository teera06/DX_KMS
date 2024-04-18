#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class MoveObject : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	MoveObject(); // ����Ʈ ������
	~MoveObject(); // ����Ʈ �Ҹ���

	// delete Function
	MoveObject(const MoveObject& _Other) = delete; // ����Ʈ ���� ������
	MoveObject(MoveObject&& _Other) noexcept = delete; 
	MoveObject& operator=(const MoveObject& _Other) = delete; // ����Ʈ ���� ������
	MoveObject& operator=(MoveObject&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* ObjectRender = nullptr;
	UCollision* TopCollision = nullptr;
};

