#pragma once
class SceneComponent
{
public:
	// constrcuter destructer
	SceneComponent(); // ����Ʈ ������
	~SceneComponent(); // ����Ʈ �Ҹ���

	// delete Function
	SceneComponent(const SceneComponent& _Other) = delete; // ����Ʈ ���� ������
	SceneComponent(SceneComponent&& _Other) noexcept = delete; 
	SceneComponent& operator=(const SceneComponent& _Other) = delete; // ����Ʈ ���� ������
	SceneComponent& operator=(SceneComponent&& _Other) noexcept = delete;

protected:

private:
};

