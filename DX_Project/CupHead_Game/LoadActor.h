#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class LoadActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	LoadActor(); // ����Ʈ ������
	~LoadActor(); // ����Ʈ �Ҹ���

	// delete Function
	LoadActor(const LoadActor& _Other) = delete; // ����Ʈ ���� ������
	LoadActor(LoadActor&& _Other) noexcept = delete; 
	LoadActor& operator=(const LoadActor& _Other) = delete; // ����Ʈ ���� ������
	LoadActor& operator=(LoadActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* timmer = nullptr;
};

