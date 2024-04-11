#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class ABoss2Map : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss2Map(); // ����Ʈ ������
	~ABoss2Map(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss2Map(const ABoss2Map& _Other) = delete; // ����Ʈ ���� ������
	ABoss2Map(ABoss2Map&& _Other) noexcept = delete; 
	ABoss2Map& operator=(const ABoss2Map& _Other) = delete; // ����Ʈ ���� ������
	ABoss2Map& operator=(ABoss2Map&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* back2Map = nullptr;
	USpriteRenderer* crowd2 = nullptr;
};

