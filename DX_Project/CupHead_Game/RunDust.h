#pragma once

class RunDust
{
public:
	// constrcuter destructer
	RunDust(); // 디폴트 생성자
	~RunDust(); // 디폴트 소멸자

	// delete Function
	RunDust(const RunDust& _Other) = delete; // 디폴트 복사 생성자
	RunDust(RunDust&& _Other) noexcept = delete; 
	RunDust& operator=(const RunDust& _Other) = delete; // 디폴트 대입 연산자
	RunDust& operator=(RunDust&& _Other) noexcept = delete;

protected:

private:
};

