#pragma once
class EngineOption
{
public:
	// constrcuter destructer
	EngineOption(); // 디폴트 생성자
	~EngineOption(); // 디폴트 소멸자

	// delete Function
	EngineOption(const EngineOption& _Other) = delete; // 디폴트 복사 생성자
	EngineOption(EngineOption&& _Other) noexcept = delete; 
	EngineOption& operator=(const EngineOption& _Other) = delete; // 디폴트 대입 연산자
	EngineOption& operator=(EngineOption&& _Other) noexcept = delete;

protected:

private:
};

