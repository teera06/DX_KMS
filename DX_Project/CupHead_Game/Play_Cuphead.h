#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/StateManager.h>
#include "PlayerCommon.h"

class USpriteRenderer;

class APlay_Cuphead : public AActor, public APlayerCommon
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

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DirCheck() override;
	void MoveUpDate(float _DeltaTime,const FVector& _MovePos = FVector::Zero) override;

	void DebugMessageFunction() override;
private:
	// ���¿� ���� ����, �ִϸ��̼� ������Ʈ
	//void StateAniChange(EActorState _State); // Ŀ���� ������ ���¿� �´� �ִϸ��̼� ����
	
	USpriteRenderer* PlayCuphead= nullptr;
	USpriteRenderer* BulletStart = nullptr;
	UCollision* Collision=nullptr;

	FVector PlayerMoveY = FVector::Zero;

	FVector GravityVector = FVector::Zero; // �߷°� �ޱ�

	// ������ ����
	FVector JumpPowerDown = FVector::Up * 1200.0f; // �̵��Ҷ��� ������
	FVector JumpPowerPress = FVector::Up * 1350.0f; // �̵��Ҷ��� ������
	FVector JumpVector = FVector::Zero; // ���� ������

	FVector BulletDir = FVector::Right; // ���� ������

	float Speed = 500.0f;
	float JumpSpeed = 300.0f;

	float DashSpeed = 1000.0f;

	float Gravity = 3000.0f;

	float skillCoolTime=-1.0f;

	int ShootPos = 0;

	bool NoGravity = false;

	void createBullet();

	// �̵��Լ�
	
	void CalGravityVector(float _DeltaTime);
	void CalLastMoveVector(float _DeltaTime, const FVector& _MovePos = FVector::Zero);
	//false =Left
	// true = Right
	///////////////////////// State
	void StateInit();
	void Idle(float _DeltaTime);
	void Run(float _DeltaTime);
	void Run_Shoot_Straight(float _DeltaTime);
	void Dash(float _DeltaTime);
	void AirDash(float _DeltaTime);
	void Duck(float _DeltaTime);
	void Shoot_Straight(float _DeltaTime);
	void Duck_Shoot(float _DeltaTime);
	void Jump(float _DeltaTime);
	void DashAfterJump(float _DeltaTime);
	//void Shoot_Straight(float _DeltaTime);
};

