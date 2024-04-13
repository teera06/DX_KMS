#pragma once
#include "ContentsENum.h"

class APlayerCommon
{
public:
	// constrcuter destructer
	APlayerCommon(); // ����Ʈ ������
	~APlayerCommon(); // ����Ʈ �Ҹ���

	// delete Function
	APlayerCommon(const APlayerCommon& _Other) = delete; // ����Ʈ ���� ������
	APlayerCommon(APlayerCommon&& _Other) noexcept = delete; 
	APlayerCommon& operator=(const APlayerCommon& _Other) = delete; // ����Ʈ ���� ������
	APlayerCommon& operator=(APlayerCommon&& _Other) noexcept = delete;

protected:
	virtual void DirCheck();
	virtual void MoveUpDate(float _DeltaTime, FVector _MovePos=FVector::Zero);

	EDir Dir = EDir::None;
private:
};

