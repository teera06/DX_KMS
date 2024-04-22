#pragma once

#include <EngineCore/Actor.h>

#include "Boss2Common.h"
class USpriteRenderer;

class AHeadAtt : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AHeadAtt(); // ����Ʈ ������
	~AHeadAtt(); // ����Ʈ �Ҹ���

	// delete Function
	AHeadAtt(const AHeadAtt& _Other) = delete; // ����Ʈ ���� ������
	AHeadAtt(AHeadAtt&& _Other) noexcept = delete; 
	AHeadAtt& operator=(const AHeadAtt& _Other) = delete; // ����Ʈ ���� ������
	AHeadAtt& operator=(AHeadAtt&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* headatt = nullptr;
};

