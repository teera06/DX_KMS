#pragma once
#include "ContentsENum.h"

class UPlayerCommon
{
public:
	// constrcuter destructer
	UPlayerCommon(); // 디폴트 생성자
	~UPlayerCommon(); // 디폴트 소멸자

	// delete Function
	UPlayerCommon(const UPlayerCommon& _Other) = delete; // 디폴트 복사 생성자
	UPlayerCommon(UPlayerCommon&& _Other) noexcept = delete; 
	UPlayerCommon& operator=(const UPlayerCommon& _Other) = delete; // 디폴트 대입 연산자
	UPlayerCommon& operator=(UPlayerCommon&& _Other) noexcept = delete;

protected:
	virtual void DirCheck();
	virtual void MoveUpDate(float _DeltaTime, FVector _MovePos=FVector::Zero);

	EDir Dir = EDir::None;
private:
};

