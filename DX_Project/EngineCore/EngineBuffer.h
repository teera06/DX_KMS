#pragma once
class EngineBuffer
{
public:
	// constrcuter destructer
	EngineBuffer(); // 디폴트 생성자
	~EngineBuffer(); // 디폴트 소멸자

	// delete Function
	EngineBuffer(const EngineBuffer& _Other) = delete; // 디폴트 복사 생성자
	EngineBuffer(EngineBuffer&& _Other) noexcept = delete; 
	EngineBuffer& operator=(const EngineBuffer& _Other) = delete; // 디폴트 대입 연산자
	EngineBuffer& operator=(EngineBuffer&& _Other) noexcept = delete;

protected:

private:
};

