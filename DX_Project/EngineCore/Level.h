#pragma once
class Level
{
public:
	// constrcuter destructer
	Level(); // ����Ʈ ������
	~Level(); // ����Ʈ �Ҹ���

	// delete Function
	Level(const Level& _Other) = delete; // ����Ʈ ���� ������
	Level(Level&& _Other) noexcept = delete; 
	Level& operator=(const Level& _Other) = delete; // ����Ʈ ���� ������
	Level& operator=(Level&& _Other) noexcept = delete;

protected:

private:
};

