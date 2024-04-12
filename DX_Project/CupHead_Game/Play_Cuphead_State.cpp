#include "PreCompile.h"
#include "Play_Cuphead.h"

#include "ContentsHelper.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineEnums.h>
//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

// �ݸ������� �浹 �ϱ�
void APlay_Cuphead::StateInit()
{
	// ������Ʈ �����
	//State.CreateState("Die");
	State.CreateState("Idle");
	State.CreateState("Run");
	State.CreateState("Dash");
	State.CreateState("Duck");
	State.CreateState("Shoot_Straight");
	State.CreateState("Run_Shoot_Straight");
	State.CreateState("Duck_Shoot");
	State.CreateState("Jump");
	

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

	State.SetUpdateFunction("Duck_Shoot", std::bind(&APlay_Cuphead::Duck_Shoot, this, std::placeholders::_1));
	State.SetStartFunction("Duck_Shoot", [=] {PlayCuphead->ChangeAnimation("Duck_Shoot"); });

	State.SetUpdateFunction("Jump", std::bind(&APlay_Cuphead::Jump, this, std::placeholders::_1));
	State.SetStartFunction("Jump", [=] {PlayCuphead->ChangeAnimation("Jump"); });

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

void APlay_Cuphead::MoveUpDate(float _DeltaTime, FVector _MovePos)
{
	std::shared_ptr<UEngineTexture> Tex = UContentsHelper::MapTex;

#ifdef _DEBUG
	if (nullptr == Tex)
	{
		MsgBoxAssert("�̹��� �浹üũ�� �̹����� �������� �ʽ��ϴ�.");
	}
#endif



	// ���� �� �ȼ� �浹 �ν� ����
	float4 Pos = GetActorLocation();
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // �߷��� ��� ��������.
	//Pos.Y = -Pos.Y;

	switch (Dir)
	{
	case EDir::Left:
		Pos.X -= 30.0f;
		break;
	case EDir::Right:
		Pos.X += 30.0f;
		break;
	default:
		break;
	}

	Color8Bit Color = Tex->GetColor(Pos.iX(), Pos.iY(), Color8Bit::Black);

	if (Color == Color8Bit::Black)
	{
		GravityVector = FVector::Zero; // �߷��� ���� 0����
	}

	AddActorLocation(_MovePos+ GravityVector+(JumpVector* _DeltaTime));

}


void APlay_Cuphead::Idle(float _DeltaTime)
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

	if (true == IsDown('Z'))
	{
		JumpVector = JumpPower;
		State.ChangeState("Jump");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Run(float  _DeltaTime)
{
	DirCheck();

	FVector MovePos = FVector::Zero;
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

	if (true == IsDown('Z'))
	{
		State.ChangeState("Jump");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		MovePos+=FVector::Left * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * Speed;
	}

	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Run_Shoot_Straight(float  _DeltaTime)
{
	DirCheck();

	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT) && true == IsFree('X'))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * Speed;
	}

	if (true == IsFree('X'))
	{
		State.ChangeState("Run");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("Shoot_Straight");
		return;
	}

	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Dash(float _DeltaTime)
{
	DirCheck();
	FVector MovePos = FVector::Zero;
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}

	switch (Dir)
	{
	case EDir::Left:
		MovePos+=FVector::Left * _DeltaTime * DashSpeed;
		break;
	case EDir::Right:
		MovePos += FVector::Right * _DeltaTime * DashSpeed;
		break;
	default:
		break;
	}
	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Duck(float _DeltaTime)
{
	DirCheck();
	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsPress('X'))
	{
		State.ChangeState("Duck_Shoot");
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

	if (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT))
	{
		State.ChangeState("Run_Shoot_Straight");
		return;
	}
}

void APlay_Cuphead::Duck_Shoot(float _DeltaTime)
{
	DirCheck();
	
	if (true == IsFree('X'))
	{
		State.ChangeState("Duck");
		return;
	}
}

void APlay_Cuphead::Jump(float _DeltaTime)
{
	DirCheck();

	std::shared_ptr<UEngineTexture> Tex = UContentsHelper::MapTex;
	Color8Bit Color = Tex->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::Black);

	if (Color == Color8Bit::Black)
	{
		//JumpVector = FVector::Zero;
	}
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	}
}