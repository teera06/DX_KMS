#pragma once
class EngineConstantBuffer
{
public:
	// constrcuter destructer
	EngineConstantBuffer(); // 디폴트 생성자
	~EngineConstantBuffer(); // 디폴트 소멸자

	// delete Function
	EngineConstantBuffer(const EngineConstantBuffer& _Other) = delete; // 디폴트 복사 생성자
	EngineConstantBuffer(EngineConstantBuffer&& _Other) noexcept = delete; 
	EngineConstantBuffer& operator=(const EngineConstantBuffer& _Other) = delete; // 디폴트 대입 연산자
	EngineConstantBuffer& operator=(EngineConstantBuffer&& _Other) noexcept = delete;

protected:

private:
};

