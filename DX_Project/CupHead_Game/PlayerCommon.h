#pragma once

class UPlayerCommon
{
public:
	// constrcuter destructer
	UPlayerCommon(); // ����Ʈ ������
	~UPlayerCommon(); // ����Ʈ �Ҹ���

	// delete Function
	UPlayerCommon(const UPlayerCommon& _Other) = delete; // ����Ʈ ���� ������
	UPlayerCommon(UPlayerCommon&& _Other) noexcept = delete; 
	UPlayerCommon& operator=(const UPlayerCommon& _Other) = delete; // ����Ʈ ���� ������
	UPlayerCommon& operator=(UPlayerCommon&& _Other) noexcept = delete;

	static int StageCount;
protected:
private:
};

