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
	

	State.SetUpdateFunction("Idle", std::bind(&APlay_Cuphead::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", [=] {PlayCuphead->ChangeAnimation("Idle"); });

	State.SetUpdateFunction("Run", std::bind(&APlay_Cuphead::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", [=] {PlayCuphead->ChangeAnimation("Run"); });

	State.SetUpdateFunction("Dash", std::bind(&APlay_Cuphead::Dash, this, std::placeholders::_1));
	State.SetStartFunction("Dash", [=] {PlayCuphead->ChangeAnimation("Dash"); });
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
	if (true == IsFree(VK_SHIFT))
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