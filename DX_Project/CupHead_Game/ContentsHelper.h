#pragma once

class UContentsHelper
{
public:
	// constrcuter destructer
	UContentsHelper(); // ����Ʈ ������
	~UContentsHelper(); // ����Ʈ �Ҹ���

	// delete Function
	UContentsHelper(const UContentsHelper& _Other) = delete; // ����Ʈ ���� ������
	UContentsHelper(UContentsHelper&& _Other) noexcept = delete; 
	UContentsHelper& operator=(const UContentsHelper& _Other) = delete; // ����Ʈ ���� ������
	UContentsHelper& operator=(UContentsHelper&& _Other) noexcept = delete;

	static int StageCount;
	// Stage 0 Ÿ��Ʋ
	// Stage 1 �����
	// Stage 2 ���� �� 1
	// Stage 3 ���� �� 2
protected:
private:
};

