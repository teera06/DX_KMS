#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/StateManager.h>
#include "PlayerCommon.h"
class APlay_Cuphead : public AActor, public UPlayerCommon
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

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DirCheck() override;
private:
	// 상태에 따른 조작, 애니메이션 업데이트
	//void StateAniChange(EActorState _State); // 커비의 움직임 상태에 맞는 애니메이션 실행
	
	USpriteRenderer* PlayCuphead= nullptr;

	float Speed = 500.0f;
	float DashSpeed = 1000.0f;
	bool LRCheck = false;

	//false =Left
	// true = Right
	///////////////////////// State
	void StateInit();
	void Idle(float _DeltaTime);
	void Run(float _DeltaTime);
	void Run_Shoot_Straight(float _DeltaTime);
	void Dash(float _DeltaTime);
	void Duck(float _DeltaTime);
	void Shoot_Straight(float _DeltaTime);
	void Duck_Shoot(float _DeltaTime);
	//void Shoot_Straight(float _DeltaTime);
};

