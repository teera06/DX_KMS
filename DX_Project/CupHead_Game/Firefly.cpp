#include "PreCompile.h"
#include "Firefly.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "Play_Cuphead.h"
AFirefly::AFirefly()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Firefly");

	FireflyRender = CreateDefaultSubObject<USpriteRenderer>("FireflyRender");

	FireflyRender->SetupAttachment(Root);

	FireflyCollision = CreateDefaultSubObject<UCollision>("FireflyCollision");
	FireflyCollision->SetupAttachment(Root);
	FireflyCollision->SetScale(FVector(100.0f, 100.0f, 100.0f));

	FireflyCollision->SetCollisionGroup(ECollisionOrder::Boss1SkillMonster);
	FireflyCollision->SetCollisionType(ECollisionType::RotRect);


	SetRoot(Root);

	FireflyRender->SetOrder(ERenderOrder::BossSkillMonster);
	FireflyRender->SetSprite("tallfrog_firefly_left_0001.png");
	FireflyRender->SetSamplering(ETextureSampling::LINEAR);
	FireflyRender->SetAutoSize(1.0f, true);
}

AFirefly::~AFirefly()
{

}

void AFirefly::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation({280.0f,185.0f,0.0f });
	FireflyRender->SetPlusColor(FVector(0.1f, 0.1f, 0.1f));

	FireflyRender->CreateAnimation("bigskillLRMove", "bigskillLRMove", 0.1f);
	FireflyRender->CreateAnimation("bigSkillIdle", "bigSkillIdle", 0.1f);
	FireflyRender->CreateAnimation("BigSkillDeath", "BigSkillDeath", 0.1f);
	//smallskillRender->CreateAnimation("Peashot_Loop", "Peashot_Loop", 0.05f);

	patternStateInit();

}

void AFirefly::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	pattern.Update(_DeltaTime);
	CollisionCheck();
	
}

void AFirefly::CalDir(float _DeltaTime)
{
	FVector PlayerPos = APlay_Cuphead::GetPlayerPos();
	FVector MonsterPos = GetActorLocation();

	FVector Move = PlayerPos- MonsterPos;

	FVector MoveNorMalize = Move.Normalize3DReturn();

	if (MoveNorMalize.iroundX() == -1 || MoveNorMalize.iroundX() == 0)
	{
		FireflyRender->SetDir(EEngineDir::Right);
	}
	else if (MoveNorMalize.iroundX() == 1)
	{
		FireflyRender->SetDir(EEngineDir::Left);
	}

	AddActorLocation(Move.Normalize3DReturn() * Speed * _DeltaTime);
}

void AFirefly::patternStateInit()
{
	pattern.CreateState("Intro");
	pattern.CreateState("bigSkillIdle");
	pattern.CreateState("bigskillLRMove");
	pattern.CreateState("Death");

	

	pattern.SetUpdateFunction("Intro", std::bind(&AFirefly::Intro, this, std::placeholders::_1));
	pattern.SetStartFunction("Intro", [=] {FireflyRender->ChangeAnimation("bigskillLRMove"); });

	pattern.SetUpdateFunction("bigSkillIdle", std::bind(&AFirefly::bigSkillIdle, this, std::placeholders::_1));
	pattern.SetStartFunction("bigSkillIdle", [=] {FireflyRender->ChangeAnimation("bigSkillIdle"); });

	pattern.SetUpdateFunction("bigskillLRMove", std::bind(&AFirefly::bigskillLRMove, this, std::placeholders::_1));
	pattern.SetStartFunction("bigskillLRMove", [=] {FireflyRender->ChangeAnimation("bigskillLRMove"); });

	pattern.SetUpdateFunction("Death", std::bind(&AFirefly::Death, this, std::placeholders::_1));
	pattern.SetStartFunction("Death", [=] {FireflyRender->ChangeAnimation("BigSkillDeath"); });

	pattern.ChangeState("Intro");
}

void AFirefly::Intro(float _DeltaTime)
{
	Delay -= _DeltaTime;
	AddActorLocation(Move * Speed * _DeltaTime);

	if (true == Die)
	{
		pattern.ChangeState("Death");
		return;
	}

	if (Delay < 0.0f)
	{
		Delay = 2.0f;
		pattern.ChangeState("bigSkillIdle");
		return;
	}


}

void AFirefly::bigSkillIdle(float _DeltaTime)
{
	Delay -= _DeltaTime;

	if (true == Die)
	{
		pattern.ChangeState("Death");
		return;
	}

	if (Delay < 0.0f)
	{
		Delay = 0.3f;
		//MoveCoolDonwTime = 2.0f;
		pattern.ChangeState("bigskillLRMove");
		return;
	}
}

void AFirefly::bigskillLRMove(float _DeltaTime)
{
	CalDir(_DeltaTime);
	Delay -= _DeltaTime;

	if (true == Die)
	{
		pattern.ChangeState("Death");
		return;
	}

	if (Delay < 0.0f)
	{
		Delay = 2.0f;
		//MoveCoolDonwTime = 2.0f;
		pattern.ChangeState("bigSkillIdle");
		return;
	}
}

void AFirefly::Death(float _DeltaTime)
{
	if (true == FireflyRender->IsCurAnimationEnd())
	{
		UEngineSound::SoundPlay("frogs_tall_firefly_death_01.wav");
		Destroy();
	}
}

void AFirefly::CollisionCheck()
{
	FireflyCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);

		Player->State.ChangeState("hit");

		Die = true;
	});
}
