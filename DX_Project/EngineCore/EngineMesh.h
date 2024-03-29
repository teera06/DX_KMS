#pragma once
class EngineMesh
{
public:
	// constrcuter destructer
	EngineMesh(); // 디폴트 생성자
	~EngineMesh(); // 디폴트 소멸자

	// delete Function
	EngineMesh(const EngineMesh& _Other) = delete; // 디폴트 복사 생성자
	EngineMesh(EngineMesh&& _Other) noexcept = delete; 
	EngineMesh& operator=(const EngineMesh& _Other) = delete; // 디폴트 대입 연산자
	EngineMesh& operator=(EngineMesh&& _Other) noexcept = delete;

protected:

private:
};

