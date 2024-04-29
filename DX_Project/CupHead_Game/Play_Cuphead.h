#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/StateManager.h>
#include "PlayerCommon.h"

class USpriteRenderer;
class ABaseBullet;
class ABaseSSBullet;


class APlay_Cuphead : public AActor, public APlayerCommon
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	APlay_Cuphead(); // 디폴트 생성자
	~APlay_Cuphead(); // 디폴트 소멸자

	// delete Function
	APlay_Cuphead(const APlay_Cuphead& _Other) = delete; // 디폴트 복사 생성자
	APlay_Cuphead(APlay_Cuphead&& _Other) noexcept = delete; 
	APlay_Cuphead& operator=(const APlay_Cuphead& _Other) = delete; // 디폴트 대입 연산자
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

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DirCheck() override;
	void MoveUpDate(float _DeltaTime,const FVector& _MovePos = FVector::Zero) override;

	void DebugMessageFunction() override;
private:
	// 상태에 따른 조작, 애니메이션 업데이트
	//void StateAniChange(EActorState _State); // 커비의 움직임 상태에 맞는 애니메이션 실행

	USpriteRenderer* PlayCuphead= nullptr;
	USpriteRenderer* BulletStart = nullptr;
	UCollision* PlayerCollision=nullptr;

	std::shared_ptr<ABaseBullet> NewBullet = nullptr;
	std::shared_ptr<ABaseSSBullet> NewSSBullet = nullptr;


	static FVector PlayerPos;

	FVector PlayerMoveY = FVector::Zero;

	FVector GravityVector = FVector::Zero; // 중력값 받기

	FVector CollisionMove = FVector::Zero;

	// 점프력 제어
	FVector JumpPowerDown = FVector::Up * 1200.0f; // 이동할때의 점프력
	FVector JumpPowerPress = FVector::Up * 1350.0f; // 이동할때의 점프력
	FVector JumpVector = FVector::Zero; // 최종 점프력

	FVector BulletDir = FVector::Right; // 최종 점프력

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

	int GrounYCheck = 0;

	bool shootY = false;
	bool NoGravity = false;

	bool PowerShoot = false;


	bool DevilDieCheck = false;
	// false -> 기본 공격
	// true -> 게이지 공격

	void ParryCheck();
	void GroundObject();
	void EventCollision(float _DeltaTime);

	// 총알 관련 함수
	void createBullet();
	void IdleShoot();
	void RunShoot();
	void DuckShoot();
	void DiagonalUpShoot();
	void UpShoot();

	void SSIdleShoot();
	void SSDuckShoot();
	void SSDiagonalUpShoot();
	void SSUpShoot();

	void createSSBullet();

	// 이동함수
	
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

	void SSGround_Straight(float _DeltaTime);
	void SSGround_Down(float _DeltaTime);
	void SSGround_DiagonalUp(float _DeltaTime);
	void SSGround_DiagonalDown(float _DeltaTime);
	void SSGround_Up(float _DeltaTime);

	void Boss2PhaseChange(float _DeltaTime);
	void Scared(float _DeltaTime);
};

