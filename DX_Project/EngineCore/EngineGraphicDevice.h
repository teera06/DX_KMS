#pragma once
class UEngineGraphicDevice
{
public:
	// constrcuter destructer
	UEngineGraphicDevice(); // ����Ʈ ������
	~UEngineGraphicDevice(); // ����Ʈ �Ҹ���

	// delete Function
	UEngineGraphicDevice(const UEngineGraphicDevice& _Other) = delete; // ����Ʈ ���� ������
	UEngineGraphicDevice(UEngineGraphicDevice&& _Other) noexcept = delete; 
	UEngineGraphicDevice& operator=(const UEngineGraphicDevice& _Other) = delete; // ����Ʈ ���� ������
	UEngineGraphicDevice& operator=(UEngineGraphicDevice&& _Other) noexcept = delete;

protected:

private:
};

