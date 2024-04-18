#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/StateManager.h>
#include "PlayerCommon.h"

class USpriteRenderer;
class ABaseBullet;

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

	static FVector GetPlayerPos()
	{
		return PlayerPos;
	}



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
	UCollision* PlayerCollision=nullptr;

	std::shared_ptr<ABaseBullet> NewBullet = nullptr;


	static FVector PlayerPos;

	FVector PlayerMoveY = FVector::Zero;

	FVector GravityVector = FVector::Zero; // �߷°� �ޱ�

	// ������ ����
	FVector JumpPowerDown = FVector::Up * 1200.0f; // �̵��Ҷ��� ������
	FVector JumpPowerPress = FVector::Up * 1350.0f; // �̵��Ҷ��� ������
	FVector JumpVector = FVector::Zero; // ���� ������

	FVector BulletDir = FVector::Right; // ���� ������

	EShootDir ShootStyle = EShootDir::None;

	float Speed = 500.0f;
	float JumpSpeed = 300.0f;

	float DashSpeed = 1000.0f;

	float Gravity = 3000.0f;

	float skillCoolTime=-1.0f;

	float shootXpos = 65.0f;
	float RunShootYpos = 5.0f;
	float DuckShootYpos = 35.0f;

	bool shootY = false;
	bool NoGravity = false;


	void ParryCheck();

	// �Ѿ� ���� �Լ�
	void createBullet();
	void IdleShoot();
	void RunShoot();
	void DuckShoot();
	void DiagonalUpShoot();
	void UpShoot();


	// �̵��Լ�
	
	void CalGravityVector(float _DeltaTime);
	void CalLastMoveVector(float _DeltaTime, const FVector& _MovePos = FVector::Zero);
	//false =Left
	// true = Right
	///////////////////////// State
	void StateInit();
	void Intro(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Run(float _DeltaTime);
	void Run_Shoot_Straight(float _DeltaTime);
	void Run_Shoot_DiagonalUp(float _DeltaTime);
	void Dash(float _DeltaTime);
	void AirDash(float _DeltaTime);
	void Duck(float _DeltaTime);
	void Shoot_Straight(float _DeltaTime);
	void Duck_Shoot(float _DeltaTime);
	void Aim_Up(float _DeltaTime);
	void Shoot_Up(float _DeltaTime);
	void Jump(float _DeltaTime);
	void JumpShoot(float _DeltaTime);
	void DashAfterJump(float _DeltaTime);
	void Parry(float _DeltaTime);
};

