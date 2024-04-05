#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class MainTitleActor : public AActor
{
public:
	// constrcuter destructer
	MainTitleActor(); // ����Ʈ ������
	~MainTitleActor(); // ����Ʈ �Ҹ���

	// delete Function
	MainTitleActor(const MainTitleActor& _Other) = delete; // ����Ʈ ���� ������
	MainTitleActor(MainTitleActor&& _Other) noexcept = delete; 
	MainTitleActor& operator=(const MainTitleActor& _Other) = delete; // ����Ʈ ���� ������
	MainTitleActor& operator=(MainTitleActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Renderer = nullptr;
};

