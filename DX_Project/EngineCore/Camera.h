#pragma once
class Camera
{
public:
	// constrcuter destructer
	Camera(); // ����Ʈ ������
	~Camera(); // ����Ʈ �Ҹ���

	// delete Function
	Camera(const Camera& _Other) = delete; // ����Ʈ ���� ������
	Camera(Camera&& _Other) noexcept = delete; 
	Camera& operator=(const Camera& _Other) = delete; // ����Ʈ ���� ������
	Camera& operator=(Camera&& _Other) noexcept = delete;

protected:

private:
};

