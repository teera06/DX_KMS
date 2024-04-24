#pragma once

#include <EngineCore/Actor.h>

class USpriteRenderer;

class AFatDemonSkill
	: public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AFatDemonSkill(); // ����Ʈ ������
	~AFatDemonSkill(); // ����Ʈ �Ҹ���

	// delete Function
	AFatDemonSkill(const AFatDemonSkill& _Other) = delete; // ����Ʈ ���� ������
	AFatDemonSkill(AFatDemonSkill&& _Other) noexcept = delete; 
	AFatDemonSkill& operator=(const AFatDemonSkill& _Other) = delete; // ����Ʈ ���� ������
	AFatDemonSkill& operator=(AFatDemonSkill&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	
private:
	USpriteRenderer* Skill = nullptr;
};

