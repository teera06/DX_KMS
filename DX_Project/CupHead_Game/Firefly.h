#pragma once
class AFirefly
{
public:
	// constrcuter destructer
	AFirefly(); // 디폴트 생성자
	~AFirefly(); // 디폴트 소멸자

	// delete Function
	AFirefly(const AFirefly& _Other) = delete; // 디폴트 복사 생성자
	AFirefly(AFirefly&& _Other) noexcept = delete; 
	AFirefly& operator=(const AFirefly& _Other) = delete; // 디폴트 대입 연산자
	AFirefly& operator=(AFirefly&& _Other) noexcept = delete;

protected:

private:
};

