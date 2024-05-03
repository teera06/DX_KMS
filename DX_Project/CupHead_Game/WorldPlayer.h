#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/StateManager.h>
#include "ContentsENum.h"
#include "PlayerCommon.h"

class USpriteRenderer;
class AWorldPlayer : public AActor, public APlayerCommon
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AWorldPlayer(); // 디폴트 생성자
	~AWorldPlayer(); // 디폴트 소멸자

	// delete Function
	AWorldPlayer(const AWorldPlayer& _Other) = delete; // 디폴트 복사 생성자
	AWorldPlayer(AWorldPlayer&& _Other) noexcept = delete; 
	AWorldPlayer& operator=(const AWorldPlayer& _Other) = delete; // 디폴트 대입 연산자
	AWorldPlayer& operator=(AWorldPlayer&& _Other) noexcept = delete;

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
	USpriteRenderer* WorldPlayerRenderer = nullptr;
	USpriteRenderer* AButton = nullptr;
	USpriteRenderer* Boss1title = nullptr;
	USpriteRenderer* Boss2title = nullptr;
	UCollision* PlayerCollision = nullptr;

	static FVector PlayerPos;
	FVector PlayMove = FVector::Zero;

	float Speed = 300.0f;
	
	float DustTime = 0.45f;

	bool Boss1Check = false;
	bool Boss2Check = false;
	
	void BossStartCheck();
	
	///////////////////////// State
	void StateInit();


	void UpIdle(float _DeltaTime);
	void UpWalk(float _DeltaTime);

	void DownIdle(float _DeltaTime);
	void DownWalk(float _DeltaTime);

	void StraightIdle(float _DeltaTime);
	void StraightWalk(float _DeltaTime);

	void DiagonalUpIdle(float _DeltaTime);
	void DiagonalUpWalk(float _DeltaTime);

	void DiagonalDownIdle(float _DeltaTime);
	void DiagonalDownWalk(float _DeltaTime);

	void BossStartBefore(float _DeltaTime);

};

