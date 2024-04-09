#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
class ABoss3Map : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss3Map(); // ����Ʈ ������
	~ABoss3Map(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss3Map(const ABoss3Map& _Other) = delete; // ����Ʈ ���� ������
	ABoss3Map(ABoss3Map&& _Other) noexcept = delete; 
	ABoss3Map& operator=(const ABoss3Map& _Other) = delete; // ����Ʈ ���� ������
	ABoss3Map& operator=(ABoss3Map&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* back3Map = nullptr;
};

