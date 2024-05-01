#include "PreCompile.h"
#include "DevilPlatform.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"
#include "PokerChip.h"

#include "Boss2Common.h"
#include "Play_Cuphead.h"


int ADevilPlatform::count=1;
std::vector<int> ADevilPlatform::num;

ADevilPlatform::ADevilPlatform()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("DevilPlatform");
	DevilPlatform = CreateDefaultSubObject<USpriteRenderer>("DevilPlatform");

	DevilPlatform->SetupAttachment(Root);

	DevilPlatform->SetOrder(ERenderOrder::MidObject);
	DevilPlatform->SetSprite("devil_platforms_rocks_004.png");
	DevilPlatform->SetSamplering(ETextureSampling::LINEAR);
	DevilPlatform->SetAutoSize(0.85f, true);

	GroundCollision = CreateDefaultSubObject<UCollision>("GroundCollision");
	GroundCollision->SetupAttachment(Root);
	GroundCollision->AddPosition(FVector(0.0f, 35.0f, 0.0f));
	GroundCollision->SetScale(FVector(160.0f, 10.0f, 100.0f));

	GroundCollision->SetCollisionGroup(ECollisionOrder::Boss2Object1);
	GroundCollision->SetCollisionType(ECollisionType::RotRect);

	LRCollision = CreateDefaultSubObject<UCollision>("LRCollision2");
	LRCollision->SetupAttachment(Root);
	LRCollision->AddPosition(FVector(0.0f, -20.0f, 0.0f));
	LRCollision->SetScale(FVector(180.0f, 90.0f, 100.0f));

	LRCollision->SetCollisionGroup(ECollisionOrder::Boss1LR);
	LRCollision->SetCollisionType(ECollisionType::RotRect);

	SetRoot(Root);
}

ADevilPlatform::~ADevilPlatform()
{
	num.clear();
}

void ADevilPlatform::BeginPlay()
{
	Super::BeginPlay();

	DevilPlatform->CreateAnimation("DevilPlatform1", "DevilPlatform1", 0.075f);
	DevilPlatform->CreateAnimation("DevilPlatform2", "DevilPlatform2", 0.075f);
	DevilPlatform->CreateAnimation("DevilPlatform3", "DevilPlatform3", 0.075f);
	DevilPlatform->CreateAnimation("DevilPlatform4", "DevilPlatform4", 0.075f);

	DevilPlatform->ChangeAnimation("DevilPlatform1");

	patternInit();

	num.resize(4);
}

void ADevilPlatform::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == OneCheck)
	{
		OneCheck = true;

		CheckYDown = GetActorLocation().iY();
		CheckYUP = GetActorLocation().iY() + 180;
	}

	CreateChip(_DeltaTime);

	PlayerCollision();

	if (40 == ABoss2Common::GetHp())
	{
		if (GroundOrder == 1)
		{
			DownDie(_DeltaTime);
		}
	
		if (GroundOrder == 5)
		{
			DownDie(_DeltaTime);
		}
		count = 3;
		return;
	}
	else if (10 == ABoss2Common::GetHp())
	{
		if (GroundOrder == 2)
		{
			DownDie(_DeltaTime);
		}

		if (GroundOrder == 4)
		{
			DownDie(_DeltaTime);
		}
		count = 3;
		return;
	}

	if (count == GroundOrder)
	{
		pattern.Update(_DeltaTime);
	}
}

void ADevilPlatform::CreateChip(float _DeltaTime)
{
	Delay -= _DeltaTime;

	if (Delay < 0)
	{
		if (order == 1)
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (0 == order - num[i])
				{
					order += Add;
					return;
				}
			}

			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(580.0f, 500.0f, 10.0f));
		}
		else if (order == 2)
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (0 == order - num[i])
				{
					order += Add;
					return;
				}
			}
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(290.0f, 500.0f, 10.0f));
		}
		else if (order == 3)
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (0 == order - num[i])
				{
					order += Add;
					return;
				}
			}
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(0.0f, 500.0f, 10.0f));
		}
		else if (order == 4)
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (0 == order - num[i])
				{
					order += Add;
					return;
				}
			}
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(-290.0f, 500.0f, 10.0f));
		}
		else if (order == 5)
		{
			for (int i = 0; i < num.size(); i++)
			{
				if (0 == order - num[i])
				{
					order += Add;
					return;
				}
			}
			GetWorld()->SpawnActor<APokerChip>("PokerChip")->SetActorLocation(FVector(-580.0f, 500.0f, 10.0f));
		}
		else if (order == 6 || order == 0) {
			Add *= -1;
		}

		order += Add;
		Delay = 4.0f;
	}
}

void ADevilPlatform::PlayerCollision()
{
	LRCollision->CollisionEnter(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);
		Player->AddActorLocation(FVector::Up * 100.0f);
		Player->State.ChangeState("hit");
	});
}

void ADevilPlatform::patternInit()
{
	pattern.CreateState("UP");
	pattern.CreateState("DOWN");
	pattern.CreateState("DownDie");

	pattern.SetUpdateFunction("UP", std::bind(&ADevilPlatform::UP, this, std::placeholders::_1));
	

	pattern.SetUpdateFunction("DOWN", std::bind(&ADevilPlatform::Down, this, std::placeholders::_1));

	pattern.SetUpdateFunction("DownDie", std::bind(&ADevilPlatform::DownDie, this, std::placeholders::_1));
	
	pattern.ChangeState("UP");
}

void ADevilPlatform::UP(float _DeltaTime)
{
	if (GetActorLocation().iY() == CheckYUP)
	{
		pattern.ChangeState("DOWN");
		return;
	}
	
	AddActorLocation(FVector::Up*Speed*_DeltaTime);
	GroundCollision->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);
		Player->AddActorLocation(FVector::Up * Speed * _DeltaTime);
	});
}

void ADevilPlatform::Down(float _DeltaTime)
{

	if (GetActorLocation().iY() == CheckYDown)
	{

		if (count == 5)
		{
			count = 1;
			pattern.ChangeState("UP");
			return;
		}
		
		++count;
		pattern.ChangeState("UP");
		return;
	}


	AddActorLocation(FVector::Down * Speed * _DeltaTime);

	GroundCollision->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);
		Player->AddActorLocation(FVector::Down * Speed * _DeltaTime);
	});
}

void ADevilPlatform::DownDie(float _DeltaTime)
{
	if (GetActorLocation().iY() <=-400)
	{
		num.push_back(GroundOrder);
		Destroy();
		return;
	}

	AddActorLocation(FVector::Down * Speed * _DeltaTime);
}
