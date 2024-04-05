#pragma once
#include <EngineCore/Actor.h>

#include "ContentsENum.h"

class URenderer;
class APlay_Cuphead : public AActor
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	// 상태에 따른 조작, 애니메이션 업데이트
	//void StateAniChange(EActorState _State); // 커비의 움직임 상태에 맞는 애니메이션 실행
	
	URenderer* CupHeadRenderer=nullptr;

	float MoveSpeed = 400.0f;


	EPlayerState State = EPlayerState::None;
	void StateUpdate(float _DeltaTime);
	// 상태에 따른 조작
	void Idle(float _DeltaTime); // 서있기
	void Move(float _DeltaTime); // 걷기
	//void Jump(float _DeltaTime); // 점프
	//void hit(float _DeltaTime); // 몬스터와의 충돌
	//void HeadDown(float _DeltaTime); // 숙이기
	//void Att1(float _DeltaTime); // 숙이기
	//void Att2(float _DeltaTime); // 숙이기
};

