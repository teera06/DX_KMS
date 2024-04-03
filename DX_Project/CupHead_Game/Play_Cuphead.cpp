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
	case EPlayerState::Dash: // 
		break;
	
	default:
		break;
	}
}
