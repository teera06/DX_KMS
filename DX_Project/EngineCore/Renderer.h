#pragma once
class Renderer
{
public:
	// constrcuter destructer
	Renderer(); // ����Ʈ ������
	~Renderer(); // ����Ʈ �Ҹ���

	// delete Function
	Renderer(const Renderer& _Other) = delete; // ����Ʈ ���� ������
	Renderer(Renderer&& _Other) noexcept = delete; 
	Renderer& operator=(const Renderer& _Other) = delete; // ����Ʈ ���� ������
	Renderer& operator=(Renderer&& _Other) noexcept = delete;

protected:

private:
};

