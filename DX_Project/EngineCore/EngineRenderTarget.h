#pragma once
class EngineRenderTarget
{
public:
	// constrcuter destructer
	EngineRenderTarget(); // 디폴트 생성자
	~EngineRenderTarget(); // 디폴트 소멸자

	// delete Function
	EngineRenderTarget(const EngineRenderTarget& _Other) = delete; // 디폴트 복사 생성자
	EngineRenderTarget(EngineRenderTarget&& _Other) noexcept = delete; 
	EngineRenderTarget& operator=(const EngineRenderTarget& _Other) = delete; // 디폴트 대입 연산자
	EngineRenderTarget& operator=(EngineRenderTarget&& _Other) noexcept = delete;

protected:

private:
};

