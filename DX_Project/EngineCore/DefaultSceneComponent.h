#pragma once
class DefaultSceneComponent
{
public:
	// constrcuter destructer
	DefaultSceneComponent(); // ����Ʈ ������
	~DefaultSceneComponent(); // ����Ʈ �Ҹ���

	// delete Function
	DefaultSceneComponent(const DefaultSceneComponent& _Other) = delete; // ����Ʈ ���� ������
	DefaultSceneComponent(DefaultSceneComponent&& _Other) noexcept = delete; 
	DefaultSceneComponent& operator=(const DefaultSceneComponent& _Other) = delete; // ����Ʈ ���� ������
	DefaultSceneComponent& operator=(DefaultSceneComponent&& _Other) noexcept = delete;

protected:

private:
};

