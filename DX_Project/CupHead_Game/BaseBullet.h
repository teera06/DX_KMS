#pragma once

#include <Enginecore/Actor.h>

class USpriteRenderer;
class ABaseBullet : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABaseBullet(); // ����Ʈ ������
	~ABaseBullet(); // ����Ʈ �Ҹ���

	// delete Function
	ABaseBullet(const ABaseBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseBullet(ABaseBullet&& _Other) noexcept = delete; 
	ABaseBullet& operator=(const ABaseBullet& _Other) = delete; // ����Ʈ ���� ������
	ABaseBullet& operator=(ABaseBullet&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* BulletRender = nullptr;
	UCollision* BulletCollision = nullptr;
};

