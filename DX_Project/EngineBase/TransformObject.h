#pragma once
class TransformObject
{
public:
	// constrcuter destructer
	TransformObject(); // ����Ʈ ������
	~TransformObject(); // ����Ʈ �Ҹ���

	// delete Function
	TransformObject(const TransformObject& _Other) = delete; // ����Ʈ ���� ������
	TransformObject(TransformObject&& _Other) noexcept = delete; 
	TransformObject& operator=(const TransformObject& _Other) = delete; // ����Ʈ ���� ������
	TransformObject& operator=(TransformObject&& _Other) noexcept = delete;

protected:

private:
};

