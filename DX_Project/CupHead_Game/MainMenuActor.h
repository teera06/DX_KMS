#pragma once
class MainMenuActor
{
public:
	// constrcuter destructer
	MainMenuActor(); // ����Ʈ ������
	~MainMenuActor(); // ����Ʈ �Ҹ���

	// delete Function
	MainMenuActor(const MainMenuActor& _Other) = delete; // ����Ʈ ���� ������
	MainMenuActor(MainMenuActor&& _Other) noexcept = delete; 
	MainMenuActor& operator=(const MainMenuActor& _Other) = delete; // ����Ʈ ���� ������
	MainMenuActor& operator=(MainMenuActor&& _Other) noexcept = delete;

protected:

private:
};

