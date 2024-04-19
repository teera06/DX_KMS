#pragma once
class MainMenuActor
{
public:
	// constrcuter destructer
	MainMenuActor(); // 디폴트 생성자
	~MainMenuActor(); // 디폴트 소멸자

	// delete Function
	MainMenuActor(const MainMenuActor& _Other) = delete; // 디폴트 복사 생성자
	MainMenuActor(MainMenuActor&& _Other) noexcept = delete; 
	MainMenuActor& operator=(const MainMenuActor& _Other) = delete; // 디폴트 대입 연산자
	MainMenuActor& operator=(MainMenuActor&& _Other) noexcept = delete;

protected:

private:
};

