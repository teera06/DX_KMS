#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ABoss1Map : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss1Map(); // ����Ʈ ������
	~ABoss1Map(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss1Map(const ABoss1Map& _Other) = delete; // ����Ʈ ���� ������
	ABoss1Map(ABoss1Map&& _Other) noexcept = delete; 
	ABoss1Map& operator=(const ABoss1Map& _Other) = delete; // ����Ʈ ���� ������
	ABoss1Map& operator=(ABoss1Map&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* back1Map = nullptr;
	//USpriteRenderer* back3Map = nullptr;
};

