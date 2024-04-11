#pragma once
#include <Enginecore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/StateManager.h>
#include "ContentsENum.h"
class AWorldPlayer : public AActor
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

	UStateManager State;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* WorldPlayerRenderer = nullptr;

	float Speed = 300.0f;

	EDir Dir = EDir::None;

	void DebugMessageFunction();
	void DirCheck();
	void MoveUpDate(float _DeltaTime,FVector _MovePos);
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

};

