#pragma once
class EngineVertexBuffer
{
public:
	// constrcuter destructer
	EngineVertexBuffer(); // ����Ʈ ������
	~EngineVertexBuffer(); // ����Ʈ �Ҹ���

	// delete Function
	EngineVertexBuffer(const EngineVertexBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineVertexBuffer(EngineVertexBuffer&& _Other) noexcept = delete; 
	EngineVertexBuffer& operator=(const EngineVertexBuffer& _Other) = delete; // ����Ʈ ���� ������
	EngineVertexBuffer& operator=(EngineVertexBuffer&& _Other) noexcept = delete;

protected:

private:
};

