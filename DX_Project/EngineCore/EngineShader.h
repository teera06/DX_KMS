#pragma once
class EngineShader
{
public:
	// constrcuter destructer
	EngineShader(); // 디폴트 생성자
	~EngineShader(); // 디폴트 소멸자

	// delete Function
	EngineShader(const EngineShader& _Other) = delete; // 디폴트 복사 생성자
	EngineShader(EngineShader&& _Other) noexcept = delete; 
	EngineShader& operator=(const EngineShader& _Other) = delete; // 디폴트 대입 연산자
	EngineShader& operator=(EngineShader&& _Other) noexcept = delete;

protected:

private:
};

