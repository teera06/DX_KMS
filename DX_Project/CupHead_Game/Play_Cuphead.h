#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/StateManager.h>
#include "PlayerCommon.h"

class USpriteRenderer;
class ABaseBullet;
class ABaseSSBullet;
class UImage;

class UEngineSoundPlayer;
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

	void SetGrounYCheck(const int& _GrounYCheck)
	{
		GrounYCheck = _GrounYCheck;
	}

	void AddCollisionMove(const FVector& _CollisionMove)
	{
		CollisionMove += _CollisionMove;
	}


	static int GetHp() 
	{
		return Hp;
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
	UEngineSoundPlayer BaseBulletSound;
	UEngineSoundPlayer GrountSound;

	UImage* HpBar = nullptr;

	std::vector<UImage*> Guage;

	USpriteRenderer* PlayCuphead= nullptr;
	USpriteRenderer* BulletStart = nullptr;
	USpriteRenderer* Effect = nullptr;
	UCollision* PlayerCollision=nullptr;
	UCollision* ParryCollision = nullptr;

	std::shared_ptr<ABaseBullet> NewBullet = nullptr;
	std::shared_ptr<ABaseSSBullet> NewSSBullet = nullptr;


	static FVector PlayerPos;

	FVector PlayerMoveY = FVector::Zero;

	FVector GravityVector = FVector::Zero; // �߷°� �ޱ�

	FVector CollisionMove = FVector::Zero;

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

	float SaveSkilltime = 0.15f;

	float shootXpos = 65.0f;
	float RunShootYpos = 5.0f;
	float DuckShootYpos = 35.0f;

	float bulletY1 = 110.0f;
	float bulletY2 = 80.0f;

	float DustTime = 0.45f;

	float ColOnTime = 1.5f;

	float Hp1Time = 0.55f;

	int GrounYCheck = 0;
	static int Hp;

	bool shootY = false;
	bool NoGravity = false;

	bool PowerShoot = false;
	bool IsHitEffect = false;

	bool DevilDieCheck = false;

	bool Devil2GrounCheck = false;

	bool Hp1OnOff = false;

	// false -> �⺻ ����
	// true -> ������ ����

	void ParryCheck(float _DeltaTime);
	void GroundObject();
	void EventCollision(float _DeltaTime);

	// �Ѿ� ���� �Լ�
	void createBullet();
	void IdleShoot();
	void RunShoot();
	void DuckShoot();
	void DiagonalUpShoot();
	void UpShoot();

	void SSIdleShoot();
	void SSDownShoot();
	void SSDiagonalUpShoot();
	void SSDiagonalDownShoot();
	void SSUpShoot();

	void createSSBullet();

	// �̵��Լ�
	
	void CalGravityVector(float _DeltaTime);
	void CalLastMoveVector(float _DeltaTime, const FVector& _MovePos = FVector::Zero);
	void GroupUp(float _DeltaTime);
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
	void hit(float _DeltaTime);
	void Parry(float _DeltaTime);

	// �߰�
	void Aim_Straight(float _DeltaTime);
	void Aim_DiagonalDown(float _DeltaTime);
	void Aim_Down(float _DeltaTime);
	void Aim_DiagonalUp(float _DeltaTime);

	void Shoot_Down(float _DeltaTIme);
	void Shoot_DiagonalUp(float _DeltaTIme);
	void Shoot_DiagonalDown(float _DeltaTIme);





	void SSGround_Straight(float _DeltaTime);
	void SSGround_Down(float _DeltaTime);
	void SSGround_DiagonalUp(float _DeltaTime);
	void SSGround_DiagonalDown(float _DeltaTime);
	void SSGround_Up(float _DeltaTime);

	void Boss2PhaseChange(float _DeltaTime);
	void Scared(float _DeltaTime);
};

