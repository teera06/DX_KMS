#pragma once
#include <EngineCore/Actor.h>

#include "ContentsENum.h"

class URenderer;
class APlay_Cuphead : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	APlay_Cuphead(); // ����Ʈ ������
	~APlay_Cuphead(); // ����Ʈ �Ҹ���

	// delete Function
	APlay_Cuphead(const APlay_Cuphead& _Other) = delete; // ����Ʈ ���� ������
	APlay_Cuphead(APlay_Cuphead&& _Other) noexcept = delete; 
	APlay_Cuphead& operator=(const APlay_Cuphead& _Other) = delete; // ����Ʈ ���� ������
	APlay_Cuphead& operator=(APlay_Cuphead&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	// ���¿� ���� ����, �ִϸ��̼� ������Ʈ
	//void StateAniChange(EActorState _State); // Ŀ���� ������ ���¿� �´� �ִϸ��̼� ����
	
	URenderer* CupHeadRenderer=nullptr;

	float MoveSpeed = 400.0f;


	EPlayerState State = EPlayerState::None;
	void StateUpdate(float _DeltaTime);
	// ���¿� ���� ����
	void Idle(float _DeltaTime); // ���ֱ�
	void Move(float _DeltaTime); // �ȱ�
	//void Jump(float _DeltaTime); // ����
	//void hit(float _DeltaTime); // ���Ϳ��� �浹
	//void HeadDown(float _DeltaTime); // ���̱�
	//void Att1(float _DeltaTime); // ���̱�
	//void Att2(float _DeltaTime); // ���̱�
};

