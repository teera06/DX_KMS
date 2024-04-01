#pragma once
class EngineRasterizer
{
public:
	// constrcuter destructer
	EngineRasterizer(); // 디폴트 생성자
	~EngineRasterizer(); // 디폴트 소멸자

	// delete Function
	EngineRasterizer(const EngineRasterizer& _Other) = delete; // 디폴트 복사 생성자
	EngineRasterizer(EngineRasterizer&& _Other) noexcept = delete; 
	EngineRasterizer& operator=(const EngineRasterizer& _Other) = delete; // 디폴트 대입 연산자
	EngineRasterizer& operator=(EngineRasterizer&& _Other) noexcept = delete;

protected:

private:
};

