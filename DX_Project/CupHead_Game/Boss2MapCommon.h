#pragma once
class ABoss2MapCommon
{
public:
	// constrcuter destructer
	ABoss2MapCommon(); // ����Ʈ ������
	~ABoss2MapCommon(); // ����Ʈ �Ҹ���

	// delete Function
	ABoss2MapCommon(const ABoss2MapCommon& _Other) = delete; // ����Ʈ ���� ������
	ABoss2MapCommon(ABoss2MapCommon&& _Other) noexcept = delete; 
	ABoss2MapCommon& operator=(const ABoss2MapCommon& _Other) = delete; // ����Ʈ ���� ������
	ABoss2MapCommon& operator=(ABoss2MapCommon&& _Other) noexcept = delete;


	static bool DelCheck;
protected:

private:
};

