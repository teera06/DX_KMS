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
	State.CreateState("Idle");
	//State.CreateState("Jump");
	//State.CreateState("Run");

	// �Լ��� �����ϰ�
	State.SetUpdateFunction("Idle", std::bind(&AWorldPlayer::Idle, this, std::placeholders::_1));

	// �Ｎ �Լ�
	// = [ ����ĸ�� Renderer]
	// {
	//    �Լ� ����
	// }

	// ����ĸó�� ����ȿ� =�� ����
	// ���� ���ÿ��� ��밡���� ���纻�� �����.
	// �޸𸮸� �Ҵ��ؼ� Renderer�� ���� �̸����� �����Ѵ�.


	State.SetStartFunction("Idle", [=] {WorldPlayerRenderer->ChangeAnimation("Idle"); });


	//State.SetUpdateFunction("Run", std::bind(&AWorldPlayer::Run, this, std::placeholders::_1));

	//State.SetStartFunction("Run", std::bind(&AWorldPlayer::RunStart, this));





	// ü����
	State.ChangeState("Idle");
}


void AWorldPlayer::Die(float _Update)
{

}

void AWorldPlayer::Idle(float _Update)
{
	if (true == IsPress('A') || true == IsPress('D') || true == IsPress('W') || true == IsPress('S'))
	{
		//State.ChangeState("Run");
		return;
	}
}

void AWorldPlayer::Jump(float _Update)
{

}



void AWorldPlayer::Run(float _DeltaTime)
{

	float Speed = 500.0f;

	if (true == IsPress('A'))
	{
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == IsPress('D'))
	{
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}

	if (true == IsPress('W'))
	{
		AddActorLocation(FVector::Up * _DeltaTime * Speed);
	}

	if (true == IsPress('S'))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_NUMPAD1))
	{
		// AddActorRotation(float4{0.0f, 0.0f, 1.0f} * 360.0f * _DeltaTime);
		// Color.X += _DeltaTime;
	}

	

	//std::shared_ptr<UEngineTexture> Tex = UContentsConstValue::MapTex;

#ifdef _DEBUG
	//if (nullptr == Tex)
	//{
		//MsgBoxAssert("�̹��� �浹üũ�� �̹����� �������� �ʽ��ϴ�.");
	//}
#endif

	//float4 Pos = GetActorLocation();


	//Pos /= UContentsConstValue::TileSize;
	//Pos.Y = -Pos.Y;

	//Color8Bit Color = Tex->GetColor(Pos, Color8Bit::Black);

	//if (Color != Color8Bit::Black)
	//{
		//AddActorLocation(float4::Down * _DeltaTime * 100.0f);
	//}


}
