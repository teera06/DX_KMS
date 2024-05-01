#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class ABossBackMap1 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABossBackMap1(); // ����Ʈ ������
	~ABossBackMap1(); // ����Ʈ �Ҹ���

	// delete Function
	ABossBackMap1(const ABossBackMap1& _Other) = delete; // ����Ʈ ���� ������
	ABossBackMap1(ABossBackMap1&& _Other) noexcept = delete; 
	ABossBackMap1& operator=(const ABossBackMap1& _Other) = delete; // ����Ʈ ���� ������
	ABossBackMap1& operator=(ABossBackMap1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BossBackMap1 = nullptr;
	USpriteRenderer* Front = nullptr;

	float CoolDownTime = 3.0f;

	bool LRCheck = false;
};

