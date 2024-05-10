#pragma once
class EndingLevel
{
public:
	// constrcuter destructer
	EndingLevel(); // 디폴트 생성자
	~EndingLevel(); // 디폴트 소멸자

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete; // 디폴트 복사 생성자
	EndingLevel(EndingLevel&& _Other) noexcept = delete; 
	EndingLevel& operator=(const EndingLevel& _Other) = delete; // 디폴트 대입 연산자
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

protected:

private:
};

