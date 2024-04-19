#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;

class MainMenuActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	MainMenuActor(); // ����Ʈ ������
	~MainMenuActor(); // ����Ʈ �Ҹ���

	// delete Function
	MainMenuActor(const MainMenuActor& _Other) = delete; // ����Ʈ ���� ������
	MainMenuActor(MainMenuActor&& _Other) noexcept = delete; 
	MainMenuActor& operator=(const MainMenuActor& _Other) = delete; // ����Ʈ ���� ������
	MainMenuActor& operator=(MainMenuActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
};

