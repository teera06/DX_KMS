#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AEndingActor: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AEndingActor(); // ����Ʈ ������
	~AEndingActor(); // ����Ʈ �Ҹ���

	// delete Function
	AEndingActor(const AEndingActor& _Other) = delete; // ����Ʈ ���� ������
	AEndingActor(AEndingActor&& _Other) noexcept = delete; 
	AEndingActor& operator=(const AEndingActor& _Other) = delete; // ����Ʈ ���� ������
	AEndingActor& operator=(AEndingActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	UEngineSoundPlayer BGM;
	USpriteRenderer* end = nullptr;

};

