#pragma once
class SpriteRenderer
{
public:
	// constrcuter destructer
	SpriteRenderer(); // ����Ʈ ������
	~SpriteRenderer(); // ����Ʈ �Ҹ���

	// delete Function
	SpriteRenderer(const SpriteRenderer& _Other) = delete; // ����Ʈ ���� ������
	SpriteRenderer(SpriteRenderer&& _Other) noexcept = delete; 
	SpriteRenderer& operator=(const SpriteRenderer& _Other) = delete; // ����Ʈ ���� ������
	SpriteRenderer& operator=(SpriteRenderer&& _Other) noexcept = delete;

protected:

private:
};

