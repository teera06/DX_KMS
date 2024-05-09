#include "PreCompile.h"
#include "Axe.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Play_Cuphead.h"

AAxe::AAxe()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Axe");
	Axe = CreateDefaultSubObject<USpriteRenderer>("Axe");
	Axe->SetupAttachment(Root);

	Axe->SetOrder(ERenderOrder::FrontSkillMonster);
	Axe->SetSprite("devil_ph3_axe_spin_0001.png");
	Axe->SetSamplering(ETextureSampling::LINEAR);
	Axe->SetAutoSize(1.0f, true);


	AxeCol = CreateDefaultSubObject<UCollision>("Collision");
	AxeCol->SetupAttachment(Root);
	
	AxeCol->SetScale(FVector(70.0f, 100.0f, 100.0f));

	AxeCol->SetCollisionGroup(ECollisionOrder::Axe);
	AxeCol->SetCollisionType(ECollisionType::RotRect);


	

	SetRoot(Root);
}

AAxe::~AAxe()
{
}

void AAxe::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, 0.0f, 5.0f));

	Axe->CreateAnimation("Spiral_Spawn", "Spiral_Spawn", 0.075f);
	Axe->CreateAnimation("Spiral_Spin", "Spiral_Spin", 0.075f);

	patternInit();
}

void AAxe::Tick(float _DeltaTime)
{

	Super::Tick(_DeltaTime);
	pattern.Update(_DeltaTime);

	
	//AddActorRotation(FVector(0.0f, 0.0f, UEngineMath::DToR) * OneSpeed * _DeltaTime);
	//AddActorLocation((FVector::Right+FVector::Up+FVector::Left+FVector::Down) * MoveSpeed * _DeltaTime);
}

void AAxe::CalDir(float _DeltaTime)
{
	FVector AxeDir = GetActorLocation();
	FVector PlayerPos= APlay_Cuphead::GetPlayerPos();

	FVector Move = PlayerPos - AxeDir;

	FVector MoveNorMalize = Move.Normalize3DReturn();

	AddActorLocation(MoveNorMalize * MoveSpeed * _DeltaTime);
}

void AAxe::CollisionCheck()
{
	AxeCol->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		if (nullptr != Player)
		{
			Player->AddActorLocation(FVector::Up * 100.0f);
			Player->State.ChangeState("hit");
		}
	});
}

void AAxe::patternInit()
{
	pattern.CreateState("Start");
	pattern.CreateState("StartMove");
	pattern.CreateState("AttMove");

	pattern.SetUpdateFunction("Start", std::bind(&AAxe::Start, this, std::placeholders::_1));
	pattern.SetStartFunction("Start", [=] {Axe->ChangeAnimation("Spiral_Spawn"); });

	pattern.SetUpdateFunction("StartMove", std::bind(&AAxe::StartMove, this, std::placeholders::_1));
	pattern.SetStartFunction("StartMove", [=] {Axe->ChangeAnimation("Spiral_Spin"); });

	pattern.SetUpdateFunction("AttMove", std::bind(&AAxe::AttMove, this, std::placeholders::_1));
	pattern.SetStartFunction("AttMove", [=] {Axe->ChangeAnimation("Spiral_Spin"); });

	pattern.ChangeState("Start");
}

void AAxe::Start(float _DeltaTime)
{
	if (true == Axe->IsCurAnimationEnd())
	{
		pattern.ChangeState("StartMove");
		return;
	}
}

void AAxe::StartMove(float _DeltaTime)
{
	Delay -= _DeltaTime;
	CalDir(_DeltaTime);

	if (Delay < 0)
	{
		pattern.ChangeState("AttMove");
		return;
	}

	CollisionCheck();
}

void AAxe::AttMove(float _DeltaTime)
{
	FMatrix RotationMat, RotationXMat, RotationYMat, RotationZMat;
	RotationXMat.RotationXDeg(GetActorTransform().GetRotation().X);
	RotationYMat.RotationYDeg(GetActorTransform().GetRotation().Y);
	RotationZMat.RotationZDeg(GetActorTransform().GetRotation().Z);
	RotationMat = RotationXMat * RotationYMat * RotationZMat;

	MoveSpeed += 0.1f;

	AddActorRotation(FVector(0.0f, 0.0f, UEngineMath::DToR * RotSpeed * _DeltaTime));
	AddActorLocation(RotationMat.RightVector() * MoveSpeed * _DeltaTime);

	if (GetActorLocation().iX() <= -800 || GetActorLocation().iX() >= 840)
	{
		Destroy();
		return;
	}


	if (GetActorLocation().iY() <= -500 || GetActorLocation().iY() >= 500)
	{
		Destroy();
		return;
	}

	CollisionCheck();
}
