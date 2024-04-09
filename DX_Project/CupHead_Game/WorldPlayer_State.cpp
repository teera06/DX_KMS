#include "PreCompile.h"
#include "WorldPlayer.h"
#include <EngineCore/SpriteRenderer.h>

//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

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
}

void AWorldPlayer::UpWalk(float _DeltaTime)
{

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
}

void AWorldPlayer::DownWalk(float _DeltaTime)
{

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


}

void AWorldPlayer::StraightWalk(float _DeltaTime)
{

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


	if (true == IsPress(VK_LEFT))
	{
		SetActorScale3D(FVector(-60.0f, 100.0f, 100.0f));
		AddActorLocation(FVector::Left * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_RIGHT))
	{
		SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
		AddActorLocation(FVector::Right * _DeltaTime * Speed);
	}
}


void AWorldPlayer::DiagonalUpIdle(float _Update)
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

	if (true == IsPress(VK_RIGHT) && true == IsPress(VK_UP))
	{
		State.ChangeState("DiagonalUpWalk");
		return;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_UP))
	{
		State.ChangeState("DiagonalUpWalk");
		return;
	}
}

void AWorldPlayer::DiagonalUpWalk(float _DeltaTime)
{

	if (true == IsFree(VK_UP))
	{
		State.ChangeState("DiagonalUpIdle");
		return;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_UP))
	{
		SetActorScale3D(FVector(-60.0f, 100.0f, 100.0f));
		AddActorLocation((FVector::Left+ FVector::Up) * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_RIGHT) && true == IsPress(VK_UP))
	{
		SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
		AddActorLocation((FVector::Right + FVector::Up)* _DeltaTime * Speed);
	}
}

void AWorldPlayer::DiagonalDownIdle(float _Update)
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
}

void AWorldPlayer::DiagonalDownWalk(float _DeltaTime)
{

	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("DiagonalDownIdle");
		return;
	}

	if (true == IsPress(VK_LEFT) && true == IsPress(VK_DOWN))
	{
		SetActorScale3D(FVector(-60.0f, 100.0f, 100.0f));
		AddActorLocation((FVector::Left + FVector::Down) * _DeltaTime * Speed);
	}

	if (true == IsPress(VK_RIGHT) && true == IsPress(VK_DOWN))
	{
		SetActorScale3D(FVector(60.0f, 100.0f, 100.0f));
		AddActorLocation((FVector::Right + FVector::Down) * _DeltaTime * Speed);
	}
}

//void AWorldPlayer::Run(float _DeltaTime)
//{

	

	

	//std::shared_ptr<UEngineTexture> Tex = UContentsConstValue::MapTex;

//#ifdef _DEBUG
	//if (nullptr == Tex)
	//{
		//MsgBoxAssert("이미지 충돌체크중 이미지가 존재하지 않습니다.");
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
