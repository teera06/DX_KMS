#pragma once
class TickObject
{
public:
	// constrcuter destructer
	TickObject(); // 디폴트 생성자
	~TickObject(); // 디폴트 소멸자

	// delete Function
	TickObject(const TickObject& _Other) = delete; // 디폴트 복사 생성자
	TickObject(TickObject&& _Other) noexcept = delete; 
	TickObject& operator=(const TickObject& _Other) = delete; // 디폴트 대입 연산자
	TickObject& operator=(TickObject&& _Other) noexcept = delete;

protected:

private:
};

