#include "PreCompile.h"
#include "DevilPlatform.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

#include "Boss2Common.h"
#include "Play_Cuphead.h"


int ADevilPlatform::count=1;
int ADevilPlatform::PhaseCount = 1;
bool ADevilPlatform::Groundpattern = false;
bool ADevilPlatform::HPCheck1 = false;
bool ADevilPlatform::HPCheck2 = false;

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
		patternInit2();
		CheckYDown = GetActorLocation().iY();
		CheckYUP = GetActorLocation().iY() + 180;
	}

	if (50 == ABoss2Common::GetHp() && false==HPCheck1)
	{
		HPCheck1 = true;
		PhaseCount = 2;
		count = 3;
	}
	else if (25 == ABoss2Common::GetHp() && false == HPCheck2)
	{
		HPCheck2 = true;
		PhaseCount = 3;

		if (GroundOrder == 2)
		{
			DownDie(_DeltaTime);
		}

		if (GroundOrder == 4)
		{
			DownDie(_DeltaTime);
		}
	}

	PlayerCollision();

	if (true == HPCheck1)
	{
		if (GroundOrder == 1)
		{
			DownDie(_DeltaTime);
		}

		if (GroundOrder == 5)
		{
			DownDie(_DeltaTime);
		}
	}


	if (true == HPCheck2)
	{
		if (GroundOrder == 2)
		{
			DownDie(_DeltaTime);
		}

		if (GroundOrder == 4)
		{
			DownDie(_DeltaTime);
		}
	}



	if (PhaseCount == 1 && count==GroundOrder)
	{ 
		
		pattern1.Update(_DeltaTime);
	}
	else if (PhaseCount == 2 && count == GroundOrder) // ÆäÀÌÁö 3
	{
		
		pattern2.Update(_DeltaTime);
	}
	else if (PhaseCount == 3 && count == GroundOrder)
	{
		LastPos(_DeltaTime);
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
	pattern1.CreateState("UP");
	pattern1.CreateState("DOWN");
	

	pattern1.SetUpdateFunction("UP", std::bind(&ADevilPlatform::UP, this, std::placeholders::_1));
	

	pattern1.SetUpdateFunction("DOWN", std::bind(&ADevilPlatform::Down, this, std::placeholders::_1));

	
	pattern1.ChangeState("UP");
}

void ADevilPlatform::patternInit2()
{
	pattern2.CreateState("UP");
	pattern2.CreateState("DOWN");
	
		   
	pattern2.SetUpdateFunction("UP", std::bind(&ADevilPlatform::UP, this, std::placeholders::_1));
		   
		   
	pattern2.SetUpdateFunction("DOWN", std::bind(&ADevilPlatform::Down2, this, std::placeholders::_1));
		   
		   
	pattern2.ChangeState("UP");
}


void ADevilPlatform::UP(float _DeltaTime)
{
	if (GetActorLocation().iY() == CheckYUP)
	{
		if (PhaseCount == 1)
		{
			pattern1.ChangeState("DOWN");
		}else if (PhaseCount == 2)
		{
			pattern2.ChangeState("DOWN");
		}
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

		if (false == Groundpattern)
		{
			if (count == 1)
			{
				count = 5;
				pattern1.ChangeState("UP");
				return;
			
			}else if (count == 5)
			{
				count = 4;
				pattern1.ChangeState("UP");
				return;
			}
			else if (count == 4)
			{
				count = 2;
				pattern1.ChangeState("UP");
				return;
			}
			else if (count == 2)
			{
				count = 3;
				pattern1.ChangeState("UP");
				return;
			}
			else if (count == 3)
			{
				Groundpattern = true;
				count = 1;
				pattern1.ChangeState("UP");
				return;
			}
		}
		else if (true == Groundpattern)
		{
			if (count == 1)
			{
				count = 3;
				pattern1.ChangeState("UP");
				return;
			}
			else if (count == 3)
			{
				count = 5;
				pattern1.ChangeState("UP");
				return;
			}
			else if (count == 5)
			{
				count = 4;
				pattern1.ChangeState("UP");
				return;
			}
			else if (count == 4)
			{
				count = 2;
				pattern1.ChangeState("UP");
				return;
				
			}
			else if (count == 2)
			{
				Groundpattern = false;
				count = 1;
				pattern1.ChangeState("UP");
				return;
			}
		}
	}


	AddActorLocation(FVector::Down * Speed * _DeltaTime);

	GroundCollision->CollisionStay(ECollisionOrder::Player, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		APlay_Cuphead* Player = dynamic_cast<APlay_Cuphead*>(Ptr);
		Player->AddActorLocation(FVector::Down * Speed * _DeltaTime);
	});
}

void ADevilPlatform::LastPos(float _DeltaTime)
{
	if (GetActorLocation().iY() == CheckYDown)
	{
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


void ADevilPlatform::Down2(float _DeltaTime)
{
	if (GetActorLocation().iY() == CheckYDown)
	{

		if (false == Groundpattern)
		{
			if (count == 3)
			{
				count = 2;
				pattern2.ChangeState("UP");
				return;

			}
			else if (count == 2)
			{
				count = 4;
				pattern2.ChangeState("UP");
				return;
			}
			else if (count == 4)
			{
				count = 2;
				Groundpattern = true;
				pattern2.ChangeState("UP");
				return;
			}
		}
		else if (true == Groundpattern)
		{
			if (count == 2)
			{
				count = 3;
				pattern2.ChangeState("UP");
				return;

			}
			else if (count == 3)
			{
				count = 4;
				pattern2.ChangeState("UP");
				return;
			}
			else if (count == 4)
			{
				count = 2;
				Groundpattern = false;
				pattern2.ChangeState("UP");
				return;
			}
		}
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
		Destroy();
		return;
	}

	AddActorLocation(FVector::Down * Speed * _DeltaTime);
}
