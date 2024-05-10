#pragma once
class EndingActor
{
public:
	// constrcuter destructer
	EndingActor(); // 디폴트 생성자
	~EndingActor(); // 디폴트 소멸자

	// delete Function
	EndingActor(const EndingActor& _Other) = delete; // 디폴트 복사 생성자
	EndingActor(EndingActor&& _Other) noexcept = delete; 
	EndingActor& operator=(const EndingActor& _Other) = delete; // 디폴트 대입 연산자
	EndingActor& operator=(EndingActor&& _Other) noexcept = delete;

protected:

private:
};

