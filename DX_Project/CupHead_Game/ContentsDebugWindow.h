#pragma once
#include <EngineCore/EngineDebugMsgWindow.h>

class UContentsDebugWindow : public UEngineDebugMsgWindow
{
	GENERATED_BODY(UEngineDebugMsgWindow);
public:
	// constrcuter destructer
	UContentsDebugWindow(); // ����Ʈ ������
	~UContentsDebugWindow(); // ����Ʈ �Ҹ���

	// delete Function
	UContentsDebugWindow(const UContentsDebugWindow& _Other) = delete; // ����Ʈ ���� ������
	UContentsDebugWindow(UContentsDebugWindow&& _Other) noexcept = delete; 
	UContentsDebugWindow& operator=(const UContentsDebugWindow& _Other) = delete; // ����Ʈ ���� ������
	UContentsDebugWindow& operator=(UContentsDebugWindow&& _Other) noexcept = delete;

protected:
	void Init() override;
	void OnGui(ULevel* Level, float _Delta) override;
private:
};

