#pragma once
class ActorComponent
{
public:
	// constrcuter destructer
	ActorComponent(); // ����Ʈ ������
	~ActorComponent(); // ����Ʈ �Ҹ���

	// delete Function
	ActorComponent(const ActorComponent& _Other) = delete; // ����Ʈ ���� ������
	ActorComponent(ActorComponent&& _Other) noexcept = delete; 
	ActorComponent& operator=(const ActorComponent& _Other) = delete; // ����Ʈ ���� ������
	ActorComponent& operator=(ActorComponent&& _Other) noexcept = delete;

protected:

private:
};

