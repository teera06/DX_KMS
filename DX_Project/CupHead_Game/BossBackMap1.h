#pragma once
class ABossBackMap1
{
public:
	// constrcuter destructer
	ABossBackMap1(); // 디폴트 생성자
	~ABossBackMap1(); // 디폴트 소멸자

	// delete Function
	ABossBackMap1(const ABossBackMap1& _Other) = delete; // 디폴트 복사 생성자
	ABossBackMap1(ABossBackMap1&& _Other) noexcept = delete; 
	ABossBackMap1& operator=(const ABossBackMap1& _Other) = delete; // 디폴트 대입 연산자
	ABossBackMap1& operator=(ABossBackMap1&& _Other) noexcept = delete;

protected:

private:
};

