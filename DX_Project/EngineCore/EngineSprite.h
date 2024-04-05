#pragma once
class EngineSprite
{
public:
	// constrcuter destructer
	EngineSprite(); // 디폴트 생성자
	~EngineSprite(); // 디폴트 소멸자

	// delete Function
	EngineSprite(const EngineSprite& _Other) = delete; // 디폴트 복사 생성자
	EngineSprite(EngineSprite&& _Other) noexcept = delete; 
	EngineSprite& operator=(const EngineSprite& _Other) = delete; // 디폴트 대입 연산자
	EngineSprite& operator=(EngineSprite&& _Other) noexcept = delete;

protected:

private:
};

