#pragma once
class DefaultSceneComponent
{
public:
	// constrcuter destructer
	DefaultSceneComponent(); // 디폴트 생성자
	~DefaultSceneComponent(); // 디폴트 소멸자

	// delete Function
	DefaultSceneComponent(const DefaultSceneComponent& _Other) = delete; // 디폴트 복사 생성자
	DefaultSceneComponent(DefaultSceneComponent&& _Other) noexcept = delete; 
	DefaultSceneComponent& operator=(const DefaultSceneComponent& _Other) = delete; // 디폴트 대입 연산자
	DefaultSceneComponent& operator=(DefaultSceneComponent&& _Other) noexcept = delete;

protected:

private:
};

