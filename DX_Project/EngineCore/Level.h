#pragma once
class Level
{
public:
	// constrcuter destructer
	Level(); // 디폴트 생성자
	~Level(); // 디폴트 소멸자

	// delete Function
	Level(const Level& _Other) = delete; // 디폴트 복사 생성자
	Level(Level&& _Other) noexcept = delete; 
	Level& operator=(const Level& _Other) = delete; // 디폴트 대입 연산자
	Level& operator=(Level&& _Other) noexcept = delete;

protected:

private:
};

