#pragma once
class SceneComponent
{
public:
	// constrcuter destructer
	SceneComponent(); // 디폴트 생성자
	~SceneComponent(); // 디폴트 소멸자

	// delete Function
	SceneComponent(const SceneComponent& _Other) = delete; // 디폴트 복사 생성자
	SceneComponent(SceneComponent&& _Other) noexcept = delete; 
	SceneComponent& operator=(const SceneComponent& _Other) = delete; // 디폴트 대입 연산자
	SceneComponent& operator=(SceneComponent&& _Other) noexcept = delete;

protected:

private:
};

