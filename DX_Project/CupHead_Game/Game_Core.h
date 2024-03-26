#pragma once
#include <EngineCore/EngineCore.h>

class UGame_Core : public UserCore
{
public:
	// constrcuter destructer
	UGame_Core(); // ����Ʈ ������
	~UGame_Core(); // ����Ʈ �Ҹ���

	// delete Function
	UGame_Core(const UGame_Core& _Other) = delete; // ����Ʈ ���� ������
	UGame_Core(UGame_Core&& _Other) noexcept = delete; 
	UGame_Core& operator=(const UGame_Core& _Other) = delete; // ����Ʈ ���� ������
	UGame_Core& operator=(UGame_Core&& _Other) noexcept = delete;

protected:
	void Initialize() override;
private:
};

