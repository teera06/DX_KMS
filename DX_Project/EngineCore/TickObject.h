#pragma once
class TickObject
{
public:
	// constrcuter destructer
	TickObject(); // ����Ʈ ������
	~TickObject(); // ����Ʈ �Ҹ���

	// delete Function
	TickObject(const TickObject& _Other) = delete; // ����Ʈ ���� ������
	TickObject(TickObject&& _Other) noexcept = delete; 
	TickObject& operator=(const TickObject& _Other) = delete; // ����Ʈ ���� ������
	TickObject& operator=(TickObject&& _Other) noexcept = delete;

protected:

private:
};

