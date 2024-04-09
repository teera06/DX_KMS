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
	//State.CreateState("Run");

	// 함수들 세팅하고
	State.SetUpdateFunction("UpIdle", std::bind(&AWorldPlayer::UpIdle, this, std::placeholders::_1));

	// 즉석 함수
	// = [ 람다캡쳐 Renderer]
	// {
	//    함수 내용
	// }

	// 람다캡처의 내용안에 =을 쓰면
	// 현재 스택에서 사용가능한 복사본을 만든다.
	// 메모리를 할당해서 Renderer를 같은 이름으로 복사한다.


	State.SetStartFunction("UpIdle", [=] {WorldPlayerRenderer->ChangeAnimation("UpIdle"); });


	State.SetUpdateFunction("UpWalk", std::bind(&AWorldPlayer::UpWalk, this, std::placeholders::_1));
	State.SetStartFunction("UpWalk", [=] {WorldPlayerRenderer->ChangeAnimation("UpWalk"); });
	//State.SetUpdateFunction("Run", std::bind(&AWorldPlayer::Run, this, std::placeholders::_1));

	//State.SetStartFunction("Run", std::bind(&AWorldPlayer::RunStart, this));





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
