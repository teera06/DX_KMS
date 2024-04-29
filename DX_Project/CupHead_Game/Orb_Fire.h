#pragma once
class Orb_Fire
{
public:
	// constrcuter destructer
	Orb_Fire(); // 디폴트 생성자
	~Orb_Fire(); // 디폴트 소멸자

	// delete Function
	Orb_Fire(const Orb_Fire& _Other) = delete; // 디폴트 복사 생성자
	Orb_Fire(Orb_Fire&& _Other) noexcept = delete; 
	Orb_Fire& operator=(const Orb_Fire& _Other) = delete; // 디폴트 대입 연산자
	Orb_Fire& operator=(Orb_Fire&& _Other) noexcept = delete;

protected:

private:
};

