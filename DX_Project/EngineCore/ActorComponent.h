#pragma once
class ActorComponent
{
public:
	// constrcuter destructer
	ActorComponent(); // 디폴트 생성자
	~ActorComponent(); // 디폴트 소멸자

	// delete Function
	ActorComponent(const ActorComponent& _Other) = delete; // 디폴트 복사 생성자
	ActorComponent(ActorComponent&& _Other) noexcept = delete; 
	ActorComponent& operator=(const ActorComponent& _Other) = delete; // 디폴트 대입 연산자
	ActorComponent& operator=(ActorComponent&& _Other) noexcept = delete;

protected:

private:
};

