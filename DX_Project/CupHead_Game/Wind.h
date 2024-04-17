#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AWind : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWind(); // ����Ʈ ������
	~AWind(); // ����Ʈ �Ҹ���

	// delete Function
	AWind(const AWind& _Other) = delete; // ����Ʈ ���� ������
	AWind(AWind&& _Other) noexcept = delete; 
	AWind& operator=(const AWind& _Other) = delete; // ����Ʈ ���� ������
	AWind& operator=(AWind&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	USpriteRenderer* WindRender = nullptr;
	UCollision* WindCollision = nullptr;

	float Speed = 200.0f;
};

