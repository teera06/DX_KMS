#pragma once
class EngineInputLayOut
{
public:
	// constrcuter destructer
	EngineInputLayOut(); // 디폴트 생성자
	~EngineInputLayOut(); // 디폴트 소멸자

	// delete Function
	EngineInputLayOut(const EngineInputLayOut& _Other) = delete; // 디폴트 복사 생성자
	EngineInputLayOut(EngineInputLayOut&& _Other) noexcept = delete; 
	EngineInputLayOut& operator=(const EngineInputLayOut& _Other) = delete; // 디폴트 대입 연산자
	EngineInputLayOut& operator=(EngineInputLayOut&& _Other) noexcept = delete;

protected:

private:
};

