#pragma once
class EngineShaderResources
{
public:
	// constrcuter destructer
	EngineShaderResources(); // 디폴트 생성자
	~EngineShaderResources(); // 디폴트 소멸자

	// delete Function
	EngineShaderResources(const EngineShaderResources& _Other) = delete; // 디폴트 복사 생성자
	EngineShaderResources(EngineShaderResources&& _Other) noexcept = delete; 
	EngineShaderResources& operator=(const EngineShaderResources& _Other) = delete; // 디폴트 대입 연산자
	EngineShaderResources& operator=(EngineShaderResources&& _Other) noexcept = delete;

protected:

private:
};

