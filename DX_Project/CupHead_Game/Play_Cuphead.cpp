#include "PreCompile.h"
#include "Play_Cuphead.h"

#include <EngineCore/Renderer.h>


APlay_Cuphead::APlay_Cuphead()
{
	CupHeadRenderer = CreateDefaultSubObject<URenderer>("Renderer");
	CupHeadRenderer->SetMesh("Rect");
	// ���׸����� ���ִ¼���
	// ���׸����� �ȿ� ���ؽ����̴��� �ȼ����̴��� �Ѵ� ��� ����.
	// ����  ��Ƽ�������ü�� �������ش�.
	// 
	CupHeadRenderer->SetMaterial("2DImage");

	// Renderer->�����ȼ����̴��������();
	// Renderer->���ù��ؽ����̴��������();
}

APlay_Cuphead::~APlay_Cuphead()
{
}

void APlay_Cuphead::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(300.0f, 300.0f, 100.0f));

	// �����ָ� �������Ѵ�.
	//CupHeadRenderer->Resources->SettingConstantBuffer("OutPutColor", Color);
	// ���ο��� ���÷��� ���� ã��
	CupHeadRenderer->Resources->SettingTexture("Image", "cuphead_idle_0001.png", "POINT");
}

void APlay_Cuphead::Tick(float _DeltaTime)
{
	// ���� ������ �ľ��Ҷ��� �ִ�.
	Super::Tick(_DeltaTime);

	
}

void APlay_Cuphead::StateUpdate(float _DeltaTime)
{
	switch (State) // ���� ���º� �����ؾ��ϴ� ����
	{
	case EPlayerState::Idle: // ���ֱ�
		Idle(_DeltaTime);
		break;
	case EPlayerState::Move: // �̵�
		//Walk(_DeltaTime);
		break;
	case EPlayerState::Jump: // ����
		//Run(_DeltaTime);
		break;
	case EPlayerState::Dash: // shift �̵�
		break;
	case EPlayerState::IdleAtt: // �� �ֱ� ����
		break;
	case EPlayerState::MoveAtt: // �̵� �ϸ� ����
		break;
	case EPlayerState::JumpAtt: // ���� ����
		break;
	
	default:
		break;
	}
}

void APlay_Cuphead::Idle(float _DeltaTime)
{
	
	// �̵�
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

