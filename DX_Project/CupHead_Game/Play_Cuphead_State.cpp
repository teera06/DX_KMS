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
	// ������Ʈ �����
	//State.CreateState("Die");
	State.CreateState("Idle");
	State.CreateState("Run");
	State.CreateState("Dash");
	State.CreateState("Duck");
	State.CreateState("Shoot_Straight");
	

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

	//State.SetUpdateFunction("Duck", std::bind(&APlay_Cuphead::Duck, this, std::placeholders::_1));
	//State.SetStartFunction("Duck", [=] {PlayCuphead->ChangeAnimation("Duck"); });
	//State.SetUpdateFunction("Run", std::bind(&AWorldPlayer::Run, this, std::placeholders::_1));

	//State.SetStartFunction("Run", std::bind(&AWorldPlayer::RunStart, this));


	// �Ｎ �Լ�
	// = [ ����ĸ�� Renderer]
	// {
	//    �Լ� ����
	// }

	// ����ĸó�� ����ȿ� =�� ����
	// ���� ���ÿ��� ��밡���� ���纻�� �����.
	// �޸𸮸� �Ҵ��ؼ� Renderer�� ���� �̸����� �����Ѵ�.


	// ü����
	State.ChangeState("Idle");
}



void APlay_Cuphead::Idle(float _Update)
{


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

	if (true == IsPress(VK_LEFT))
	{
		LRCheck = false;
		PlayCuphead->SetDir(EEngineDir::Left);
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_RIGHT))
	{
		LRCheck = true;
		PlayCuphead->SetDir(EEngineDir::Right);
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}
}

void APlay_Cuphead::Dash(float _DeltaTime)
{
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}

	if (false==LRCheck)
	{
		AddActorLocation(FVector::Left * _DeltaTime * DashSpeed);
	}
	else {
		AddActorLocation(FVector::Right * _DeltaTime * DashSpeed);
	}

}

void APlay_Cuphead::Duck(float _DeltaTime)
{
	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("Idle");
		return;
	}


}

void APlay_Cuphead::Shoot_Straight(float _DeltaTime)
{
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