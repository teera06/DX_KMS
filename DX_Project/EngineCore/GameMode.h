#pragma once
class GameMode
{
public:
	// constrcuter destructer
	GameMode(); // ����Ʈ ������
	~GameMode(); // ����Ʈ �Ҹ���

	// delete Function
	GameMode(const GameMode& _Other) = delete; // ����Ʈ ���� ������
	GameMode(GameMode&& _Other) noexcept = delete; 
	GameMode& operator=(const GameMode& _Other) = delete; // ����Ʈ ���� ������
	GameMode& operator=(GameMode&& _Other) noexcept = delete;

protected:

private:
};

