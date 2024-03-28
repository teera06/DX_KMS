#pragma once
class Renderer
{
public:
	// constrcuter destructer
	Renderer(); // 디폴트 생성자
	~Renderer(); // 디폴트 소멸자

	// delete Function
	Renderer(const Renderer& _Other) = delete; // 디폴트 복사 생성자
	Renderer(Renderer&& _Other) noexcept = delete; 
	Renderer& operator=(const Renderer& _Other) = delete; // 디폴트 대입 연산자
	Renderer& operator=(Renderer&& _Other) noexcept = delete;

protected:

private:
};

