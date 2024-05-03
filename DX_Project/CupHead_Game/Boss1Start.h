#pragma once
#include "CommonStart.h"

class ABoss1Start : public ACommonStart
{
	GENERATED_BODY(ACommonStart)
public:
	// constrcuter destructer
	ABoss1Start(); // ����Ʈ ������
	~ABoss1Start(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss1Start(const ABoss1Start& _Other) = delete; // ����Ʈ ���� ������
	ABoss1Start(ABoss1Start&& _Other) noexcept = delete; 
	ABoss1Start& operator=(const ABoss1Start& _Other) = delete; // ����Ʈ ���� ������
	ABoss1Start& operator=(ABoss1Start&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void AniCreate() override;
private:
	
};

