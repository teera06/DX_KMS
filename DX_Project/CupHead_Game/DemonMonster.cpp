#include "PreCompile.h"
#include "DemonMonster.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ADemonMonster::ADemonMonster()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Demon");
	Demon = CreateDefaultSubObject<USpriteRenderer>("Demon");

	Demon->SetupAttachment(Root);
	//Boss2->SetPivot(EPivot::LEFTTOP);

	SetRoot(Root);

	Demon->SetOrder(ERenderOrder::Boss1_back3);
	Demon->SetSprite("a1.png");
	Demon->SetSamplering(ETextureSampling::LINEAR);
	Demon->SetAutoSize(1.0f, true);
}

ADemonMonster::~ADemonMonster()
{
}

void ADemonMonster::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(-200.0f, -90.0f, 100.0f));
	AniCreate();
	StateInit();
}

void ADemonMonster::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	State.Update(_DeltaTime);
}

void ADemonMonster::AniCreate()
{
	Demon->CreateAnimation("DemonIntro1", "DemonIntro1", 0.075f);
	Demon->CreateAnimation("DemonJump", "DemonJump", 0.075f);
	Demon->CreateAnimation("DemonAttack", "DemonAttack", 0.075f);
	
}

void ADemonMonster::StateInit()
{
	State.CreateState("DemonIntro1");
	State.CreateState("DemonJump");
	State.CreateState("DemonAttack1");
	State.CreateState("DemonAttack2");
	
	State.SetUpdateFunction("DemonIntro1", std::bind(&ADemonMonster::DemonIntro1, this, std::placeholders::_1));
	State.SetStartFunction("DemonIntro1", [=] {Demon->ChangeAnimation("DemonIntro1"); });
	
	State.SetUpdateFunction("DemonJump", std::bind(&ADemonMonster::DemonJump, this, std::placeholders::_1));
	State.SetStartFunction("DemonJump", [=] {Demon->ChangeAnimation("DemonJump"); });

	State.SetUpdateFunction("DemonAttack1", std::bind(&ADemonMonster::DemonAttack1, this, std::placeholders::_1));
	State.SetStartFunction("DemonAttack1", [=] {Demon->ChangeAnimation("DemonAttack"); });

	State.SetUpdateFunction("DemonAttack2", std::bind(&ADemonMonster::DemonAttack2, this, std::placeholders::_1));
	State.SetStartFunction("DemonAttack2", [=] {Demon->ChangeAnimation("DemonAttack"); });
	
	State.ChangeState("DemonIntro1");
}

void ADemonMonster::DemonIntro1(float _DeltaTime)
{

	if (true == Demon->IsCurAnimationEnd())
	{
		State.ChangeState("DemonJump");
		return;
	}
}

void ADemonMonster::DemonJump(float _DeltaTime)
{
	AddActorLocation((Move+(FVector::Up*0.05f)) * speed * _DeltaTime);

	if (true == Demon->IsCurAnimationEnd())
	{
		State.ChangeState("DemonAttack1");
		return;
	}

}

void ADemonMonster::DemonAttack1(float _DeltaTime)
{

	AddActorLocation(Move * speed * _DeltaTime);
	if (GetActorLocation().iX() <= -700 || GetActorLocation().iX() >= 700) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Demon->SetDir(EEngineDir::Left);
		Move = FVector::Right;
		AddActorLocation(FVector(0.0f, -180.0f, -100.0f));
		Demon->SetOrder(ERenderOrder::BossSkillMonster);
		State.ChangeState("DemonAttack2");
		return;
	}
}

void ADemonMonster::DemonAttack2(float _DeltaTime)
{
	AddActorLocation(Move * speed * _DeltaTime);
	if (GetActorLocation().iX() <= -700 || GetActorLocation().iX() >= 700) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{

	}
}
