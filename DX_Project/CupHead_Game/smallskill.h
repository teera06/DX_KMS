#pragma once
class Asmallskill
{
public:
	// constrcuter destructer
	Asmallskill(); // ����Ʈ ������
	~Asmallskill(); // ����Ʈ �Ҹ���

	// delete Function
	Asmallskill(const Asmallskill& _Other) = delete; // ����Ʈ ���� ������
	Asmallskill(Asmallskill&& _Other) noexcept = delete; 
	Asmallskill& operator=(const Asmallskill& _Other) = delete; // ����Ʈ ���� ������
	Asmallskill& operator=(Asmallskill&& _Other) noexcept = delete;

protected:

private:
};

