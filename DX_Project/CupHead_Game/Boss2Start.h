#pragma once

#include "CommonStart.h"

class ABoss2Start : public ACommonStart
{
	GENERATED_BODY(ACommonStart)
public:
	// constrcuter destructer
	ABoss2Start(); // ����Ʈ ������
	~ABoss2Start(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss2Start(const ABoss2Start& _Other) = delete; // ����Ʈ ���� ������
	ABoss2Start(ABoss2Start&& _Other) noexcept = delete; 
	ABoss2Start& operator=(const ABoss2Start& _Other) = delete; // ����Ʈ ���� ������
	ABoss2Start& operator=(ABoss2Start&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	
};

