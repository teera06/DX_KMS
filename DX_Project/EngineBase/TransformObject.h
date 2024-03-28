#pragma once
class TransformObject
{
public:
	// constrcuter destructer
	TransformObject(); // 디폴트 생성자
	~TransformObject(); // 디폴트 소멸자

	// delete Function
	TransformObject(const TransformObject& _Other) = delete; // 디폴트 복사 생성자
	TransformObject(TransformObject&& _Other) noexcept = delete; 
	TransformObject& operator=(const TransformObject& _Other) = delete; // 디폴트 대입 연산자
	TransformObject& operator=(TransformObject&& _Other) noexcept = delete;

protected:

private:
};

