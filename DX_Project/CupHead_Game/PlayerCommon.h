#pragma once

class PlayerCommon
{
public:
	// constrcuter destructer
	PlayerCommon(); // ����Ʈ ������
	~PlayerCommon(); // ����Ʈ �Ҹ���

	// delete Function
	PlayerCommon(const PlayerCommon& _Other) = delete; // ����Ʈ ���� ������
	PlayerCommon(PlayerCommon&& _Other) noexcept = delete; 
	PlayerCommon& operator=(const PlayerCommon& _Other) = delete; // ����Ʈ ���� ������
	PlayerCommon& operator=(PlayerCommon&& _Other) noexcept = delete;

protected:
	static int StageCount;
private:
};

