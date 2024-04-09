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
	//State.CreateState("Run");

	// �Լ��� �����ϰ�
	State.SetUpdateFunction("UpIdle", std::bind(&AWorldPlayer::UpIdle, this, std::placeholders::_1));

	// �Ｎ �Լ�
	// = [ ����ĸ�� Renderer]
	// {
	//    �Լ� ����
	// }

	// ����ĸó�� ����ȿ� =�� ����
	// ���� ���ÿ��� ��밡���� ���纻�� �����.
	// �޸𸮸� �Ҵ��ؼ� Renderer�� ���� �̸����� �����Ѵ�.


	State.SetStartFunction("UpIdle", [=] {WorldPlayerRenderer->ChangeAnimation("UpIdle"); });


	State.SetUpdateFunction("UpWalk", std::bind(&AWorldPlayer::UpWalk, this, std::placeholders::_1));
	State.SetStartFunction("UpWalk", [=] {WorldPlayerRenderer->ChangeAnimation("UpWalk"); });
	//State.SetUpdateFunction("Run", std::bind(&AWorldPlayer::Run, this, std::placeholders::_1));

	//State.SetStartFunction("Run", std::bind(&AWorldPlayer::RunStart, this));





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
}

void AWorldPlayer::UpWalk(float _DeltaTime)
{
	if (true == IsPress(VK_UP))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
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
