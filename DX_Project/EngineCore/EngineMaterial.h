#pragma once
class EngineMaterial
{
public:
	// constrcuter destructer
	EngineMaterial(); // ����Ʈ ������
	~EngineMaterial(); // ����Ʈ �Ҹ���

	// delete Function
	EngineMaterial(const EngineMaterial& _Other) = delete; // ����Ʈ ���� ������
	EngineMaterial(EngineMaterial&& _Other) noexcept = delete; 
	EngineMaterial& operator=(const EngineMaterial& _Other) = delete; // ����Ʈ ���� ������
	EngineMaterial& operator=(EngineMaterial&& _Other) noexcept = delete;

protected:

private:
};

