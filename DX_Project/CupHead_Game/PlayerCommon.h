#pragma once

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

	static int StageCount;
protected:
private:
};

