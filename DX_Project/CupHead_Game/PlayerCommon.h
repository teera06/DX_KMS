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
	// Stage 0 Ÿ��Ʋ
	// Stage 1 �����
	// Stage 2 ���� �� 1
	// Stage 3 ���� �� 2
protected:
private:
};

