#include "PreCompile.h"
#include "Axe.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
AAxe::AAxe()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Axe");
	Axe = CreateDefaultSubObject<USpriteRenderer>("Axe");
	Axe->SetupAttachment(Root);

	Axe->SetOrder(ERenderOrder::FrontSkillMonster);
	Axe->SetSprite("devil_ph3_axe_spin_0001.png");
	Axe->SetSamplering(ETextureSampling::LINEAR);
	Axe->SetAutoSize(1.0f, true);

	AxeCollision = CreateDefaultSubObject<UCollision>("Collision");
	AxeCollision->SetupAttachment(Root);
	AxeCollision->SetPosition(FVector(0.0f, 00.0f, 0.0f));
	AxeCollision->SetScale(FVector(70.0f, 70.0f, 100.0f));

	AxeCollision->SetCollisionGroup(ECollisionOrder::Axe);
	AxeCollision->SetCollisionType(ECollisionType::RotBox);

	SetRoot(Root);
}

AAxe::~AAxe()
{
}

void AAxe::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, 0.0f, 5.0f));

	Axe->CreateAnimation("Spiral_Spin", "Spiral_Spin", 0.075f);

	Axe->ChangeAnimation("Spiral_Spin");

	//AddActorRotation(FVector(0.0f, 0.0f, 1.0f) * 60.0f);
}

void AAxe::Tick(float _DeltaTime)
{

	Super::Tick(_DeltaTime);

	FMatrix RotationMat, RotationXMat, RotationYMat, RotationZMat;
	RotationXMat.RotationXDeg(GetActorTransform().GetRotation().X);
	RotationYMat.RotationYDeg(GetActorTransform().GetRotation().Y);
	RotationZMat.RotationZDeg(GetActorTransform().GetRotation().Z);
	RotationMat = RotationXMat * RotationYMat * RotationZMat;

	MoveSpeed += 0.1f;

	AddActorRotation(FVector(0.0f, 0.0f, UEngineMath::DToR * OneSpeed*_DeltaTime));
	AddActorLocation(RotationMat.RightVector() * MoveSpeed * _DeltaTime);
	
	//AddActorRotation(FVector(0.0f, 0.0f, UEngineMath::DToR) * OneSpeed * _DeltaTime);
	//AddActorLocation((FVector::Right+FVector::Up+FVector::Left+FVector::Down) * MoveSpeed * _DeltaTime);
}
