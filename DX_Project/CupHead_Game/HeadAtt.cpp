#include "PreCompile.h"
#include "HeadAtt.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

AHeadAtt::AHeadAtt()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("headatt");
	headatt = CreateDefaultSubObject<USpriteRenderer>("headatt");

	headatt->SetupAttachment(Root);
	//Boss2->SetPivot(EPivot::LEFTTOP);

	SetRoot(Root);

	headatt->SetOrder(ERenderOrder::FrontSkill);
	headatt->SetSprite("devil_ph1_dragon_attack_0001.png");
	headatt->SetSamplering(ETextureSampling::LINEAR);
	headatt->SetAutoSize(1.0f, true);
}

AHeadAtt::~AHeadAtt()
{
}

void AHeadAtt::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(-900.0f, -100.0f, 0.0f));
	AniCreate();

	Phase1StateInit();
}

void AHeadAtt::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	//coolDownTime -= _DeltaTime;
	Phase1.Update(_DeltaTime);
}

void AHeadAtt::Phase1StateInit()
{
	Phase1.CreateState("DragonHeadAppear");
	Phase1.CreateState("DragonHeadSmile");
	Phase1.CreateState("DragonHeadDisappear");

	Phase1.SetUpdateFunction("DragonHeadAppear", std::bind(&AHeadAtt::DragonHeadAppear, this, std::placeholders::_1));
	Phase1.SetStartFunction("DragonHeadAppear", [=] {headatt->ChangeAnimation("DragonHeadAppear"); });

	Phase1.SetUpdateFunction("DragonHeadSmile", std::bind(&AHeadAtt::DragonHeadSmile, this, std::placeholders::_1));
	Phase1.SetStartFunction("DragonHeadSmile", [=] {headatt->ChangeAnimation("DragonHeadSmile"); });

	Phase1.SetUpdateFunction("DragonHeadDisappear", std::bind(&AHeadAtt::DragonHeadDisappear, this, std::placeholders::_1));
	Phase1.SetStartFunction("DragonHeadDisappear", [=] {headatt->ChangeAnimation("DragonHeadDisappear"); });

	Phase1.ChangeState("DragonHeadAppear");
}

void AHeadAtt::AniCreate()
{
	headatt->CreateAnimation("DragonHeadAppear", "DragonHeadAppear", 0.075f);
	headatt->CreateAnimation("DragonHeadSmile", "DragonHeadSmile", 0.075f);
	headatt->CreateAnimation("DragonHeadDisappear", "DragonHeadDisappear", 0.075f,false);
}

void AHeadAtt::DragonHeadAppear(float _DeltaTime)
{
	AddActorLocation(FVector::Right * speed* _DeltaTime);

	if (GetActorLocation().iX() >= -200)
	{
		Phase1.ChangeState("DragonHeadSmile");
		return;
	}
}

void AHeadAtt::DragonHeadSmile(float _DeltaTime)
{
	if (true == headatt->IsCurAnimationEnd())
	{
		Phase1.ChangeState("DragonHeadDisappear");
		return;
	}
}

void AHeadAtt::DragonHeadDisappear(float _DeltaTime)
{
	AddActorLocation(FVector::Left * 900.0f * _DeltaTime);

	if (GetActorLocation().iX() <= -1000)
	{
	
		if (true == headatt->IsCurAnimationEnd())
		{
			SkillDestory = true;
			Destroy();
			return;
		}
	}
}
