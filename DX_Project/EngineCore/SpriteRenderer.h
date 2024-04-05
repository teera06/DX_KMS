#pragma once
class SpriteRenderer
{
public:
	// constrcuter destructer
	SpriteRenderer(); // 디폴트 생성자
	~SpriteRenderer(); // 디폴트 소멸자

	// delete Function
	SpriteRenderer(const SpriteRenderer& _Other) = delete; // 디폴트 복사 생성자
	SpriteRenderer(SpriteRenderer&& _Other) noexcept = delete; 
	SpriteRenderer& operator=(const SpriteRenderer& _Other) = delete; // 디폴트 대입 연산자
	SpriteRenderer& operator=(SpriteRenderer&& _Other) noexcept = delete;

protected:

private:
};

