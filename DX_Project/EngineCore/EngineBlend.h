#pragma once
class EngineBlend
{
public:
	// constrcuter destructer
	EngineBlend(); // 디폴트 생성자
	~EngineBlend(); // 디폴트 소멸자

	// delete Function
	EngineBlend(const EngineBlend& _Other) = delete; // 디폴트 복사 생성자
	EngineBlend(EngineBlend&& _Other) noexcept = delete; 
	EngineBlend& operator=(const EngineBlend& _Other) = delete; // 디폴트 대입 연산자
	EngineBlend& operator=(EngineBlend&& _Other) noexcept = delete;

protected:

private:
};

