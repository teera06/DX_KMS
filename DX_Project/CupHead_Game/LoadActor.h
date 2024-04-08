#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ALoadActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ALoadActor(); // ����Ʈ ������
	~ALoadActor(); // ����Ʈ �Ҹ���

	// delete Function
	ALoadActor(const ALoadActor& _Other) = delete; // ����Ʈ ���� ������
	ALoadActor(ALoadActor&& _Other) noexcept = delete; 
	ALoadActor& operator=(const ALoadActor& _Other) = delete; // ����Ʈ ���� ������
	ALoadActor& operator=(ALoadActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* timmer = nullptr;
};

