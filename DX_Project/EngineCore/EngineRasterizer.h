#pragma once
class EngineRasterizer
{
public:
	// constrcuter destructer
	EngineRasterizer(); // ����Ʈ ������
	~EngineRasterizer(); // ����Ʈ �Ҹ���

	// delete Function
	EngineRasterizer(const EngineRasterizer& _Other) = delete; // ����Ʈ ���� ������
	EngineRasterizer(EngineRasterizer&& _Other) noexcept = delete; 
	EngineRasterizer& operator=(const EngineRasterizer& _Other) = delete; // ����Ʈ ���� ������
	EngineRasterizer& operator=(EngineRasterizer&& _Other) noexcept = delete;

protected:

private:
};

