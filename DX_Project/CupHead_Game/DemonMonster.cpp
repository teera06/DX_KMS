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

	Demon->SetOrder(ERenderOrder::BackMonster);
	Demon->SetSprite("a1.png");
	Demon->SetSamplering(ETextureSampling::LINEAR);
	Demon->SetAutoSize(1.0f, true);
	Demon->SetPlusColor(FVector(0.1f,0.1f, 0.1f));
}

ADemonMonster::~ADemonMonster()
{
}

void ADemonMonster::BeginPlay()
{
	Super::BeginPlay();
	//SetActorScale3D(FVector(1600.0f, 900.0f, 100.0f));
	SetActorLocation(FVector(-188.0f, -90.0f, 100.0f));
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
	AddActorLocation((MoveL+(FVector::Up*0.05f)) * speed * _DeltaTime);

	if (true == Demon->IsCurAnimationEnd())
	{
		State.ChangeState("DemonAttack1");
		return;
	}

}

void ADemonMonster::DemonAttack1(float _DeltaTime)
{

	AddActorLocation(MoveL * speed * _DeltaTime);
	if (GetActorLocation().iX() <= -700 || GetActorLocation().iX() >= 700) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Demon->SetDir(EEngineDir::Left);
		MoveL = FVector::Right;
		AddActorLocation(FVector(0.0f, -140.0f, -100.0f));
		Demon->SetOrder(ERenderOrder::FrontSkillMonster);
		State.ChangeState("DemonAttack2");
		return;
	}
}

void ADemonMonster::DemonAttack2(float _DeltaTime)
{
	AddActorLocation(MoveL * speed * _DeltaTime);

	if (MoveL.iX()==1 && GetActorLocation().iX() >= 700) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		Destroy();
	}
}

void ADemonMonster::StateInit2()
{
	State2.CreateState("DemonIntro2");
	State2.CreateState("Demon2Jump");
	State2.CreateState("Demon2Attack1");
	State2.CreateState("Demon2Attack2");

	State2.SetUpdateFunction("DemonIntro2", std::bind(&ADemonMonster::DemonIntro2, this, std::placeholders::_1));
	State2.SetStartFunction("DemonIntro2", [=] {Demon->ChangeAnimation("DemonIntro2"); });

	State2.SetUpdateFunction("Demon2Jump", std::bind(&ADemonMonster::Demon2Jump, this, std::placeholders::_1));
	State2.SetStartFunction("Demon2Jump", [=] {Demon->ChangeAnimation("DemonJump"); });

	State2.SetUpdateFunction("Demon2Attack1", std::bind(&ADemonMonster::Demon2Attack1, this, std::placeholders::_1));
	State2.SetStartFunction("Demon2Attack1", [=] {Demon->ChangeAnimation("DemonAttack"); });

	State2.SetUpdateFunction("Demon2Attack2", std::bind(&ADemonMonster::Demon2Attack2, this, std::placeholders::_1));
	State2.SetStartFunction("Demon2Attack2", [=] {Demon->ChangeAnimation("DemonAttack"); });

	State2.ChangeState("DemonIntro1");
}

void ADemonMonster::DemonIntro2(float _DeltaTime)
{
	if (true == Demon->IsCurAnimationEnd())
	{
		State2.ChangeState("Demon2Jump");
		return;
	}
}



void ADemonMonster::Demon2Jump(float _DeltaTime)
{
	AddActorLocation((MoveL + (FVector::Up * 0.05f)) * speed * _DeltaTime);

	if (true == Demon->IsCurAnimationEnd())
	{
		State2.ChangeState("DemonAttack1");
		return;
	}
}

void ADemonMonster::Demon2Attack1(float _DeltaTime)
{
}

void ADemonMonster::Demon2Attack2(float _DeltaTime)
{
}
