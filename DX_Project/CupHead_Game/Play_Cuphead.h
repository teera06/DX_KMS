#pragma once
#include <EngineCore/Actor.h>

class APlay_Cuphead : public AActor
{
public:
	// constrcuter destructer
	APlay_Cuphead(); // ����Ʈ ������
	~APlay_Cuphead(); // ����Ʈ �Ҹ���

	// delete Function
	APlay_Cuphead(const APlay_Cuphead& _Other) = delete; // ����Ʈ ���� ������
	APlay_Cuphead(APlay_Cuphead&& _Other) noexcept = delete; 
	APlay_Cuphead& operator=(const APlay_Cuphead& _Other) = delete; // ����Ʈ ���� ������
	APlay_Cuphead& operator=(APlay_Cuphead&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
};

