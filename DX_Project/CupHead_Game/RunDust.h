#pragma once

class RunDust
{
public:
	// constrcuter destructer
	RunDust(); // ����Ʈ ������
	~RunDust(); // ����Ʈ �Ҹ���

	// delete Function
	RunDust(const RunDust& _Other) = delete; // ����Ʈ ���� ������
	RunDust(RunDust&& _Other) noexcept = delete; 
	RunDust& operator=(const RunDust& _Other) = delete; // ����Ʈ ���� ������
	RunDust& operator=(RunDust&& _Other) noexcept = delete;

protected:

private:
};

