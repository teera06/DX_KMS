#pragma once
class EngineRenderTarget
{
public:
	// constrcuter destructer
	EngineRenderTarget(); // ����Ʈ ������
	~EngineRenderTarget(); // ����Ʈ �Ҹ���

	// delete Function
	EngineRenderTarget(const EngineRenderTarget& _Other) = delete; // ����Ʈ ���� ������
	EngineRenderTarget(EngineRenderTarget&& _Other) noexcept = delete; 
	EngineRenderTarget& operator=(const EngineRenderTarget& _Other) = delete; // ����Ʈ ���� ������
	EngineRenderTarget& operator=(EngineRenderTarget&& _Other) noexcept = delete;

protected:

private:
};

