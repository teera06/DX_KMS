#pragma once
class WorldObject
{
public:
	// constrcuter destructer
	WorldObject(); // ����Ʈ ������
	~WorldObject(); // ����Ʈ �Ҹ���

	// delete Function
	WorldObject(const WorldObject& _Other) = delete; // ����Ʈ ���� ������
	WorldObject(WorldObject&& _Other) noexcept = delete; 
	WorldObject& operator=(const WorldObject& _Other) = delete; // ����Ʈ ���� ������
	WorldObject& operator=(WorldObject&& _Other) noexcept = delete;

protected:

private:
};

