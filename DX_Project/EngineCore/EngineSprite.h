#pragma once
class EngineSprite
{
public:
	// constrcuter destructer
	EngineSprite(); // ����Ʈ ������
	~EngineSprite(); // ����Ʈ �Ҹ���

	// delete Function
	EngineSprite(const EngineSprite& _Other) = delete; // ����Ʈ ���� ������
	EngineSprite(EngineSprite&& _Other) noexcept = delete; 
	EngineSprite& operator=(const EngineSprite& _Other) = delete; // ����Ʈ ���� ������
	EngineSprite& operator=(EngineSprite&& _Other) noexcept = delete;

protected:

private:
};

