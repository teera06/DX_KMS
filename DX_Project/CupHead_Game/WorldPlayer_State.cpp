#include "PreCompile.h"
#include "WorldPlayer.h"
#include <EngineCore/SpriteRenderer.h>

//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void AWorldPlayer::StateInit()
{
	// ������Ʈ �����
	//State.CreateState("Die");
	State.CreateState("UpIdle");
	State.CreateState("UpWalk");

	State.CreateState("DownIdle");
	State.CreateState("DownWalk");

	State.CreateState("StraightIdle");
	State.CreateState("StraightWalk");
	//State.CreateState("Run");

	// �Լ��� �����ϰ�
	State.SetUpdateFunction("UpIdle", std::bind(&AWorldPlayer::UpIdle, this, std::placeholders::_1));
	State.SetStartFunction("UpIdle", [=] {WorldPlayerRenderer->ChangeAnimation("UpIdle"); });

	State.SetUpdateFunction("UpWalk", std::bind(&AWorldPlayer::UpWalk, this, std::placeholders::_1));
	State.SetStartFunction("UpWalk", [=] {WorldPlayerRenderer->ChangeAnimation("UpWalk"); });

	State.SetUpdateFunction("DownIdle", std::bind(&AWorldPlayer::DownIdle, this, std::placeholders::_1));
	State.SetStartFunction("DownIdle", [=] {WorldPlayerRenderer->ChangeAnimation("DownIdle"); });

	State.SetUpdateFunction("DownWalk", std::bind(&AWorldPlayer::DownWalk, this, std::placeholders::_1));
	State.SetStartFunction("DownWalk", [=] {WorldPlayerRenderer->ChangeAnimation("DownWalk"); });

	State.SetUpdateFunction("StraightIdle", std::bind(&AWorldPlayer::StraightIdle, this, std::placeholders::_1));
	State.SetStartFunction("StraightIdle", [=] {WorldPlayerRenderer->ChangeAnimation("StraightIdle"); });

	State.SetUpdateFunction("StraightWalk", std::bind(&AWorldPlayer::StraightWalk, this, std::placeholders::_1));
	State.SetStartFunction("StraightWalk", [=] {WorldPlayerRenderer->ChangeAnimation("StraightWalk"); });
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
	State.ChangeState("UpIdle");
}



void AWorldPlayer::UpIdle(float _Update)
{
	if (true == IsPress(VK_UP))
	{
		State.ChangeState("UpWalk");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		State.ChangeState("DownWalk");
		return;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_RIGHT))
	{
		State.ChangeState("StraightWalk");
		return;
	}
}

void AWorldPlayer::UpWalk(float _DeltaTime)
{

	if (true == IsFree(VK_UP))
	{
		State.ChangeState("UpIdle");
		return;
	}

	if (true == IsPress(VK_UP))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}
}

void AWorldPlayer::DownIdle(float _Update)
{
	if (true == IsPress(VK_DOWN))
	{
		State.ChangeState("DownWalk");
		return;
	}

	if (true == IsPress(VK_UP))
	{
		State.ChangeState("UpWalk");
		return;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_RIGHT))
	{
		State.ChangeState("StraightWalk");
		return;
	}
}

void AWorldPlayer::DownWalk(float _DeltaTime)
{

	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("DownIdle");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}
}

void AWorldPlayer::StraightIdle(float _Update)
{
	if (true == IsPress(VK_DOWN))
	{
		State.ChangeState("DownWalk");
		return;
	}

	if (true == IsPress(VK_UP))
	{
		State.ChangeState("UpWalk");
		return;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_RIGHT))
	{
		State.ChangeState("StraightWalk");
		return;
	}
}

void AWorldPlayer::StraightWalk(float _DeltaTime)
{

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("StraightIdle");
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


//void AWorldPlayer::Run(float _DeltaTime)
//{

	

	

	//std::shared_ptr<UEngineTexture> Tex = UContentsConstValue::MapTex;

//#ifdef _DEBUG
	//if (nullptr == Tex)
	//{
		//MsgBoxAssert("�̹��� �浹üũ�� �̹����� �������� �ʽ��ϴ�.");
	//}
//#endif

	//float4 Pos = GetActorLocation();


	//Pos /= UContentsConstValue::TileSize;
	//Pos.Y = -Pos.Y;

	//Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

	//if (Color != Color8Bit::Black)
	//{
		//AddActorLocation(float4::Down * _DeltaTime * 100.0f);
	//}


//}
