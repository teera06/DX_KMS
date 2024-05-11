#include "PreCompile.h"
#include "WorldPlayer.h"
#include "ContentsHelper.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineEnums.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/EngineCore.h>
#include <EngineCore/Camera.h>

#include <EngineCore/Collision.h>

#include "WorldDust.h"
#include "ScreenEffect.h"


//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void AWorldPlayer::DebugMessageFunction()
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

void AWorldPlayer::DirCheck()
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		WorldPlayerRenderer->SetDir(EEngineDir::Left);
		Dir = EDir::Left;
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		WorldPlayerRenderer->SetDir(EEngineDir::Right);
		Dir = EDir::Right;
	}
	if (UEngineInput::IsPress(VK_UP))
	{
		Dir = EDir::Up;
	}
	if (UEngineInput::IsPress(VK_DOWN))
	{
		Dir = EDir::Down;
	}
}

void AWorldPlayer::MoveUpDate(float _DeltaTime,const FVector& _MovePos)
{
	std::shared_ptr<UEngineTexture> Tex = UContentsHelper::MapTex;

#ifdef _DEBUG
	if (nullptr == Tex)
	{
		MsgBoxAssert("이미지 충돌체크중 이미지가 존재하지 않습니다.");
	}
#endif

	PlayMove = _MovePos;
	// 방향 별 픽셀 충돌 인식 범위
	float4 Pos = GetActorLocation();

	// 반대로 y축을 적용 해야한다.
	Pos.Y = -Pos.Y;
	switch (Dir)
	{
	case EDir::Left:
		Pos.X-= 30.0f;
		break;
	case EDir::Right:
		Pos.X += 30.0f;
		break;
	case EDir::Up:
		Pos.Y -= 30.0f;
		break;
	case EDir::Down:
		Pos.Y += 30.0f;
		break;
	default:
		break;
	}

	Color8Bit Color = Tex->GetColor(Pos.iX(),Pos.iY(), Color8Bit::Black);

	if (Color == Color8Bit::Black)
	{
		PlayMove = FVector::Zero;
	}


	GetWorld()->GetMainCamera()->AddActorLocation(PlayMove);
	AddActorLocation(PlayMove);

}


void AWorldPlayer::BossStartCheck()
{
	PlayerCollision->CollisionStay(ECollisionOrder::WorldObject2 , [=](std::shared_ptr<UCollision> _Collison)
	{
		Boss2Check = true;
		AButton->SetActive(true);
	});

	PlayerCollision->CollisionExit(ECollisionOrder::WorldObject2, [=](std::shared_ptr<UCollision> _Collison)
	{
		Boss2Check = false;
		AButton->SetActive(false);
	});

	PlayerCollision->CollisionStay(ECollisionOrder::WorldObject1, [=](std::shared_ptr<UCollision> _Collison)
	{
		Boss1Check = true;
		AButton->SetActive(true);
	});

	PlayerCollision->CollisionExit(ECollisionOrder::WorldObject1, [=](std::shared_ptr<UCollision> _Collison)
	{
		Boss1Check = false;
		AButton->SetActive(false);
	});
}

void AWorldPlayer::StateInit()
{
	// 스테이트 만들고
	//State.CreateState("Die");
	State.CreateState("UpIdle");
	State.CreateState("UpWalk");

	State.CreateState("DownIdle");
	State.CreateState("DownWalk");

	State.CreateState("StraightIdle");
	State.CreateState("StraightWalk");

	State.CreateState("DiagonalUpIdle");
	State.CreateState("DiagonalUpWalk");

	State.CreateState("DiagonalDownIdle");
	State.CreateState("DiagonalDownWalk");

	State.CreateState("BossStartBefore");
	//State.CreateState("Run");

	// 함수들 세팅하고
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

	State.SetUpdateFunction("StraightIdle", std::bind(&AWorldPlayer::StraightIdle, this, std::placeholders::_1));
	State.SetStartFunction("StraightIdle", [=] {WorldPlayerRenderer->ChangeAnimation("StraightIdle"); });

	State.SetUpdateFunction("DiagonalUpIdle", std::bind(&AWorldPlayer::DiagonalUpIdle, this, std::placeholders::_1));
	State.SetStartFunction("DiagonalUpIdle", [=] {WorldPlayerRenderer->ChangeAnimation("DiagonalUpIdle"); });

	State.SetUpdateFunction("DiagonalUpWalk", std::bind(&AWorldPlayer::DiagonalUpWalk, this, std::placeholders::_1));
	State.SetStartFunction("DiagonalUpWalk", [=] {WorldPlayerRenderer->ChangeAnimation("DiagonalUpWalk"); });

	State.SetUpdateFunction("DiagonalDownIdle", std::bind(&AWorldPlayer::DiagonalDownIdle, this, std::placeholders::_1));
	State.SetStartFunction("DiagonalDownIdle", [=] {WorldPlayerRenderer->ChangeAnimation("DiagonalDownIdle"); });

	State.SetUpdateFunction("DiagonalDownWalk", std::bind(&AWorldPlayer::DiagonalDownWalk, this, std::placeholders::_1));
	State.SetStartFunction("DiagonalDownWalk", [=] {WorldPlayerRenderer->ChangeAnimation("DiagonalDownWalk"); });

	State.SetUpdateFunction("BossStartBefore", std::bind(&AWorldPlayer::BossStartBefore, this, std::placeholders::_1));
	State.SetStartFunction("BossStartBefore", [=] {WorldPlayerRenderer->ChangeAnimation("DownIdle"); });
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
	State.ChangeState("DownIdle");
}



void AWorldPlayer::UpIdle(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();

	if (true == UEngineInput::IsDown('A') && true == Boss2Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss2title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('A') && true == Boss1Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss1title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('Z'))
	{
		GEngine->ChangeLevel("Loading");
	}

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

	if (true == IsPress(VK_RIGHT))
	{
		WorldPlayerRenderer->SetDir(EEngineDir::Right);
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsPress(VK_RIGHT))
	{
		WorldPlayerRenderer->SetDir(EEngineDir::Right);
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		WorldPlayerRenderer->SetDir(EEngineDir::Left);
		State.ChangeState("StraightWalk");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void AWorldPlayer::UpWalk(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();
	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_UP))
	{
		State.ChangeState("UpIdle");
		return;
	}

	if (true == IsPress(VK_RIGHT))
	{
		State.ChangeState("DiagonalUpWalk");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		State.ChangeState("DiagonalUpWalk");
		return;
	}

	DustTime -= _DeltaTime;

	if (DustTime < 0)
	{
		GetWorld()->SpawnActor<AWorldDust>("WorldDust");
		DustTime = 0.45f;
	}

	if (true == IsPress(VK_UP))
	{
		MovePos+=FVector::Up * _DeltaTime * Speed;
	}
	MoveUpDate(_DeltaTime, MovePos);
}

void AWorldPlayer::DownIdle(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();

	if (true == UEngineInput::IsDown('A') && true==Boss2Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss2title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('A') && true == Boss1Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss1title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

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

	if (true == IsPress(VK_RIGHT))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void AWorldPlayer::DownWalk(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();
	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("DownIdle");
		return;
	}

	if (true == IsPress(VK_RIGHT))
	{
		State.ChangeState("DiagonalDownWalk");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		State.ChangeState("DiagonalDownWalk");
		return;
	}

	DustTime -= _DeltaTime;

	if (DustTime < 0)
	{
		GetWorld()->SpawnActor<AWorldDust>("WorldDust");
		DustTime = 0.45f;
	}

	if (true == IsPress(VK_DOWN))
	{
		MovePos+=FVector::Down * _DeltaTime * Speed;
	}
	MoveUpDate(_DeltaTime, MovePos);
}

void AWorldPlayer::StraightIdle(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();

	if (true == UEngineInput::IsDown('A') && true == Boss2Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss2title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('A') && true == Boss1Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss1title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('Z'))
	{
		GEngine->ChangeLevel("Loading");
	}

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

	if (true == IsPress(VK_RIGHT))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		State.ChangeState("StraightWalk");
		return;
	}
	MoveUpDate(_DeltaTime);
}

void AWorldPlayer::StraightWalk(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();
	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("StraightIdle");
		return;
	}

	if (true == IsPress(VK_UP))
	{
		State.ChangeState("DiagonalUpWalk");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		State.ChangeState("DiagonalDownWalk");
		return;
	}

	DustTime -= _DeltaTime;

	if (DustTime < 0)
	{
		GetWorld()->SpawnActor<AWorldDust>("WorldDust");
		DustTime = 0.45f;
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


void AWorldPlayer::DiagonalUpIdle(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();

	if (true == UEngineInput::IsDown('A') && true == Boss2Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss2title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('A') && true == Boss1Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss1title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('Z'))
	{
		GEngine->ChangeLevel("Loading");
	}

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

	if (true == IsPress(VK_RIGHT))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		State.ChangeState("StraightWalk");
		return;
	}


	if ((true == IsPress(VK_LEFT)|| true == IsPress(VK_RIGHT)) && true == IsPress(VK_UP))
	{
		State.ChangeState("DiagonalUpWalk");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void AWorldPlayer::DiagonalUpWalk(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();
	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_UP))
	{
		State.ChangeState("DiagonalUpIdle");
		return;
	}

	if (true == IsFree(VK_UP) && true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("DiagonalUpIdle");
		return;
	}

	if (true == IsFree(VK_UP))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("UpWalk");
		return;
	}

	DustTime -= _DeltaTime;

	if (DustTime < 0)
	{
		GetWorld()->SpawnActor<AWorldDust>("WorldDust");
		DustTime = 0.45f;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_UP))
	{
		MovePos+=(FVector::Left+ FVector::Up) * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_RIGHT) && true == IsPress(VK_UP))
	{
		MovePos+=(FVector::Right + FVector::Up)* _DeltaTime * Speed;
	}

	MoveUpDate(_DeltaTime, MovePos);
}

void AWorldPlayer::DiagonalDownIdle(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();

	if (true == UEngineInput::IsDown('A') && true == Boss2Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss2title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}

	if (true == UEngineInput::IsDown('A') && true == Boss1Check)
	{

		//GEngine->ChangeLevel("Loading");
		Boss1title->SetActive(true);
		State.ChangeState("BossStartBefore");
		return;
	}


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

	if (true == IsPress(VK_RIGHT))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsPress(VK_RIGHT) && true == IsPress(VK_DOWN))
	{
		State.ChangeState("DiagonalDownWalk");
		return;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_DOWN))
	{
		State.ChangeState("DiagonalDownWalk");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void AWorldPlayer::DiagonalDownWalk(float _DeltaTime)
{
	DirCheck();
	BossStartCheck();
	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("DiagonalDownIdle");
		return;
	}
	if (true == IsFree(VK_DOWN) && true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("DiagonalDownIdle");
		return;
	}

	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("StraightWalk");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		State.ChangeState("DownWalk");
		return;
	}

	DustTime -= _DeltaTime;

	if (DustTime < 0)
	{
		GetWorld()->SpawnActor<AWorldDust>("WorldDust");
		DustTime = 0.45f;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_DOWN))
	{
		MovePos+=(FVector::Left + FVector::Down) * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_RIGHT) && true == IsPress(VK_DOWN))
	{
		MovePos += (FVector::Right + FVector::Down) * _DeltaTime * Speed;
	}

	MoveUpDate(_DeltaTime, MovePos);
}

void AWorldPlayer::BossStartBefore(float _DeltaTime)
{

	if (true == IsPress(VK_ESCAPE))
	{
		Boss2title->SetActive(false);
		Boss1title->SetActive(false);
		State.ChangeState("DownIdle");
		return;
	}

	if (true == IsDown('Z') && true == Boss2Check)
	{
		Boss2Check = false;
		std::shared_ptr<AScreenEffect> NewScreen = GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");
		NewScreen->SetBossZone(2);
		NewScreen->SetActorLocation(GetActorLocation());
		NewScreen->SetScreenEffect(EScreenEffect::IrisRe);
		Boss2title->SetActive(false);
		Boss1title->SetActive(false);
		State.ChangeState("DownIdle");
		return;
	}

	if (true == IsDown('Z') && true == Boss1Check)
	{
		Boss1Check = false;
		std::shared_ptr<AScreenEffect> NewScreen = GetWorld()->SpawnActor<AScreenEffect>("ScreenEffect");
		NewScreen->SetBossZone(1);
		NewScreen->SetActorLocation(GetActorLocation());
		NewScreen->SetScreenEffect(EScreenEffect::IrisRe);
		Boss2title->SetActive(false);
		Boss1title->SetActive(false);
		State.ChangeState("DownIdle");
		return;
	}
}

