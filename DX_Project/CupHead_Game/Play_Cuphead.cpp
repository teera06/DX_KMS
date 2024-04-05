#include "PreCompile.h"
#include "Play_Cuphead.h"

#include <EngineCore/Renderer.h>


APlay_Cuphead::APlay_Cuphead()
{
	CupHeadRenderer = CreateDefaultSubObject<URenderer>("Renderer");
	CupHeadRenderer->SetMesh("Rect");
	// 메테리얼을 해주는순간
	// 메테리얼은 안에 버텍스쉐이더와 픽셀쉐이더를 둘다 들고 있죠.
	// 색깔  머티리얼그자체에 세팅해준다.
	// 
	CupHeadRenderer->SetMaterial("2DImage");

	// Renderer->세팅픽셀쉐이더상수버퍼();
	// Renderer->세팅버텍스쉐이더상수버퍼();
}

APlay_Cuphead::~APlay_Cuphead()
{
}

void APlay_Cuphead::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(300.0f, 300.0f, 100.0f));

	// 안해주면 터져야한다.
	//CupHeadRenderer->Resources->SettingConstantBuffer("OutPutColor", Color);
	// 내부에서 샘플러도 같이 찾을
	CupHeadRenderer->Resources->SettingTexture("Image", "cuphead_idle_0001.png", "POINT");
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
	// 위에 뭔가를 쳐야할때도 있다.
	Super::Tick(_DeltaTime);

	
}

void APlay_Cuphead::StateUpdate(float _DeltaTime)
{
	switch (State) // 현재 상태별 진행해야하는 형태
	{
	case EPlayerState::Idle: // 서있기
		Idle(_DeltaTime);
		break;
	case EPlayerState::Move: // 이동
		//Walk(_DeltaTime);
		break;
	case EPlayerState::Jump: // 점프
		//Run(_DeltaTime);
		break;
	case EPlayerState::Dash: // shift 이동
		break;
	case EPlayerState::IdleAtt: // 서 있기 공격
		break;
	case EPlayerState::MoveAtt: // 이동 하며 공격
		break;
	case EPlayerState::JumpAtt: // 점프 공격
		break;
	
	default:
		break;
	}
}

void APlay_Cuphead::Idle(float _DeltaTime)
{
	
	// 이동
	if (
		true == UEngineInput::IsPress(VK_LEFT) ||
		true == UEngineInput::IsPress(VK_RIGHT)
		)
	{
		//StateAniChange(EPlayerState::Move);
		return;
	}

	


}

void APlay_Cuphead::Move(float _DeltaTime)
{
}

