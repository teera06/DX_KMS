#pragma once
class Asmallskill
{
public:
	// constrcuter destructer
	Asmallskill(); // 디폴트 생성자
	~Asmallskill(); // 디폴트 소멸자

	// delete Function
	Asmallskill(const Asmallskill& _Other) = delete; // 디폴트 복사 생성자
	Asmallskill(Asmallskill&& _Other) noexcept = delete; 
	Asmallskill& operator=(const Asmallskill& _Other) = delete; // 디폴트 대입 연산자
	Asmallskill& operator=(Asmallskill&& _Other) noexcept = delete;

protected:

private:
};

