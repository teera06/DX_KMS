#pragma once
class ABoss2MapCommon
{
public:
	// constrcuter destructer
	ABoss2MapCommon(); // 디폴트 생성자
	~ABoss2MapCommon(); // 디폴트 소멸자

	// delete Function
	ABoss2MapCommon(const ABoss2MapCommon& _Other) = delete; // 디폴트 복사 생성자
	ABoss2MapCommon(ABoss2MapCommon&& _Other) noexcept = delete; 
	ABoss2MapCommon& operator=(const ABoss2MapCommon& _Other) = delete; // 디폴트 대입 연산자
	ABoss2MapCommon& operator=(ABoss2MapCommon&& _Other) noexcept = delete;


	static bool DelCheck;
protected:

private:
};

