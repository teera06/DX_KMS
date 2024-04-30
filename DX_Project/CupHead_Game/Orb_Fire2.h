#pragma once
class Orb_Fire2
{
public:
	// constrcuter destructer
	Orb_Fire2(); // 디폴트 생성자
	~Orb_Fire2(); // 디폴트 소멸자

	// delete Function
	Orb_Fire2(const Orb_Fire2& _Other) = delete; // 디폴트 복사 생성자
	Orb_Fire2(Orb_Fire2&& _Other) noexcept = delete; 
	Orb_Fire2& operator=(const Orb_Fire2& _Other) = delete; // 디폴트 대입 연산자
	Orb_Fire2& operator=(Orb_Fire2&& _Other) noexcept = delete;

protected:

private:
};

