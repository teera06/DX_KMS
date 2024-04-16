#include "PreCompile.h"
#include "Play_Cuphead.h"

#include "ContentsHelper.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/EngineEnums.h>
#include <EngineCore/Camera.h>

#include "Boss1Common.h"
#include "BaseBullet.h"

//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void APlay_Cuphead::createBullet()
{


	if (BulletDir.iX() == 0)
	{
		return;
	}

	NewBullet = GetWorld()->SpawnActor<ABaseBullet>("BaseBullet");

	if (NewBullet == nullptr)
	{
		return;
	}

	switch (ShootStyle)
	{
	case EShootDir::None:
		break;
	case EShootDir::IdleShoot:
		IdleShoot();
		break;
	case EShootDir::RunShoot:
		RunShoot();
		break;
	case EShootDir::UpShoot:
		break;
	case EShootDir::DownShoot:
		break;
	case EShootDir::DuckShoot:
		DuckShoot();
		break;
	case EShootDir::DiagonalUpShoot:
		DiagonalUpShoot();
		break;
	default:
		break;
	}
	
	NewBullet->SetBulletDir(BulletDir);
}

void APlay_Cuphead::IdleShoot()
{

	if (BulletDir.iX() == 1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + 90.0f,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + 90.0f,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::RunShoot()
{
	if (BulletDir.iX() == 1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y-RunShootYpos + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y - RunShootYpos + 90.0f,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - RunShootYpos + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - RunShootYpos + 90.0f,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::DuckShoot()
{
	if (BulletDir.iX() == 1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y - DuckShootYpos + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y - DuckShootYpos + 90.0f,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - DuckShootYpos + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - DuckShootYpos + 90.0f,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::DiagonalUpShoot()
{
	if (BulletDir.iX() == 1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,45.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y  + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y  + 90.0f,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,-45.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + 80.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + 90.0f,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::CalGravityVector(float _DeltaTime)
{
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // �߷��� ��� ��������.

	if (GetActorLocation().iY() <= -250 || true==NoGravity)
	{
		GravityVector = FVector::Zero;
	}
}

void APlay_Cuphead::CalLastMoveVector(float _DeltaTime, const FVector& _MovePos)
{
	PlayerMoveY = FVector::Zero;

	PlayerMoveY += JumpVector;
	PlayerMoveY += GravityVector;

	FVector CheckPos = GetActorLocation(); // Kirby

	
	FVector MovePos = _MovePos;
	

	switch (Dir)
	{
	case EDir::Left:
		CheckPos.X -= 30.0f;
		break;
	case EDir::Right:
		CheckPos.X += 30.0f;
		
		break;
	default:
		break;
	}

	if (CheckPos.iX()<=-600 || CheckPos.iX()>=600) // ��(Red)�� �浹�� ��� -> �����̴� �� 0
	{
		MovePos = FVector::Zero;
	}



	AddActorLocation(MovePos + (PlayerMoveY * _DeltaTime));
	GetWorld()->GetMainCamera()->AddActorLocation(MovePos* _DeltaTime*10.0f);
}

// �ݸ������� �浹 �ϱ�
void APlay_Cuphead::StateInit()
{
	// ������Ʈ �����
	//State.CreateState("Die");
	State.CreateState("Intro");
	State.CreateState("Idle");
	State.CreateState("Run");
	State.CreateState("Dash");
	State.CreateState("AirDash");
	State.CreateState("Duck");
	State.CreateState("Shoot_Straight");
	State.CreateState("Run_Shoot_Straight");
	State.CreateState("Run_Shoot_DiagonalUp");
	State.CreateState("Duck_Shoot");
	State.CreateState("Jump");
	State.CreateState("JumpShoot");
	State.CreateState("DashAfterJump");
	
	State.SetUpdateFunction("Intro", std::bind(&APlay_Cuphead::Intro, this, std::placeholders::_1));
	State.SetStartFunction("Intro", [=] {PlayCuphead->ChangeAnimation("Intro"); });

	State.SetUpdateFunction("Idle", std::bind(&APlay_Cuphead::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", [=] {PlayCuphead->ChangeAnimation("Idle"); });

	State.SetUpdateFunction("Run", std::bind(&APlay_Cuphead::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", [=] {PlayCuphead->ChangeAnimation("Run"); });

	State.SetUpdateFunction("Dash", std::bind(&APlay_Cuphead::Dash, this, std::placeholders::_1));
	State.SetStartFunction("Dash", [=] {PlayCuphead->ChangeAnimation("Dash"); });

	State.SetUpdateFunction("AirDash", std::bind(&APlay_Cuphead::AirDash, this, std::placeholders::_1));
	State.SetStartFunction("AirDash", [=] {PlayCuphead->ChangeAnimation("Dash"); });

	State.SetUpdateFunction("Duck", std::bind(&APlay_Cuphead::Duck, this, std::placeholders::_1));
	State.SetStartFunction("Duck", [=] {PlayCuphead->ChangeAnimation("Duck"); });

	State.SetUpdateFunction("Shoot_Straight", std::bind(&APlay_Cuphead::Shoot_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_Straight", [=] {PlayCuphead->ChangeAnimation("Shoot_Straight"); });

	State.SetUpdateFunction("Run_Shoot_Straight", std::bind(&APlay_Cuphead::Run_Shoot_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Run_Shoot_Straight", [=] {PlayCuphead->ChangeAnimation("Run_Shoot_Straight"); });

	State.SetUpdateFunction("Run_Shoot_DiagonalUp", std::bind(&APlay_Cuphead::Run_Shoot_DiagonalUp, this, std::placeholders::_1));
	State.SetStartFunction("Run_Shoot_DiagonalUp", [=] {PlayCuphead->ChangeAnimation("Run_Shoot_DiagonalUp"); });

	State.SetUpdateFunction("Duck_Shoot", std::bind(&APlay_Cuphead::Duck_Shoot, this, std::placeholders::_1));
	State.SetStartFunction("Duck_Shoot", [=] {PlayCuphead->ChangeAnimation("Duck_Shoot"); });

	State.SetUpdateFunction("Jump", std::bind(&APlay_Cuphead::Jump, this, std::placeholders::_1));
	State.SetStartFunction("Jump", [=] {PlayCuphead->ChangeAnimation("Jump"); });

	State.SetUpdateFunction("JumpShoot", std::bind(&APlay_Cuphead::JumpShoot, this, std::placeholders::_1));
	State.SetStartFunction("JumpShoot", [=] {PlayCuphead->ChangeAnimation("Jump"); });

	State.SetUpdateFunction("DashAfterJump", std::bind(&APlay_Cuphead::DashAfterJump, this, std::placeholders::_1));
	State.SetStartFunction("DashAfterJump", [=] {PlayCuphead->ChangeAnimation("Jump"); });

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
	State.ChangeState("Intro");
}

void APlay_Cuphead::Intro(float _DeltaTime)
{
	DirCheck();
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::DirCheck()
{

	if (true==IsPress(VK_LEFT))
	{
		PlayCuphead->SetDir(EEngineDir::Left);
		Dir = EDir::Left;
	}
	if (true==IsPress(VK_RIGHT))
	{
		PlayCuphead->SetDir(EEngineDir::Right);
		Dir = EDir::Right;
	}

	if (true == BulletStart->IsActive())
	{
		switch (Dir)
		{
		case EDir::Left:

			BulletDir = FVector::Left;

			switch (ShootStyle)
			{
			case EShootDir::None:
				break;
			case EShootDir::IdleShoot:
				BulletStart->SetPosition({ -70.0f,80.0f,0.0f });
				break;
			case EShootDir::RunShoot:
				BulletStart->SetPosition({ -65.0f,70.0f,0.0f });
				break;
			case EShootDir::UpShoot:
				break;
			case EShootDir::DownShoot:
				break;
			case EShootDir::DuckShoot:
				BulletStart->SetPosition({ -75.0f,40.0f,0.0f });
				break;
			case EShootDir::DiagonalUpShoot:
				BulletDir += FVector::Up;
				BulletStart->SetPosition({ -60.0f,120.0f,0.0f });
				break;
			default:
				break;
			}
			break;
		case EDir::Right:
			BulletDir = FVector::Right;
			switch (ShootStyle)
			{
			case EShootDir::None:
				break;
			case EShootDir::IdleShoot:
				BulletStart->SetPosition({ 70.0f,80.0f,0.0f });
				break;
			case EShootDir::RunShoot:
				BulletStart->SetPosition({ 65.0f,70.0f,0.0f });
				break;
			case EShootDir::UpShoot:
				break;
			case EShootDir::DownShoot:
				break;
			case EShootDir::DuckShoot:
				BulletStart->SetPosition({70.0f,40.0f,0.0f });
				break;
			case EShootDir::DiagonalUpShoot:
				BulletDir += FVector::Up;
				BulletStart->SetPosition({ 60.0f,120.0f,0.0f });
				break;
			default:
				break;
			}
			break;
		case EDir::Up:
			break;
		case EDir::Down:
			break;
		default:
			break;
		}
	}

}

void APlay_Cuphead::MoveUpDate(float _DeltaTime,const FVector& _MovePos)
{
	//std::shared_ptr<UEngineTexture> Tex = UContentsHelper::MapTex;

//#ifdef _DEBUG
	//if (nullptr == Tex)
	//{
		//MsgBoxAssert("�̹��� �浹üũ�� �̹����� �������� �ʽ��ϴ�.");
	//}
//#endif
	CalGravityVector(_DeltaTime);
	CalLastMoveVector(_DeltaTime, _MovePos);

	// ���� �� �ȼ� �浹 �ν� ����
	//float4 Pos = GetActorLocation();
	//Pos.Y = -Pos.Y;


	//Color8Bit Color = Tex->GetColor(Pos.iX(), Pos.iY(), Color8Bit::Black);

	//if (Color == Color8Bit::Black)
	//{
		//GravityVector = FVector::Zero; // �߷��� ���� 0����
	//}

	//AddActorLocation(PlayerMove + GravityVector+(JumpVector* _DeltaTime));

}

void APlay_Cuphead::DebugMessageFunction()
{
	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
}


void APlay_Cuphead::Idle(float _DeltaTime)
{

	DirCheck();

	if (true == IsDown('1'))
	{
		ABoss1Common::SetHp(80);
		return;
	}

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


	if (true == IsDown('Z') && true == IsPress('X'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsDown('X'))
	{
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_Straight");
		return;
	}

	if (true == IsDown('Z'))
	{

		JumpVector = JumpPowerPress;
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


	if (true == IsDown('Z') && true == IsPress('X'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::RunShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsDown('Z'))
	{

		JumpVector = JumpPowerPress;
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

	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		createBullet();
		skillCoolTime = 0.3f;
		return;
	}

	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT) && true == IsFree('X'))
	{
		BulletStart->SetActive(false);
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

	if (true == IsPress(VK_UP))
	{
		ShootStyle = EShootDir::DiagonalUpShoot;
		State.ChangeState("Run_Shoot_DiagonalUp");
		return;
	}

	if (true == IsFree('X'))
	{
		BulletStart->SetActive(false);
		State.ChangeState("Run");
		return;
	}

	if (true == IsDown('Z'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_Straight");
		return;
	}

	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Run_Shoot_DiagonalUp(float _DeltaTime)
{
	DirCheck();

	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		createBullet();
		skillCoolTime = 0.3f;
		return;
	}

	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT) && true == IsFree('X'))
	{
		BulletStart->SetActive(false);
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

	if (true == IsFree(VK_UP))
	{
		ShootStyle = EShootDir::RunShoot;
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsFree('X'))
	{
		BulletStart->SetActive(false);
		State.ChangeState("Run");
		return;
	}

	if (true == IsDown('Z'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_Straight");
		return;
	}

	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Dash(float _DeltaTime)
{
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}

	FVector MovePos;

	switch (Dir)
	{
	case EDir::Left:
		MovePos += FVector::Left * _DeltaTime * DashSpeed;
		break;
	case EDir::Right:
		MovePos += FVector::Right * _DeltaTime * DashSpeed;
		break;
	default:
		break;
	}

	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::AirDash(float _DeltaTime)
{
	FVector MovePos = FVector::Zero;
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		NoGravity = false;
		State.ChangeState("DashAfterJump");
		return;
	}

	switch (Dir)
	{
	case EDir::Left:
		MovePos += FVector::Left * _DeltaTime * DashSpeed;
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
		ShootStyle = EShootDir::DuckShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Duck_Shoot");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_Straight(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime<0.0f)
	{
		createBullet();
		skillCoolTime = 0.3f;
		return;
	}

	if (true == IsFree('X'))
	{
		BulletStart->SetActive(false);
		State.ChangeState("Idle");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		ShootStyle = EShootDir::DuckShoot;
		State.ChangeState("Duck_Shoot");
		return;
	}

	if (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT))
	{
		ShootStyle = EShootDir::RunShoot;
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsDown('Z'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Duck_Shoot(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		createBullet();
		skillCoolTime = 0.3f;
		return;
	}
	if (true == IsFree(VK_DOWN))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_Straight");
		return;
	}

	if (true == IsFree('X'))
	{
		BulletStart->SetActive(false);
		State.ChangeState("Duck");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Jump(float _DeltaTime)
{
	DirCheck();

	//std::shared_ptr<UEngineTexture> Tex = UContentsHelper::MapTex;
	//Color8Bit Color = Tex->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::Black);

	//if (Color == Color8Bit::Black)
	//{
		//JumpVector = FVector::Zero;
	//}

	if (true == IsUp('Z'))
	{
		JumpVector = JumpPowerDown;
	}

	if (true == IsDown(VK_SHIFT))
	{
		NoGravity = true;
		JumpVector = FVector::Zero;
		State.ChangeState("AirDash");
		return;
	}

	if (true == IsDown('X'))
	{
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		State.ChangeState("JumpShoot");
		return;
	}

	FVector MovePos;

	// ���� ���� X�� �̵�
	if (true==IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * JumpSpeed * _DeltaTime;
	}

	if (true==IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * JumpSpeed * _DeltaTime;
	}


	MoveUpDate(_DeltaTime, MovePos); // ���� ������
	if (GetActorLocation().iY() <= -250)
	{
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	}


	//if (true == PlayCuphead->IsCurAnimationEnd())
	//{
		//JumpVector = FVector::Zero;
		//State.ChangeState("Idle");
		//return;
	//}
}

void APlay_Cuphead::JumpShoot(float _DeltaTime)
{
	DirCheck();

	if (true == IsUp('Z'))
	{
		JumpVector = JumpPowerDown;
	}

	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		createBullet();
		skillCoolTime = 0.3f;
		return;
	}

	if (true == IsFree('X'))
	{
		BulletStart->SetActive(false);
		State.ChangeState("Jump");
		return;
	}


	FVector MovePos;

	// ���� ���� X�� �̵�
	if (true == IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * JumpSpeed * _DeltaTime;
	}

	if (true == IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * JumpSpeed * _DeltaTime;
	}


	MoveUpDate(_DeltaTime, MovePos); // ���� ������

	if (GetActorLocation().iY() <= -250)
	{
		BulletStart->SetActive(false);
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	}

}

void APlay_Cuphead::DashAfterJump(float _DeltaTime)
{
	MoveUpDate(_DeltaTime); // ���� ������
	if (GetActorLocation().iY() <= -250)
	{
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	}
}
