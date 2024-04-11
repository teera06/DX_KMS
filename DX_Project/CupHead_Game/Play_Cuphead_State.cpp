#include "PreCompile.h"
#include "Play_Cuphead.h"

#include "ContentsHelper.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineEnums.h>
//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void APlay_Cuphead::StateInit()
{
	// 스테이트 만들고
	//State.CreateState("Die");
	State.CreateState("Idle");
	State.CreateState("Run");
	State.CreateState("Dash");
	State.CreateState("Duck");
	State.CreateState("Shoot_Straight");
	State.CreateState("Run_Shoot_Straight");
	

	State.SetUpdateFunction("Idle", std::bind(&APlay_Cuphead::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", [=] {PlayCuphead->ChangeAnimation("Idle"); });

	State.SetUpdateFunction("Run", std::bind(&APlay_Cuphead::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", [=] {PlayCuphead->ChangeAnimation("Run"); });

	State.SetUpdateFunction("Dash", std::bind(&APlay_Cuphead::Dash, this, std::placeholders::_1));
	State.SetStartFunction("Dash", [=] {PlayCuphead->ChangeAnimation("Dash"); });

	State.SetUpdateFunction("Duck", std::bind(&APlay_Cuphead::Duck, this, std::placeholders::_1));
	State.SetStartFunction("Duck", [=] {PlayCuphead->ChangeAnimation("Duck"); });

	State.SetUpdateFunction("Shoot_Straight", std::bind(&APlay_Cuphead::Shoot_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_Straight", [=] {PlayCuphead->ChangeAnimation("Shoot_Straight"); });

	State.SetUpdateFunction("Run_Shoot_Straight", std::bind(&APlay_Cuphead::Run_Shoot_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Run_Shoot_Straight", [=] {PlayCuphead->ChangeAnimation("Run_Shoot_Straight"); });

	//State.SetUpdateFunction("Duck", std::bind(&APlay_Cuphead::Duck, this, std::placeholders::_1));
	//State.SetStartFunction("Duck", [=] {PlayCuphead->ChangeAnimation("Duck"); });
	//State.SetUpdateFunction("Run", std::bind(&AWorldPlayer::Run, this, std::placeholders::_1));

	//State.SetStartFunction("Run", std::bind(&AWorldPlayer::RunStart, this));


	// 즉석 함수
	// = [ 람다캡쳐 Renderer]
	// {
	//    함수 내용
	// }

	// 람다캡처의 내용안에 =을 쓰면
	// 현재 스택에서 사용가능한 복사본을 만든다.
	// 메모리를 할당해서 Renderer를 같은 이름으로 복사한다.


	// 체인지
	State.ChangeState("Idle");
}

void APlay_Cuphead::DirCheck()
{

	if (UEngineInput::IsPress(VK_LEFT))
	{
		PlayCuphead->SetDir(EEngineDir::Left);
		Dir = EDir::Left;
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		PlayCuphead->SetDir(EEngineDir::Right);
		Dir = EDir::Right;
	}
}


void APlay_Cuphead::Idle(float _Update)
{

	DirCheck();
	if (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT))
	{
		State.ChangeState("Run");
		return;
	}
	
	if (true == IsDown(VK_SHIFT))
	{
		State.ChangeState("Dash");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		State.ChangeState("Duck");
		return;
	}

	if (true == IsPress('X'))
	{
		State.ChangeState("Shoot_Straight");
		return;
	}
}

void APlay_Cuphead::Run(float  _DeltaTime)
{
	DirCheck();
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsDown(VK_SHIFT))
	{
		State.ChangeState("Dash");
		return;
	}

	if (true == IsPress('X'))
	{
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_RIGHT))
	{
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}
}

void APlay_Cuphead::Run_Shoot_Straight(float  _DeltaTime)
{
	DirCheck();

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT) && true == IsFree('X'))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("Shoot_Straight");
		return;
	}

	if (true == IsFree('X'))
	{
		State.ChangeState("Run");
		return;
	}
}

void APlay_Cuphead::Dash(float _DeltaTime)
{
	DirCheck();
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}

	switch (Dir)
	{
	case EDir::Left:
		AddActorLocation(FVector::Left * _DeltaTime * DashSpeed);
		break;
	case EDir::Right:
		AddActorLocation(FVector::Right * _DeltaTime * DashSpeed);
		break;
	default:
		break;
	}
}

void APlay_Cuphead::Duck(float _DeltaTime)
{
	DirCheck();
	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("Idle");
		return;
	}
}

void APlay_Cuphead::Shoot_Straight(float _DeltaTime)
{
	DirCheck();
	if (true == IsFree('X'))
	{
		State.ChangeState("Idle");
		return;
	}

	//if (true == IsFree('X'))
	//{
		//State.ChangeState("Idle");
		//return;
	//}
}