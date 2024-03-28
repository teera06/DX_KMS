#pragma once
class GameMode
{
public:
	// constrcuter destructer
	GameMode(); // 디폴트 생성자
	~GameMode(); // 디폴트 소멸자

	// delete Function
	GameMode(const GameMode& _Other) = delete; // 디폴트 복사 생성자
	GameMode(GameMode&& _Other) noexcept = delete; 
	GameMode& operator=(const GameMode& _Other) = delete; // 디폴트 대입 연산자
	GameMode& operator=(GameMode&& _Other) noexcept = delete;

protected:

private:
};

