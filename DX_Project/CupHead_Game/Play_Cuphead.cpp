#include "PreCompile.h"
#include "Play_Cuphead.h"

#include <EngineCore/Renderer.h>


APlay_Cuphead::APlay_Cuphead()
{
}

APlay_Cuphead::~APlay_Cuphead()
{
}

void APlay_Cuphead::BeginPlay()
{
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
}

void APlay_Cuphead::StateUpdate(float _DeltaTime)
{
	switch (State) // 현재 상태별 진행해야하는 형태
	{
	case EPlayerState::Idle: // 서있기
		//Idle(_DeltaTime);
		break;
	case EPlayerState::Move: // 이동
		//Walk(_DeltaTime);
		break;
	case EPlayerState::Jump: // 점프
		//Run(_DeltaTime);
		break;
	case EPlayerState::Dash: // shift 이동
		break;
	case EPlayerState::IdleAtt: // 서 있기 공격
		break;
	case EPlayerState::MoveAtt: // 이동 하며 공격
		break;
	case EPlayerState::JumpAtt: // 점프 공격
		break;
	
	default:
		break;
	}
}

void APlay_Cuphead::Idle(float _DeltaTime)
{
	
	// 이동
	if (
		true == UEngineInput::IsPress(VK_LEFT) ||
		true == UEngineInput::IsPress(VK_RIGHT)
		)
	{
		//StateAniChange(EPlayerState::Move);
		return;
	}

	


}

