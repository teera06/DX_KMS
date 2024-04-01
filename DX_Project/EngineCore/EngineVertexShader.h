#pragma once
class EngineVertexShader
{
public:
	// constrcuter destructer
	EngineVertexShader(); // 디폴트 생성자
	~EngineVertexShader(); // 디폴트 소멸자

	// delete Function
	EngineVertexShader(const EngineVertexShader& _Other) = delete; // 디폴트 복사 생성자
	EngineVertexShader(EngineVertexShader&& _Other) noexcept = delete; 
	EngineVertexShader& operator=(const EngineVertexShader& _Other) = delete; // 디폴트 대입 연산자
	EngineVertexShader& operator=(EngineVertexShader&& _Other) noexcept = delete;

protected:

private:
};

