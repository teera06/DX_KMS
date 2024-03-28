#pragma once
class Camera
{
public:
	// constrcuter destructer
	Camera(); // 디폴트 생성자
	~Camera(); // 디폴트 소멸자

	// delete Function
	Camera(const Camera& _Other) = delete; // 디폴트 복사 생성자
	Camera(Camera&& _Other) noexcept = delete; 
	Camera& operator=(const Camera& _Other) = delete; // 디폴트 대입 연산자
	Camera& operator=(Camera&& _Other) noexcept = delete;

protected:

private:
};

