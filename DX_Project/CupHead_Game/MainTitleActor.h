#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AMainTitleActor : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMainTitleActor(); // ����Ʈ ������
	~AMainTitleActor(); // ����Ʈ �Ҹ���

	// delete Function
	AMainTitleActor(const AMainTitleActor& _Other) = delete; // ����Ʈ ���� ������
	AMainTitleActor(AMainTitleActor&& _Other) noexcept = delete; 
	AMainTitleActor& operator=(const AMainTitleActor& _Other) = delete; // ����Ʈ ���� ������
	AMainTitleActor& operator=(AMainTitleActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* titleRenderer = nullptr;
	USpriteRenderer* CupRenderer = nullptr;

	void DebugMessageFunction();
};

