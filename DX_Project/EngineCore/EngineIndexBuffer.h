#pragma once
class EngineIndexBuffer
{
public:
	// constrcuter destructer
	EngineIndexBuffer(); // 디폴트 생성자
	~EngineIndexBuffer(); // 디폴트 소멸자

	// delete Function
	EngineIndexBuffer(const EngineIndexBuffer& _Other) = delete; // 디폴트 복사 생성자
	EngineIndexBuffer(EngineIndexBuffer&& _Other) noexcept = delete; 
	EngineIndexBuffer& operator=(const EngineIndexBuffer& _Other) = delete; // 디폴트 대입 연산자
	EngineIndexBuffer& operator=(EngineIndexBuffer&& _Other) noexcept = delete;

protected:

private:
};

