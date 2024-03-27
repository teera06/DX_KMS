#pragma once
class UEngineGraphicDevice
{
public:
	// constrcuter destructer
	UEngineGraphicDevice(); // 디폴트 생성자
	~UEngineGraphicDevice(); // 디폴트 소멸자

	// delete Function
	UEngineGraphicDevice(const UEngineGraphicDevice& _Other) = delete; // 디폴트 복사 생성자
	UEngineGraphicDevice(UEngineGraphicDevice&& _Other) noexcept = delete; 
	UEngineGraphicDevice& operator=(const UEngineGraphicDevice& _Other) = delete; // 디폴트 대입 연산자
	UEngineGraphicDevice& operator=(UEngineGraphicDevice&& _Other) noexcept = delete;

protected:

private:
};

