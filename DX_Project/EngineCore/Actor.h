#pragma once
class Actor
{
public:
	// constrcuter destructer
	Actor(); // 디폴트 생성자
	~Actor(); // 디폴트 소멸자

	// delete Function
	Actor(const Actor& _Other) = delete; // 디폴트 복사 생성자
	Actor(Actor&& _Other) noexcept = delete; 
	Actor& operator=(const Actor& _Other) = delete; // 디폴트 대입 연산자
	Actor& operator=(Actor&& _Other) noexcept = delete;

protected:

private:
};

