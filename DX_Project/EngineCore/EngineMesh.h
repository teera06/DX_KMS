#pragma once
class EngineMesh
{
public:
	// constrcuter destructer
	EngineMesh(); // ����Ʈ ������
	~EngineMesh(); // ����Ʈ �Ҹ���

	// delete Function
	EngineMesh(const EngineMesh& _Other) = delete; // ����Ʈ ���� ������
	EngineMesh(EngineMesh&& _Other) noexcept = delete; 
	EngineMesh& operator=(const EngineMesh& _Other) = delete; // ����Ʈ ���� ������
	EngineMesh& operator=(EngineMesh&& _Other) noexcept = delete;

protected:

private:
};

