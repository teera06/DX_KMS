#pragma once
#include "ContentsENum.h"

class APlayerCommon
{
public:
	// constrcuter destructer
	APlayerCommon(); // 디폴트 생성자
	~APlayerCommon(); // 디폴트 소멸자

	// delete Function
	APlayerCommon(const APlayerCommon& _Other) = delete; // 디폴트 복사 생성자
	APlayerCommon(APlayerCommon&& _Other) noexcept = delete; 
	APlayerCommon& operator=(const APlayerCommon& _Other) = delete; // 디폴트 대입 연산자
	APlayerCommon& operator=(APlayerCommon&& _Other) noexcept = delete;

protected:
	virtual void DirCheck();
	virtual void MoveUpDate(float _DeltaTime, FVector _MovePos=FVector::Zero);

	EDir Dir = EDir::None;
private:
};

