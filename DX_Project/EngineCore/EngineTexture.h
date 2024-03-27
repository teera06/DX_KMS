#pragma once
class EngineTexture
{
public:
	// constrcuter destructer
	EngineTexture(); // 디폴트 생성자
	~EngineTexture(); // 디폴트 소멸자

	// delete Function
	EngineTexture(const EngineTexture& _Other) = delete; // 디폴트 복사 생성자
	EngineTexture(EngineTexture&& _Other) noexcept = delete; 
	EngineTexture& operator=(const EngineTexture& _Other) = delete; // 디폴트 대입 연산자
	EngineTexture& operator=(EngineTexture&& _Other) noexcept = delete;

protected:

private:
};

