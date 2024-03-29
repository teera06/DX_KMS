#pragma once
class EngineVertexBuffer
{
public:
	// constrcuter destructer
	EngineVertexBuffer(); // 디폴트 생성자
	~EngineVertexBuffer(); // 디폴트 소멸자

	// delete Function
	EngineVertexBuffer(const EngineVertexBuffer& _Other) = delete; // 디폴트 복사 생성자
	EngineVertexBuffer(EngineVertexBuffer&& _Other) noexcept = delete; 
	EngineVertexBuffer& operator=(const EngineVertexBuffer& _Other) = delete; // 디폴트 대입 연산자
	EngineVertexBuffer& operator=(EngineVertexBuffer&& _Other) noexcept = delete;

protected:

private:
};

