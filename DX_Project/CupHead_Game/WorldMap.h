#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>

class AWorldMap : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldMap(); // ����Ʈ ������
	~AWorldMap(); // ����Ʈ �Ҹ���

	// delete Function
	AWorldMap(const AWorldMap& _Other) = delete; // ����Ʈ ���� ������
	AWorldMap(AWorldMap&& _Other) noexcept = delete; 
	AWorldMap& operator=(const AWorldMap& _Other) = delete; // ����Ʈ ���� ������
	AWorldMap& operator=(AWorldMap&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MapImageName); // �� �̹��� Set
	void SetColMapImage(std::string_view _MapImageName); // �ȼ� �浹 �� �̹��� Set

	void SwitchDebug();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* MapRenderer = nullptr;
};

