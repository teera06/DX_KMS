#pragma once
class EnginePixelShader
{
public:
	// constrcuter destructer
	EnginePixelShader(); // 디폴트 생성자
	~EnginePixelShader(); // 디폴트 소멸자

	// delete Function
	EnginePixelShader(const EnginePixelShader& _Other) = delete; // 디폴트 복사 생성자
	EnginePixelShader(EnginePixelShader&& _Other) noexcept = delete; 
	EnginePixelShader& operator=(const EnginePixelShader& _Other) = delete; // 디폴트 대입 연산자
	EnginePixelShader& operator=(EnginePixelShader&& _Other) noexcept = delete;

protected:

private:
};

