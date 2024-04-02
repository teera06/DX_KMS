#pragma once
class DirectXHelper
{
public:
	// constrcuter destructer
	DirectXHelper(); // 디폴트 생성자
	~DirectXHelper(); // 디폴트 소멸자

	// delete Function
	DirectXHelper(const DirectXHelper& _Other) = delete; // 디폴트 복사 생성자
	DirectXHelper(DirectXHelper&& _Other) noexcept = delete; 
	DirectXHelper& operator=(const DirectXHelper& _Other) = delete; // 디폴트 대입 연산자
	DirectXHelper& operator=(DirectXHelper&& _Other) noexcept = delete;

protected:

private:
};

