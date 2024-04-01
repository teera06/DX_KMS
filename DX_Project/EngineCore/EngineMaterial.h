#pragma once
class EngineMaterial
{
public:
	// constrcuter destructer
	EngineMaterial(); // 디폴트 생성자
	~EngineMaterial(); // 디폴트 소멸자

	// delete Function
	EngineMaterial(const EngineMaterial& _Other) = delete; // 디폴트 복사 생성자
	EngineMaterial(EngineMaterial&& _Other) noexcept = delete; 
	EngineMaterial& operator=(const EngineMaterial& _Other) = delete; // 디폴트 대입 연산자
	EngineMaterial& operator=(EngineMaterial&& _Other) noexcept = delete;

protected:

private:
};

