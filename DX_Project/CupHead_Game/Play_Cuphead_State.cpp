#include "PreCompile.h"
#include "Play_Cuphead.h"

#include "ContentsHelper.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/EngineEnums.h>
#include <EngineCore/Camera.h>
#include <EngineCore/Image.h>

#include "RunDust.h"
#include "DashDust.h"
#include "SSDust.h"
#include "GroundDust.h"
#include "hitEffect.h"

#include "Boss1Common.h"
#include "Devil1.h"
#include "BaseBullet.h"
#include "BaseSSBullet.h"

#include "Boss1_Monster2.h"
#include "MoveObject2.h"

// 패링
#include "Orb_Fire.h"
#include "Orb_Fire2.h"
#include "DevilBall.h"
#include "smallskill.h"
#include "BombBat.h"
#include "FatDemonSkill.h"

#include "Hole.h"

#include "PhaseChangeBack.h"


//void Function(URenderer* Renderer)
//{
//	Renderer->ChangeAnimation("Idle");
//}

void APlay_Cuphead::ParryCheck(float _DeltaTime)
{
	ParryCollision->CollisionEnter(ECollisionOrder::Boss1Monster2Hand, [=](std::shared_ptr<UCollision> _Collison)
	{
		Effect->SetActive(true);
		UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster2* Hand = dynamic_cast<ABoss1_Monster2*>(Ptr);

		Hand->SetSlotTouch(true);



		GEngine->SetOrderTimeScale(static_cast<int>(ERenderOrder::Cuphead), 0.6f);
		//AddActorLocation(FVector::Up * 1000.0f* _DeltaTime);

		GravityVector = FVector::Down * 300.0f;
		AddGuage(ParryGuage);

		PlayerCollision->SetActive(false);
	});

	ParryCollision->CollisionStay(ECollisionOrder::Boss1Monster2Hand, [=](std::shared_ptr<UCollision> _Collison)
	{
		Effect->SetActive(true);
		UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
		AActor* Ptr = _Collison->GetActor();
		ABoss1_Monster2* Hand = dynamic_cast<ABoss1_Monster2*>(Ptr);

		Hand->SetSlotTouch(true);

		GEngine->SetGlobalTimeScale(0.6f);

		//AddActorLocation(FVector::Up * 1000.0f * _DeltaTime);
		GravityVector = FVector::Down*300.0f;
		AddGuage(ParryGuage);
		PlayerCollision->SetActive(false);
	});

	ParryCollision->CollisionEnter(ECollisionOrder::Orb_Fire1, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		AOrb_Fire* Fire1 = dynamic_cast<AOrb_Fire*>(Ptr);

		if (true == Fire1->GetParryCheck())
		{
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			Fire1->Destroy();
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		}

	});

	ParryCollision->CollisionStay(ECollisionOrder::Orb_Fire1, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		AOrb_Fire* Fire1 = dynamic_cast<AOrb_Fire*>(Ptr);

		if (true == Fire1->GetParryCheck())
		{
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			Fire1->Destroy();
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		}
	});

	ParryCollision->CollisionEnter(ECollisionOrder::MonsterSkill, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		Asmallskill* skill = dynamic_cast<Asmallskill*>(Ptr);

		if (true == skill->GetParryCheck())
		{
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			skill->Destroy();
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		}

	});

	ParryCollision->CollisionStay(ECollisionOrder::MonsterSkill, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		Asmallskill* skill = dynamic_cast<Asmallskill*>(Ptr);

		if (true == skill->GetParryCheck())
		{
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			skill->Destroy();
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		}
	});

	ParryCollision->CollisionEnter(ECollisionOrder::Orb_Fire2_Parry, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			AOrb_Fire2* Fire = dynamic_cast<AOrb_Fire2*>(Ptr);


			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			Fire->GetMainRender()->SetActive(false);
			Fire->GetMainCollision()->SetActive(false);
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		});

	ParryCollision->CollisionStay(ECollisionOrder::Orb_Fire2_Parry, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			AOrb_Fire2* Fire = dynamic_cast<AOrb_Fire2*>(Ptr);

			
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			Fire->GetMainRender()->SetActive(false);
			Fire->GetMainCollision()->SetActive(false);
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		});

	ParryCollision->CollisionEnter(ECollisionOrder::Devil1ball, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			ADevilBall* ball = dynamic_cast<ADevilBall*>(Ptr);

			if (true == ball->GetParryCheck())
			{
				Effect->SetActive(true);
				UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
				GEngine->SetGlobalTimeScale(0.6f);
				GravityVector = FVector::Down * 300.0f;

				ball->Destroy();
				AddGuage(ParryGuage);
				PlayerCollision->SetActive(false);
			}

		});

	ParryCollision->CollisionStay(ECollisionOrder::Devil1ball, [=](std::shared_ptr<UCollision> _Collison)
		{
			AActor* Ptr = _Collison->GetActor();
			ADevilBall* ball = dynamic_cast<ADevilBall*>(Ptr);

			if (true == ball->GetParryCheck())
			{
				Effect->SetActive(true);
				UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
				GEngine->SetGlobalTimeScale(0.6f);
				GravityVector = FVector::Down * 300.0f;

				ball->Destroy();
				AddGuage(ParryGuage);
				PlayerCollision->SetActive(false);
			}
		});


	ParryCollision->CollisionEnter(ECollisionOrder::BombBat, [=](std::shared_ptr<UCollision> _Collison)
	{

		AActor* Ptr = _Collison->GetActor();
		ABombBat* Monster = dynamic_cast<ABombBat*>(Ptr);
		Effect->SetActive(true);
		UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
		GEngine->SetGlobalTimeScale(0.6f);
		GravityVector = FVector::Down * 300.0f;

		Monster->Destroy();
		AddGuage(ParryGuage);
		PlayerCollision->SetActive(false);
	});

	ParryCollision->CollisionStay(ECollisionOrder::BombBat, [=](std::shared_ptr<UCollision> _Collison)
	{

		AActor* Ptr = _Collison->GetActor();
		Asmallskill* skill = dynamic_cast<Asmallskill*>(Ptr);

		if (true == skill->GetParryCheck())
		{
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			skill->Destroy();
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		}
	});


	ParryCollision->CollisionEnter(ECollisionOrder::FatSkill, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		AFatDemonSkill* skill = dynamic_cast<AFatDemonSkill*>(Ptr);

		if (true == skill->GetParryCheck())
		{
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			skill->Destroy();
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		}

	});

	ParryCollision->CollisionStay(ECollisionOrder::FatSkill, [=](std::shared_ptr<UCollision> _Collison)
	{
		AActor* Ptr = _Collison->GetActor();
		AFatDemonSkill* skill = dynamic_cast<AFatDemonSkill*>(Ptr);

		if (true == skill->GetParryCheck())
		{
			Effect->SetActive(true);
			UEngineSound::SoundPlay("sfx_player_parry_slap_01.wav");
			GEngine->SetGlobalTimeScale(0.6f);
			GravityVector = FVector::Down * 300.0f;

			skill->Destroy();
			AddGuage(ParryGuage);
			PlayerCollision->SetActive(false);
		}
	});

}

void APlay_Cuphead::GroundObject()
{

	if (GetActorLocation().iY() <= GrounYCheck)
	{
		BaseBulletSound.Off();
		GetWorld()->SpawnActor<AGroundDust>("AGroundDust");
		BulletStart->SetActive(false);
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	}

	GroundCollision->CollisionEnter(ECollisionOrder::Boss1Top, [=](std::shared_ptr<UCollision> _Collison)
	{
		BaseBulletSound.Off();
		GetWorld()->SpawnActor<AGroundDust>("AGroundDust");
		BulletStart->SetActive(false);
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	});

	GroundCollision->CollisionStay(ECollisionOrder::Boss1Top, [=](std::shared_ptr<UCollision> _Collison)
	{
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	});

	GroundCollision->CollisionEnter(ECollisionOrder::Boss2Object1, [=](std::shared_ptr<UCollision> _Collison)
	{
		BaseBulletSound.Off();
		GetWorld()->SpawnActor<AGroundDust>("AGroundDust");
		BulletStart->SetActive(false);
		Devil2GrounCheck = true;
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	});

	GroundCollision->CollisionStay(ECollisionOrder::Boss2Object1, [=](std::shared_ptr<UCollision> _Collison)
	{
		Devil2GrounCheck = true;
		JumpVector = FVector::Zero;
		State.ChangeState("Idle");
		return;
	});
}

void APlay_Cuphead::EventCollision(float _DeltaTime)
{
	PlayerCollision->CollisionEnter(ECollisionOrder::Hole, [=](std::shared_ptr<UCollision> _Collison)
	{
		BaseBulletSound.Off();
		GrountSound.Off();
		GetWorld()->SpawnActor<APhaseChangeBack>("PhaseChangeBack");
		State.ChangeState("Boss2PhaseChange");
		return;
	});

	PlayerCollision->CollisionEnter(ECollisionOrder::Devil1Change, [=](std::shared_ptr<UCollision> _Collison)
	{

		AActor* Ptr = _Collison->GetActor();
		ADevil1* Monster = dynamic_cast<ADevil1*>(Ptr);
		Monster->SetDieTime(3.0f);

	});
}

void APlay_Cuphead::createBullet()
{


	if (BulletDir.iX() == 0)
	{
		return;
	}

	NewBullet = GetWorld()->SpawnActor<ABaseBullet>("BaseBullet");

	if (NewBullet == nullptr)
	{
		return;
	}

	switch (ShootStyle)
	{
	case EShootDir::None:
		break;
	case EShootDir::IdleShoot:
		IdleShoot();
		break;
	case EShootDir::RunShoot:
		RunShoot();
		break;
	case EShootDir::UpShoot:
		UpShoot();
		break;
	case EShootDir::DownShoot:
		DownShoot();
		break;
	case EShootDir::DuckShoot:
		DuckShoot();
		break;
	case EShootDir::DiagonalDownShoot:
		DiagonalDownShoot();
		break;
	case EShootDir::DiagonalUpShoot:
		DiagonalUpShoot();
		break;
	case EShootDir::DiagonalUpShootCB:
		DiagonalUpShootCB();
		break;
	default:
		break;
	}
	
	NewBullet->SetBulletDir(BulletDir);
}

void APlay_Cuphead::IdleShoot()
{

	if (BulletDir.iX() == 1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + bulletY2,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY2,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::RunShoot()
{
	if (BulletDir.iX() == 1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y-RunShootYpos + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y - RunShootYpos + bulletY2,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - RunShootYpos + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - RunShootYpos + bulletY2,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::DuckShoot()
{
	if (BulletDir.iX() == 1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y - DuckShootYpos + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y - DuckShootYpos + bulletY2,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - DuckShootYpos + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - DuckShootYpos + bulletY2,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::DiagonalUpShoot()
{
	if (BulletDir.iX() == 1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,45.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y  + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y  + bulletY2,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,-45.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY1,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY2,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::UpShoot()
{
	BulletDir = FVector::Up;

	NewBullet->SetActorRotation({ 0.0f,0.0f,90.0f });
	switch (Dir)
	{
	case EDir::None:
		break;
	case EDir::Left:
		if (BulletDir.iY() == 1)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - 80.0f + shootXpos,GetActorLocation().Y + 100.0f,0.0f });
			if (false == shootY)
			{
				shootY = true;
			}
			else {
				shootY = false;
			}
		}
		break;
	case EDir::Right:
		if (BulletDir.iY() == 1)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - 35.0f + shootXpos,GetActorLocation().Y + 100.0f,0.0f });
			if (false == shootY)
			{
				shootY = true;
			}
			else {

				shootY = false;
			}
		}
		break;
	default:
		break;
	}
}

void APlay_Cuphead::DiagonalUpShootCB()
{
	if (BulletDir.iX() == 1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,45.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + bulletY1+10.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + bulletY2 + 10.0f,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,-45.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY1 + 10.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY2 + 10.0f,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::DownShoot()
{
	BulletDir = FVector::Down;

	NewBullet->SetActorRotation({ 0.0f,0.0f,-90.0f });
	switch (Dir)
	{
	case EDir::None:
		break;
	case EDir::Left:
		if (BulletDir.iY() == -1)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - 95.0f + shootXpos,GetActorLocation().Y,0.0f });
			if (false == shootY)
			{
				shootY = true;
			}
			else {
				shootY = false;
			}
		}
		break;
	case EDir::Right:
		if (BulletDir.iY() == -1)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - 35.0f + shootXpos,GetActorLocation().Y,0.0f });
			if (false == shootY)
			{
				shootY = true;
			}
			else {

				shootY = false;
			}
		}
		break;
	default:
		break;
	}
}

void APlay_Cuphead::DiagonalDownShoot()
{

	if (BulletDir.iX() == 1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,315.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + 35.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y  + 25.0f,0.0f });
			shootY = false;
		}
	}
	else if (BulletDir.iX() == -1)
	{
		NewBullet->SetActorRotation({ 0.0f,0.0f,-315.0f });
		if (false == shootY)
		{
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + 35.0f,0.0f });
			shootY = true;
		}
		else {
			NewBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + 25.0f,0.0f });
			shootY = false;

		}
	}
}

void APlay_Cuphead::SSIdleShoot()
{
	if (BulletDir.iX() == 1)
	{
		NewSSBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + bulletY2,0.0f });
	}
	else if (BulletDir.iX() == -1)
	{
		NewSSBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY2,0.0f });
	}
}

void APlay_Cuphead::SSDownShoot()
{
	BulletDir = FVector::Down;

	NewSSBullet->SetActorRotation({ 0.0f,0.0f,-90.0f });
	
	switch (Dir)
	{
	case EDir::None:
		break;
	case EDir::Left:
		if (BulletDir.iY() == -1)
		{
			
			NewSSBullet->SetActorLocation({ GetActorLocation().X - 80.0f + shootXpos,GetActorLocation().Y,0.0f });
		}
		break;
	case EDir::Right:
		if (BulletDir.iY() == -1)
		{
			
			NewSSBullet->SetActorLocation({ GetActorLocation().X - 35.0f + shootXpos,GetActorLocation().Y,0.0f });
		}
		break;
	default:
		break;
	}
}

void APlay_Cuphead::SSDiagonalUpShoot()
{
	if (BulletDir.iX() == 1)
	{
		NewSSBullet->SetActorRotation({ 0.0f,0.0f,45.0f });
		NewSSBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y + bulletY2,0.0f });
	}
	else if (BulletDir.iX() == -1)
	{
		NewSSBullet->SetActorRotation({ 0.0f,0.0f,-45.0f });
		NewSSBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y + bulletY2,0.0f });
	}
}

void APlay_Cuphead::SSDiagonalDownShoot()
{
	if (BulletDir.iX() == 1)
	{
		NewSSBullet->SetActorRotation({ 0.0f,0.0f,315.0f }   );
		NewSSBullet->SetActorLocation({ GetActorLocation().X + shootXpos,GetActorLocation().Y - 15.0f,0.0f });
	}
	else if (BulletDir.iX() == -1)
	{
		NewSSBullet->SetActorRotation({ 0.0f,0.0f,-315.0f });
		NewSSBullet->SetActorLocation({ GetActorLocation().X - shootXpos,GetActorLocation().Y - 15.0f,0.0f });
	}
}

void APlay_Cuphead::SSUpShoot()
{
	BulletDir = FVector::Up;

	NewSSBullet->SetActorRotation({ 0.0f,0.0f,90.0f });
	switch (Dir)
	{
	case EDir::None:
		break;
	case EDir::Left:
		if (BulletDir.iY() == 1)
		{
			NewSSBullet->SetActorLocation({ GetActorLocation().X - 80.0f + shootXpos,GetActorLocation().Y + 100.0f,0.0f });
		}
		break;
	case EDir::Right:
		if (BulletDir.iY() == 1)
		{
			NewSSBullet->SetActorLocation({ GetActorLocation().X - 35.0f + shootXpos,GetActorLocation().Y + 100.0f,0.0f });
		}
		break;
	default:
		break;
	}
}


void APlay_Cuphead::createSSBullet()
{

	NewSSBullet = GetWorld()->SpawnActor<ABaseSSBullet>("BaseSSBullet");

	if (NewSSBullet == nullptr)
	{
		return;
	}

	switch (ShootStyle)
	{
	case EShootDir::None:
		break;
	case EShootDir::IdleShoot:
		SSIdleShoot();
		break;
	case EShootDir::UpShoot:
		SSUpShoot();
		break;
	case EShootDir::DownShoot:
		SSDownShoot();
		break;
	case EShootDir::DiagonalUpShoot:
		SSDiagonalUpShoot();
		break;
	case EShootDir::DiagonalDownShoot:
		SSDiagonalDownShoot();
		break;
	default:
		break;
	}

	NewSSBullet->SetBulletDir(BulletDir);
}

void APlay_Cuphead::CalHp(float _DeltaTime)
{
	if (Hp == 2)
	{
		HpBar->SetSprite("HP2.png");
	}
	else if (Hp == 1)
	{
		Hp1Time -= _DeltaTime;

		if (Hp1Time < 0)
		{
			if (false == Hp1OnOff)
			{
				HpBar->SetSprite("HP1.png");
				Hp1OnOff = true;
			}
			else
			{
				HpBar->SetSprite("HP1Warn.png");
				Hp1OnOff = false;
			}
			Hp1Time = 0.55f;
		}
	}
	else if (Hp <= 0)
	{
		HpBar->SetSprite("HPDead.png");
	}
}

void APlay_Cuphead::CalGuage()
{
	if (CurGuageCount == 5)
	{
		return;
	}

	Guageint[CurGuageCount] += (GuageGet+ overGuageGet);
	overGuageGet = 0;
	if (Guageint[CurGuageCount] > 100)
	{
		overGuageGet = Guageint[CurGuageCount] - 100;
		Guageint[CurGuageCount] = 100;
	}

	if (Guageint[CurGuageCount] == 100)
	{
		Guage[CurGuageCount]->SetSprite("SuperMeterCard.png");
		PrevGuageCount = CurGuageCount;
		++CurGuageCount;
	}
	else if (Guageint[CurGuageCount] <= 90 && Guageint[CurGuageCount] > 80)
	{
		Guage[CurGuageCount]->SetActive(true);
		Guage[CurGuageCount]->SetSprite("Super6.png");
	}
	else if (Guageint[CurGuageCount] <= 80 && Guageint[CurGuageCount] > 60)
	{
		Guage[CurGuageCount]->SetActive(true);
		Guage[CurGuageCount]->SetSprite("Super5.png");
	}
	else if (Guageint[CurGuageCount] <= 60 && Guageint[CurGuageCount] > 50)
	{
		Guage[CurGuageCount]->SetActive(true);
		Guage[CurGuageCount]->SetSprite("Super4.png");
	}
	else if (Guageint[CurGuageCount] <= 50 && Guageint[CurGuageCount] > 40)
	{
		Guage[CurGuageCount]->SetActive(true);
		Guage[CurGuageCount]->SetSprite("Super3.png");
	}
	else if (Guageint[CurGuageCount] <= 40 && Guageint[CurGuageCount] > 5)
	{
		Guage[CurGuageCount]->SetActive(true);
		Guage[CurGuageCount]->SetSprite("Super2.png");
	}
	else if (Guageint[CurGuageCount] <= 5 && Guageint[CurGuageCount] > 0)
	{
		Guage[CurGuageCount]->SetActive(true);
		Guage[CurGuageCount]->SetSprite("Super1.png");
	}
	GuageGet = 0;
}

void APlay_Cuphead::UseSSBullet()
{
	if (CurGuageCount < 5)
	{
		if (Guageint[CurGuageCount] > 0 && Guageint[CurGuageCount] < 100)
		{
			Guage[CurGuageCount]->SetActive(false);
			Guageint[PrevGuageCount] = Guageint[CurGuageCount];
			Guageint[CurGuageCount] = 0;
			--CurGuageCount;
			--PrevGuageCount;

			if (PrevGuageCount < 0)
			{
				PrevGuageCount = 0;
			}
			//CalGuage();
			return;
		}
	}
	

	Guage[PrevGuageCount]->SetActive(false);
	Guageint[PrevGuageCount] = 0;
	

	--PrevGuageCount;
	--CurGuageCount;

	
	if (PrevGuageCount < 0)
	{
		PrevGuageCount = 0;
		return;
	}
	
}

void APlay_Cuphead::SSBulletBehavir()
{
	UseSSBullet();
	GrountSound.Off();
	BaseBulletSound.Off();
	UEngineSound::SoundPlay("sfx_player_plane_shmup_bomb_explode_01.wav");
	BulletStart->SetActive(false);
}


void APlay_Cuphead::CalGravityVector(float _DeltaTime)
{
	GravityVector += (FVector::Down * Gravity * _DeltaTime); // 중력은 계속 가해진다.

	if (true == Devil2GrounCheck && GetActorLocation().iY() <= -270)
	{
		GravityVector = FVector::Zero;
		AddActorLocation(FVector::Up * 200.0f);
		State.ChangeState("hit");
		return;
	}

	if (GetActorLocation().iY() <= GrounYCheck || true==NoGravity)
	{
		GravityVector = FVector::Zero;
	}

	GroundCollision->CollisionEnter(ECollisionOrder::Boss1Top, [=](std::shared_ptr<UCollision> _Collison)
	{
		GravityVector = FVector::Zero;

		AddActorLocation(FVector::Up * 3.0f);
	});

	GroundCollision->CollisionStay(ECollisionOrder::Boss1Top, [=](std::shared_ptr<UCollision> _Collison)
	{
		GravityVector = FVector::Zero;
		CollisionMove.X += (-450.0f * _DeltaTime);
	});

	GroundCollision->CollisionEnter(ECollisionOrder::Boss2Object1, [=](std::shared_ptr<UCollision> _Collison)
	{
		GravityVector = FVector::Zero;
		AddActorLocation(FVector::Up * 3.0f);
	});

	GroundCollision->CollisionStay(ECollisionOrder::Boss2Object1, [=](std::shared_ptr<UCollision> _Collison)
	{
		GravityVector = FVector::Zero;
	});
}

void APlay_Cuphead::CalLastMoveVector(float _DeltaTime, const FVector& _MovePos)
{
	PlayerMoveY = FVector::Zero;

	PlayerMoveY += JumpVector;
	PlayerMoveY += GravityVector;

	FVector CheckPos = GetActorLocation(); // Kirby

	
	FVector MovePos = _MovePos;
	

	switch (Dir)
	{
	case EDir::Left:
		CheckPos.X -= 30.0f;
		break;
	case EDir::Right:
		CheckPos.X += 30.0f;
		
		break;
	default:
		break;
	}

	if (CheckPos.iX() <= -590 || CheckPos.iX() >= 590) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		CollisionMove = FVector::Zero;
	}

	if (CheckPos.iX()<=-600 || CheckPos.iX()>=600) // 벽(Red)랑 충돌인 경우 -> 움직이는 값 0
	{
		MovePos = FVector::Zero;
	}

	AddActorLocation(MovePos + (PlayerMoveY * _DeltaTime)+ CollisionMove);
	GetWorld()->GetMainCamera()->AddActorLocation((MovePos* _DeltaTime*10.0f));

	if (CollisionMove.iX() != 0)
	{
		GetWorld()->GetMainCamera()->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));
	}

	CollisionMove = FVector::Zero;
}

void APlay_Cuphead::GroupUp(float _DeltaTime)
{
	if (true == Devil2GrounCheck)
	{
		return;
	}


	GroundCollision->CollisionStay(ECollisionOrder::Boss1Top, [=](std::shared_ptr<UCollision> _Collison)
	{
		AddActorLocation(FVector::Up * _DeltaTime);
	});

	GroundCollision->CollisionStay(ECollisionOrder::Boss2Object1, [=](std::shared_ptr<UCollision> _Collison)
	{
		AddActorLocation(FVector::Up * _DeltaTime);
	});

	while (true)
	{
		if (GetActorLocation().iY() < GrounYCheck)
		{
			AddActorLocation(FVector::Up * 2.0f * _DeltaTime);
		}
		else
		{
			break;
		}
	}
}

// 콜리전으로 충돌 하기
void APlay_Cuphead::StateInit()
{
	// 스테이트 만들고
	//State.CreateState("Die");
	State.CreateState("Intro");
	State.CreateState("Idle");
	State.CreateState("Run");
	State.CreateState("Dash");
	State.CreateState("AirDash");
	State.CreateState("Duck");
	State.CreateState("Shoot_Straight");
	State.CreateState("Run_Shoot_Straight");
	State.CreateState("Run_Shoot_DiagonalUp");
	State.CreateState("Duck_Shoot");
	State.CreateState("Aim_Up");
	State.CreateState("Shoot_Up");
	State.CreateState("Jump");
	State.CreateState("JumpShoot");
	State.CreateState("DashAfterJump");
	State.CreateState("hit");
	State.CreateState("Parry");
	State.CreateState("Aim_Straight");
	State.CreateState("Aim_DiagonalDown");
	State.CreateState("Aim_Down");
	State.CreateState("Aim_DiagonalUp");
	State.CreateState("Aim_Up2");

	State.CreateState("Shoot_StraightCB");
	State.CreateState("Shoot_DiagonalDown");
	State.CreateState("Shoot_DiagonalUp");
	State.CreateState("Shoot_Down");
	State.CreateState("Shoot_UpCB");

	State.CreateState("Boss2PhaseChange");
	State.CreateState("Scared");

	State.CreateState("SSGround_Straight");
	State.CreateState("SSGround_Down");
	State.CreateState("SSGround_DiagonalUp");
	State.CreateState("SSGround_DiagonalDown");
	State.CreateState("SSGround_Up");

	State.CreateState("Air_SSGround_Straight");
	State.CreateState("Air_SSGround_Down");
	State.CreateState("Air_SSGround_DiagonalUp");
	State.CreateState("Air_SSGround_DiagonalDown");
	State.CreateState("Air_SSGround_Up");
	
	State.SetUpdateFunction("Intro", std::bind(&APlay_Cuphead::Intro, this, std::placeholders::_1));
	State.SetStartFunction("Intro", [=] {PlayCuphead->ChangeAnimation("Intro"); });

	State.SetUpdateFunction("Idle", std::bind(&APlay_Cuphead::Idle, this, std::placeholders::_1));
	State.SetStartFunction("Idle", [=] {PlayCuphead->ChangeAnimation("Idle"); });

	State.SetUpdateFunction("Run", std::bind(&APlay_Cuphead::Run, this, std::placeholders::_1));
	State.SetStartFunction("Run", [=] {PlayCuphead->ChangeAnimation("Run"); });

	State.SetUpdateFunction("Dash", std::bind(&APlay_Cuphead::Dash, this, std::placeholders::_1));
	State.SetStartFunction("Dash", [=] {PlayCuphead->ChangeAnimation("Dash"); });

	State.SetUpdateFunction("AirDash", std::bind(&APlay_Cuphead::AirDash, this, std::placeholders::_1));
	State.SetStartFunction("AirDash", [=] {PlayCuphead->ChangeAnimation("Dash"); });

	State.SetUpdateFunction("Duck", std::bind(&APlay_Cuphead::Duck, this, std::placeholders::_1));
	State.SetStartFunction("Duck", [=] {PlayCuphead->ChangeAnimation("Duck"); });

	State.SetUpdateFunction("Shoot_Straight", std::bind(&APlay_Cuphead::Shoot_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_Straight", [=] {PlayCuphead->ChangeAnimation("Shoot_Straight"); });

	State.SetUpdateFunction("Run_Shoot_Straight", std::bind(&APlay_Cuphead::Run_Shoot_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Run_Shoot_Straight", [=] {PlayCuphead->ChangeAnimation("Run_Shoot_Straight"); });

	State.SetUpdateFunction("Run_Shoot_DiagonalUp", std::bind(&APlay_Cuphead::Run_Shoot_DiagonalUp, this, std::placeholders::_1));
	State.SetStartFunction("Run_Shoot_DiagonalUp", [=] {PlayCuphead->ChangeAnimation("Run_Shoot_DiagonalUp"); });

	State.SetUpdateFunction("Duck_Shoot", std::bind(&APlay_Cuphead::Duck_Shoot, this, std::placeholders::_1));
	State.SetStartFunction("Duck_Shoot", [=] {PlayCuphead->ChangeAnimation("Duck_Shoot"); });

	State.SetUpdateFunction("Aim_Up", std::bind(&APlay_Cuphead::Aim_Up, this, std::placeholders::_1));
	State.SetStartFunction("Aim_Up", [=] {PlayCuphead->ChangeAnimation("Aim_Up"); });

	State.SetUpdateFunction("Shoot_Up", std::bind(&APlay_Cuphead::Shoot_Up, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_Up", [=] {PlayCuphead->ChangeAnimation("Shoot_Up"); });

	State.SetUpdateFunction("Jump", std::bind(&APlay_Cuphead::Jump, this, std::placeholders::_1));
	State.SetStartFunction("Jump", [=] {PlayCuphead->ChangeAnimation("Jump"); });

	State.SetUpdateFunction("JumpShoot", std::bind(&APlay_Cuphead::JumpShoot, this, std::placeholders::_1));
	State.SetStartFunction("JumpShoot", [=] {PlayCuphead->ChangeAnimation("Jump"); });

	State.SetUpdateFunction("DashAfterJump", std::bind(&APlay_Cuphead::DashAfterJump, this, std::placeholders::_1));
	State.SetStartFunction("DashAfterJump", [=] {PlayCuphead->ChangeAnimation("Jump"); });

	State.SetUpdateFunction("hit", std::bind(&APlay_Cuphead::hit, this, std::placeholders::_1));
	State.SetStartFunction("hit", [=] {PlayCuphead->ChangeAnimation("hit"); });


	State.SetUpdateFunction("Parry", std::bind(&APlay_Cuphead::Parry, this, std::placeholders::_1));
	State.SetStartFunction("Parry", [=] {PlayCuphead->ChangeAnimation("Parry"); });

	State.SetUpdateFunction("Aim_Straight", std::bind(&APlay_Cuphead::Aim_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Aim_Straight", [=] {PlayCuphead->ChangeAnimation("Aim_Straight"); });

	State.SetUpdateFunction("Aim_DiagonalDown", std::bind(&APlay_Cuphead::Aim_DiagonalDown, this, std::placeholders::_1));
	State.SetStartFunction("Aim_DiagonalDown", [=] {PlayCuphead->ChangeAnimation("Aim_DiagonalDown"); });

	State.SetUpdateFunction("Aim_Down", std::bind(&APlay_Cuphead::Aim_Down, this, std::placeholders::_1));
	State.SetStartFunction("Aim_Down", [=] {PlayCuphead->ChangeAnimation("Aim_Down"); });

	State.SetUpdateFunction("Aim_DiagonalUp", std::bind(&APlay_Cuphead::Aim_DiagonalUp, this, std::placeholders::_1));
	State.SetStartFunction("Aim_DiagonalUp", [=] {PlayCuphead->ChangeAnimation("Aim_DiagonalUp"); });

	State.SetUpdateFunction("Aim_Up2", std::bind(&APlay_Cuphead::Aim_Up2, this, std::placeholders::_1));
	State.SetStartFunction("Aim_Up2", [=] {PlayCuphead->ChangeAnimation("Aim_Up"); });

	State.SetUpdateFunction("Boss2PhaseChange", std::bind(&APlay_Cuphead::Boss2PhaseChange, this, std::placeholders::_1));
	State.SetStartFunction("Boss2PhaseChange", [=] {PlayCuphead->ChangeAnimation("Jump"); });

	State.SetUpdateFunction("Scared", std::bind(&APlay_Cuphead::Scared, this, std::placeholders::_1));
	State.SetStartFunction("Scared", [=] {PlayCuphead->ChangeAnimation("Scared"); });

	State.SetUpdateFunction("Shoot_StraightCB", std::bind(&APlay_Cuphead::Shoot_StraightCB, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_StraightCB", [=] {PlayCuphead->ChangeAnimation("Shoot_Straight"); });

	State.SetUpdateFunction("Shoot_DiagonalDown", std::bind(&APlay_Cuphead::Shoot_DiagonalDown, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_DiagonalDown", [=] {PlayCuphead->ChangeAnimation("Shoot_DiagonalDown"); });

	State.SetUpdateFunction("Shoot_DiagonalUp", std::bind(&APlay_Cuphead::Shoot_DiagonalUp, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_DiagonalUp", [=] {PlayCuphead->ChangeAnimation("Shoot_DiagonalUp"); });

	State.SetUpdateFunction("Shoot_Down", std::bind(&APlay_Cuphead::Shoot_Down, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_Down", [=] {PlayCuphead->ChangeAnimation("Shoot_Down"); });

	State.SetUpdateFunction("Shoot_UpCB", std::bind(&APlay_Cuphead::Shoot_UpCB, this, std::placeholders::_1));
	State.SetStartFunction("Shoot_UpCB", [=] {PlayCuphead->ChangeAnimation("Shoot_Up"); });

	State.SetUpdateFunction("SSGround_Straight", std::bind(&APlay_Cuphead::SSGround_Straight, this, std::placeholders::_1));
	State.SetStartFunction("SSGround_Straight", [=] {PlayCuphead->ChangeAnimation("SSGround_Straight"); });

	State.SetUpdateFunction("SSGround_Down", std::bind(&APlay_Cuphead::SSGround_Down, this, std::placeholders::_1));
	State.SetStartFunction("SSGround_Down", [=] {PlayCuphead->ChangeAnimation("SSGround_Down"); });

	State.SetUpdateFunction("SSGround_DiagonalUp", std::bind(&APlay_Cuphead::SSGround_DiagonalUp, this, std::placeholders::_1));
	State.SetStartFunction("SSGround_DiagonalUp", [=] {PlayCuphead->ChangeAnimation("SSGround_DiagonalUp"); });

	State.SetUpdateFunction("SSGround_DiagonalDown", std::bind(&APlay_Cuphead::SSGround_DiagonalDown, this, std::placeholders::_1));
	State.SetStartFunction("SSGround_DiagonalDown", [=] {PlayCuphead->ChangeAnimation("SSGround_DiagonalDown"); });

	State.SetUpdateFunction("SSGround_Up", std::bind(&APlay_Cuphead::SSGround_Up, this, std::placeholders::_1));
	State.SetStartFunction("SSGround_Up", [=] {PlayCuphead->ChangeAnimation("SSGround_Up"); });

	State.SetUpdateFunction("Air_SSGround_Up", std::bind(&APlay_Cuphead::Air_SSGround_Up, this, std::placeholders::_1));
	State.SetStartFunction("Air_SSGround_Up", [=] {PlayCuphead->ChangeAnimation("SSGround_Up"); });
							 
	State.SetUpdateFunction("Air_SSGround_Straight", std::bind(&APlay_Cuphead::Air_SSGround_Straight, this, std::placeholders::_1));
	State.SetStartFunction("Air_SSGround_Straight", [=] {PlayCuphead->ChangeAnimation("SSGround_Straight"); });
							 
	State.SetUpdateFunction("Air_SSGround_Down", std::bind(&APlay_Cuphead::Air_SSGround_Down, this, std::placeholders::_1));
	State.SetStartFunction("Air_SSGround_Down", [=] {PlayCuphead->ChangeAnimation("SSGround_Down"); });
	//						
	State.SetUpdateFunction("Air_SSGround_DiagonalUp", std::bind(&APlay_Cuphead::Air_SSGround_DiagonalUp, this, std::placeholders::_1));
	State.SetStartFunction("Air_SSGround_DiagonalUp", [=] {PlayCuphead->ChangeAnimation("SSGround_DiagonalUp"); });
	//						
	State.SetUpdateFunction("Air_SSGround_DiagonalDown", std::bind(&APlay_Cuphead::Air_SSGround_DiagonalDown, this, std::placeholders::_1));
	State.SetStartFunction("Air_SSGround_DiagonalDown", [=] {PlayCuphead->ChangeAnimation("SSGround_DiagonalDown"); });
	//					
	//State.SetUpdateFunction("Air_SSGround_Up", std::bind(&APlay_Cuphead::SSGround_Up, this, std::placeholders::_1));
	//State.SetStartFunction("Air_SSGround_Up", [=] {PlayCuphead->ChangeAnimation("SSGround_Up"); });
	//State.SetUpdateFunction("Run", std::bind(&AWorldPlayer::Run, this, std::placeholders::_1));

	//State.SetStartFunction("Run", std::bind(&AWorldPlayer::RunStart, this));


	// 즉석 함수
	// = [ 람다캡쳐 Renderer]
	// {
	//    함수 내용
	// }

	// 람다캡처의 내용안에 =을 쓰면
	// 현재 스택에서 사용가능한 복사본을 만든다.
	// 메모리를 할당해서 Renderer를 같은 이름으로 복사한다.


	// 체인지
	UEngineSound::SoundPlay("sfx_player_intro_cuphead.wav");
	State.ChangeState("Intro");
}

void APlay_Cuphead::Intro(float _DeltaTime)
{
	DirCheck();
	GrountSound.Off();
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::DirCheck()
{

	if (true==IsPress(VK_LEFT))
	{
		PlayCuphead->SetDir(EEngineDir::Left);
		Dir = EDir::Left;
	}
	if (true==IsPress(VK_RIGHT))
	{
		PlayCuphead->SetDir(EEngineDir::Right);
		Dir = EDir::Right;
	}

	if (true == BulletStart->IsActive())
	{
		switch (Dir)
		{
		case EDir::Left:

			BulletDir = FVector::Left;

			switch (ShootStyle)
			{
			case EShootDir::None:
				break;
			case EShootDir::IdleShoot:
				BulletStart->SetPosition({ -70.0f,80.0f,0.0f });
				break;
			case EShootDir::RunShoot:
				BulletStart->SetPosition({ -65.0f,70.0f,0.0f });
				break;
			case EShootDir::UpShoot:
				BulletStart->SetPosition({ -30.0f,155.0f,0.0f });
				break;
			case EShootDir::DownShoot:
				BulletStart->SetPosition({ -30.0f,0.0f,0.0f });
				break;
			case EShootDir::DuckShoot:
				BulletStart->SetPosition({ -75.0f,40.0f,0.0f });
				break;
			case EShootDir::DiagonalDownShoot:
				BulletDir += FVector::Down;
				BulletStart->SetPosition({ -60.0f,30.0f,0.0f });
				break;
			case EShootDir::DiagonalUpShoot:
				BulletDir += FVector::Up;
				BulletStart->SetPosition({ -60.0f,120.0f,0.0f });
				break;
			case EShootDir::DiagonalUpShootCB:
				BulletDir += FVector::Up;
				BulletStart->SetPosition({ -60.0f,120.0f,0.0f });
				break;
			default:
				break;
			}
			break;
		case EDir::Right:
			BulletDir = FVector::Right;
			switch (ShootStyle)
			{
			case EShootDir::None:
				break;
			case EShootDir::IdleShoot:
				BulletStart->SetPosition({ 70.0f,80.0f,0.0f });
				break;
			case EShootDir::RunShoot:
				BulletStart->SetPosition({ 65.0f,70.0f,0.0f });
				break;
			case EShootDir::UpShoot:
				BulletStart->SetPosition({ 30.0f,155.0f,0.0f });
				break;
			case EShootDir::DownShoot:
				BulletStart->SetPosition({ 30.0f,0.0f,0.0f });
				break;
			case EShootDir::DuckShoot:
				BulletStart->SetPosition({70.0f,40.0f,0.0f });
				break;
			case EShootDir::DiagonalDownShoot:
				BulletDir += FVector::Down;
				BulletStart->SetPosition({ 60.0f,30.0f,0.0f });
				break;
			case EShootDir::DiagonalUpShoot:
				BulletDir += FVector::Up;
				BulletStart->SetPosition({ 60.0f,120.0f,0.0f });
				break;
			case EShootDir::DiagonalUpShootCB:
				BulletDir += FVector::Up;
				BulletStart->SetPosition({ 60.0f,120.0f,0.0f });
				break;
			default:
				break;
			}
			break;
		case EDir::Up:
			break;
		case EDir::Down:
			break;
		default:
			break;
		}
	}
	else
	{
		switch (Dir)
		{
		case EDir::None:
			break;
		case EDir::Left:
			BulletDir = FVector::Left;
			switch (ShootStyle)
			{
			case EShootDir::IdleShoot:
				BulletDir = FVector::Left;
				break;
			case EShootDir::DiagonalUpShoot:
				BulletDir += FVector::Up;
				break;
			case EShootDir::DiagonalDownShoot:
				BulletDir += FVector::Down;
				break;
			case EShootDir::UpShoot:
				BulletDir = FVector::Up;
				break;
			case EShootDir::DownShoot:
				BulletDir = FVector::Down;
				break;
			default:
				break;
			}
			break;
		case EDir::Right:
			BulletDir = FVector::Right;
			switch (ShootStyle)
			{
			case EShootDir::IdleShoot:
				BulletDir = FVector::Right;
				break;
			case EShootDir::DiagonalUpShoot:
				BulletDir += FVector::Up;
				break;
			case EShootDir::DiagonalDownShoot:
				BulletDir += FVector::Down;
				break;
			case EShootDir::UpShoot:
				BulletDir = FVector::Up;
				break;
			case EShootDir::DownShoot:
				BulletDir = FVector::Down;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}


}

void APlay_Cuphead::MoveUpDate(float _DeltaTime,const FVector& _MovePos)
{
	//std::shared_ptr<UEngineTexture> Tex = UContentsHelper::MapTex;

//#ifdef _DEBUG
	//if (nullptr == Tex)
	//{
		//MsgBoxAssert("이미지 충돌체크중 이미지가 존재하지 않습니다.");
	//}
//#endif
	CalGravityVector(_DeltaTime);
	CalLastMoveVector(_DeltaTime, _MovePos);
	GroupUp(_DeltaTime);
	// 방향 별 픽셀 충돌 인식 범위
	//float4 Pos = GetActorLocation();
	//Pos.Y = -Pos.Y;


	//Color8Bit Color = Tex->GetColor(Pos.iX(), Pos.iY(), Color8Bit::Black);

	//if (Color == Color8Bit::Black)
	//{
		//GravityVector = FVector::Zero; // 중력의 힘은 0으로
	//}

	//AddActorLocation(PlayerMove + GravityVector+(JumpVector* _DeltaTime));

}

void APlay_Cuphead::DebugMessageFunction()
{
	{
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	{
		std::string Msg = std::format("MousePos : {}\n", GEngine->EngineWindow.GetScreenMousePos().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

}


void APlay_Cuphead::Idle(float _DeltaTime)
{

	DirCheck();
	GrountSound.Off();
	BulletStart->SetActive(false);
	if (true == IsDown('1'))
	{
		if (100 == ABoss1Common::GetHp())
		{
			ABoss1Common::SetHp(80);
		}
		else if (80 == ABoss1Common::GetHp())
		{
			ABoss1Common::SetHp(50);
		}
		return;
	}

	if (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT))
	{
		State.ChangeState("Run");
		return;
	}
	
	if (true == IsDown(VK_SHIFT))
	{

		UEngineSound::SoundPlay("sfx_player_dash_01.wav");
		GetWorld()->SpawnActor<ADashDust>("DashDust")->SetDushDir(BulletDir);
		State.ChangeState("Dash");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		PlayerCollision->SetScale(FVector(70.0f, 50.0f, 100.0f));
		PlayerCollision->SetPosition(FVector(0.0f, 30.0f, 0.0f));
		State.ChangeState("Duck");
		return;
	}

	if (true == IsPress('C'))
	{
		State.ChangeState("Aim_Straight");
		return;
	}

	if (true == IsDown('Z') && true == IsPress('X') && true == IsPress(VK_UP))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::UpShoot;
		BulletStart->SetActive(true);
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsDown('Z') && true == IsPress('X'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsDown('X'))
	{
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_Straight");
		return;
	}

	if (true == IsDown('V') && 100==Guageint[PrevGuageCount])
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("SSGround_Straight");
		return;
	}

	if (true == IsDown(VK_UP))
	{
		State.ChangeState("Aim_Up");
		return;
	}

	if (true == IsDown('Z'))
	{
		UEngineSound::SoundPlay("sfx_player_jump_01.wav");
		JumpVector = JumpPowerPress;
		State.ChangeState("Jump");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Run(float  _DeltaTime)
{
	DirCheck();
	GrountSound.On();
	if (true == IsDown('V') && true == IsPress(VK_UP) && 100 == Guageint[PrevGuageCount]
		)
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::DiagonalUpShoot;
		State.ChangeState("SSGround_DiagonalUp");
		return;
	}

	if (true == IsDown('V') && true == IsPress(VK_DOWN) && 100 == Guageint[PrevGuageCount])
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::DiagonalDownShoot;
		State.ChangeState("SSGround_DiagonalDown");
		return;
	}

	if (true == IsDown('V') && 100 == Guageint[PrevGuageCount])
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("SSGround_Straight");
		return;
	}

	DustTime -= _DeltaTime;
	
	if(DustTime<0)
	{
		GetWorld()->SpawnActor<ARunDust>("RunDust");
		DustTime = 0.45f;
	}
	

	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		GrountSound.Off();
		State.ChangeState("Idle");
		return;
	}

	if (true == IsDown(VK_SHIFT))
	{
		GrountSound.Off();
		UEngineSound::SoundPlay("sfx_player_dash_01.wav");
		GetWorld()->SpawnActor<ADashDust>("DashDust")->SetDushDir(BulletDir);
		State.ChangeState("Dash");
		return;
	}


	if (true == IsDown('Z') && true == IsPress('X'))
	{
		GrountSound.Off();
		//BulletStart->SetActive(false);
		UEngineSound::SoundPlay("sfx_player_jump_01.wav");
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::RunShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsDown('Z'))
	{
		GrountSound.Off();
		UEngineSound::SoundPlay("sfx_player_jump_01.wav");
		JumpVector = JumpPowerPress;
		State.ChangeState("Jump");
		return;
	}


	if (true == IsPress(VK_LEFT))
	{
		MovePos+=FVector::Left * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * Speed;
	}

	EventCollision(_DeltaTime);
	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Run_Shoot_Straight(float  _DeltaTime)
{
	DirCheck();
	GrountSound.On();
	DustTime -= _DeltaTime;

	if (DustTime < 0)
	{
		GetWorld()->SpawnActor<ARunDust>("RunDust");
		DustTime = 0.45f;
	}

	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT) && true == IsFree('X'))
	{
		GrountSound.Off();
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Idle");
		return;
	}

	if (true == IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_UP))
	{
		ShootStyle = EShootDir::DiagonalUpShoot;
		State.ChangeState("Run_Shoot_DiagonalUp");
		return;
	}

	if (true == IsDown('V') && 100 == Guageint[PrevGuageCount])
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("SSGround_Straight");
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Run");
		return;
	}

	if (true == IsDown('Z'))
	{
		GrountSound.Off();
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		GrountSound.Off();
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_Straight");
		return;
	}
	EventCollision(_DeltaTime);
	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Run_Shoot_DiagonalUp(float _DeltaTime)
{
	DirCheck();
	GrountSound.On();
	DustTime -= _DeltaTime;

	if (DustTime < 0)
	{
		GetWorld()->SpawnActor<ARunDust>("RunDust");
		DustTime = 0.45f;
	}

	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsDown('V') && 100 == Guageint[PrevGuageCount]
		)
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::DiagonalUpShoot;
		State.ChangeState("SSGround_DiagonalUp");
		return;
	}

	FVector MovePos = FVector::Zero;
	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT) && true == IsFree('X'))
	{
		GrountSound.Off();
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Idle");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT) && true == IsPress(VK_UP))
	{
		GrountSound.Off();
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Aim_Up");
		return;
	}


	if (true == IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * _DeltaTime * Speed;
	}

	if (true == IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * _DeltaTime * Speed;
	}

	if (true == IsFree(VK_UP))
	{
		ShootStyle = EShootDir::RunShoot;
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Run");
		return;
	}

	if (true == IsDown('Z'))
	{
		GrountSound.Off();
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsFree(VK_LEFT) && true == IsFree(VK_RIGHT))
	{
		GrountSound.Off();
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_Straight");
		return;
	}
	EventCollision(_DeltaTime);
	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Dash(float _DeltaTime)
{
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}

	FVector MovePos;

	switch (Dir)
	{
	case EDir::Left:
		MovePos += FVector::Left * _DeltaTime * DashSpeed;
		break;
	case EDir::Right:
		MovePos += FVector::Right * _DeltaTime * DashSpeed;
		break;
	default:
		break;
	}
	EventCollision(_DeltaTime);
	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::AirDash(float _DeltaTime)
{
	FVector MovePos = FVector::Zero;
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		NoGravity = false;
		State.ChangeState("DashAfterJump");
		return;
	}

	switch (Dir)
	{
	case EDir::Left:
		MovePos += FVector::Left * _DeltaTime * DashSpeed;
		break;
	case EDir::Right:
		MovePos += FVector::Right * _DeltaTime * DashSpeed;
		break;
	default:
		break;
	}
	MoveUpDate(_DeltaTime, MovePos);
}

void APlay_Cuphead::Duck(float _DeltaTime)
{
	DirCheck();
	if (true == IsFree(VK_DOWN))
	{
		PlayerCollision->SetScale(FVector(70.0f, 100.0f, 100.0f));
		PlayerCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));

		State.ChangeState("Idle");
		return;
	}

	if (true == IsPress('X'))
	{

		ShootStyle = EShootDir::DuckShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Duck_Shoot");
		return;
	}

	if (true == IsPress('V') && 100 == Guageint[PrevGuageCount]
		)
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::DownShoot;
		State.ChangeState("SSGround_Down");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_Straight(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime<0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Idle");
		return;
	}

	if (true == IsDown(VK_UP))
	{
		ShootStyle = EShootDir::UpShoot;
		State.ChangeState("Shoot_Up");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		ShootStyle = EShootDir::DuckShoot;
		State.ChangeState("Duck_Shoot");
		return;
	}

	if (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT))
	{
		ShootStyle = EShootDir::RunShoot;
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsDown('Z'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::IdleShoot;
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Duck_Shoot(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}
	if (true == IsFree(VK_DOWN))
	{
		PlayerCollision->SetScale(FVector(70.0f, 100.0f, 100.0f));
		PlayerCollision->SetPosition(FVector(0.0f, 60.0f, 0.0f));
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_Straight");
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Duck");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Aim_Up(float _DeltaTime)
{
	DirCheck();
	if (true == IsFree(VK_UP))
	{
		State.ChangeState("Idle");
		return;
	}
	

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::UpShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_Up");
		return;
	}

	if (true == IsDown('V') && 100 == Guageint[PrevGuageCount]
		)
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::UpShoot;
		State.ChangeState("SSGround_Up");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_Up(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}
	if (true == IsFree(VK_UP))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_Straight");
		return;
	}

	if (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT))
	{
		ShootStyle = EShootDir::RunShoot;
		State.ChangeState("Run_Shoot_Straight");
		return;
	}

	if (true == IsDown('Z'))
	{
		//BulletStart->SetActive(false);
		ShootStyle = EShootDir::UpShoot;
		JumpVector = JumpPowerPress;
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Aim_Up");
		return;
	}

	MoveUpDate(_DeltaTime);
}


void APlay_Cuphead::Jump(float _DeltaTime)
{
	DirCheck();


	if (true == IsUp('Z'))
	{
		JumpVector = JumpPowerDown;
	}

	if (true == IsDown(VK_SHIFT))
	{
		UEngineSound::SoundPlay("sfx_player_dash_01.wav");
		GetWorld()->SpawnActor<ADashDust>("DashDust")->SetDushDir(BulletDir);
		NoGravity = true;
		JumpVector = FVector::Zero;
		State.ChangeState("AirDash");
		return;
	}

	if (true == IsDown('X'))
	{
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		State.ChangeState("JumpShoot");
		return;
	}

	if (true == IsDown('Z'))
	{
		ParryCollision->SetActive(true);
		State.ChangeState("Parry");
		return;
	}

	if (true == IsDown('V') && true == IsPress(VK_DOWN) && (true == IsPress(VK_LEFT) || true == IsPress(VK_RIGHT)) && 100 == Guageint[PrevGuageCount])
	{
		JumpVector = FVector::Zero;
		NoGravity = true;
		SSBulletBehavir();
		ShootStyle = EShootDir::DiagonalDownShoot;
		State.ChangeState("Air_SSGround_DiagonalDown");
		return;
	}

	if (true == IsDown('V') && true == IsPress(VK_UP) && (true == IsPress(VK_LEFT) || true == IsPress(VK_RIGHT)) && 100 == Guageint[PrevGuageCount])
	{
		JumpVector = FVector::Zero;
		NoGravity = true;
		SSBulletBehavir();
		ShootStyle = EShootDir::DiagonalUpShoot;
		State.ChangeState("Air_SSGround_DiagonalUp");
		return;
	}

	if (true == IsDown('V') && true == IsPress(VK_UP) && 100 == Guageint[PrevGuageCount])
	{
		JumpVector = FVector::Zero;
		NoGravity = true;
		SSBulletBehavir();
		ShootStyle = EShootDir::UpShoot;
		State.ChangeState("Air_SSGround_Up");
		return;
	}

	if (true == IsDown('V') && true == IsPress(VK_DOWN)  && 100 == Guageint[PrevGuageCount])
	{
		JumpVector = FVector::Zero;
		NoGravity = true;
		SSBulletBehavir();
		ShootStyle = EShootDir::DownShoot;
		State.ChangeState("Air_SSGround_Down");
		return;
	}

	if (true == IsDown('V') && (true == IsPress(VK_LEFT) || true == IsPress(VK_RIGHT)) && 100 == Guageint[PrevGuageCount])
	{
		JumpVector = FVector::Zero;
		NoGravity = true;
		SSBulletBehavir();
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Air_SSGround_Straight");
		return;
	}


	FVector MovePos;

	// 점프 도중 X축 이동
	if (true==IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * JumpSpeed * _DeltaTime;
	}

	if (true==IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * JumpSpeed * _DeltaTime;
	}


	MoveUpDate(_DeltaTime, MovePos); // 최종 움직임
	
	GroundObject();

}

void APlay_Cuphead::JumpShoot(float _DeltaTime)
{
	DirCheck();

	if (true == IsUp('Z'))
	{
		JumpVector = JumpPowerDown;
	}

	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Jump");
		return;
	}


	FVector MovePos;

	// 점프 도중 X축 이동
	if (true == IsPress(VK_LEFT))
	{
		MovePos += FVector::Left * JumpSpeed * _DeltaTime;
	}

	if (true == IsPress(VK_RIGHT))
	{
		MovePos += FVector::Right * JumpSpeed * _DeltaTime;
	}


	MoveUpDate(_DeltaTime, MovePos); // 최종 움직임

	

	GroundObject();

}

void APlay_Cuphead::DashAfterJump(float _DeltaTime)
{
	MoveUpDate(_DeltaTime); // 최종 움직임
	

	GroundObject();
}

void APlay_Cuphead::hit(float _DeltaTime)
{
	BaseBulletSound.Off();
	BulletStart->SetActive(false);
	PlayerCollision->SetActive(false);

	if (false == IsHitEffect)
	{
		IsHitEffect = true;
		UEngineSound::SoundPlay("sfx_player_hit_01.wav");
		GetWorld()->SpawnActor<AhitEffect>("hitEffect")->SethitDir(BulletDir);
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		MoveUpDate(_DeltaTime);
		GroundObject();
		Hp -= 1;
		JumpVector = FVector::Zero;
		PowerShoot = false;
		NoGravity = false;
		IsHitEffect = false;
		State.ChangeState("Idle");
		return;
	}

}

void APlay_Cuphead::Parry(float _DeltaTime)
{
	DirCheck();
	BaseBulletSound.Off();

	ParryCheck(_DeltaTime);

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		PlayerCollision->SetActive(true);
		ParryCollision->SetActive(false);
		Effect->SetActive(false);
		GEngine->SetGlobalTimeScale(1.0f);
		State.ChangeState("Jump");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::Aim_Straight(float _DeltaTime)
{

	DirCheck();
	if (true == IsFree('C'))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsPress(VK_DOWN) && (true==IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		State.ChangeState("Aim_DiagonalDown");
		return;
	}

	if (true == IsPress(VK_UP) && (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		State.ChangeState("Aim_DiagonalUp");
		return;
	}

	if (true == IsPress(VK_DOWN))
	{
		State.ChangeState("Aim_Down");
		return;
	}

	if (true == IsPress(VK_UP))
	{
		State.ChangeState("Aim_Up2");
		return;
	}

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::IdleShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_StraightCB");
		return;
	}

	if (true == IsDown('V'))
	{
		SSBulletBehavir();
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("SSGround_Up");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Aim_DiagonalDown(float _DeltaTime)
{
	DirCheck();

	if (true == IsFree('C'))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("Aim_Straight");
		return;
	}

	if (true == IsFree(VK_RIGHT) && true == IsFree(VK_LEFT))
	{
		State.ChangeState("Aim_Down");
		return;
	}

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::DiagonalDownShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_DiagonalDown");
		return;
	}


	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Aim_Down(float _DeltaTime)
{
	DirCheck();

	if (true == IsFree('C'))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsFree(VK_DOWN))
	{
		State.ChangeState("Aim_Straight");
		return;
	}

	if ((true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		State.ChangeState("Aim_DiagonalDown");
		return;
	}

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::DownShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_Down");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Aim_DiagonalUp(float _DeltaTime)
{
	DirCheck();

	if (true == IsFree('C'))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsFree(VK_UP))
	{
		State.ChangeState("Aim_Straight");
		return;
	}

	if (true == IsFree(VK_RIGHT) && true == IsFree(VK_LEFT))
	{
		State.ChangeState("Aim_Up2");
		return;
	}

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::DiagonalUpShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_DiagonalUp");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Aim_Up2(float _DeltaTime)
{
	DirCheck();

	if (true == IsFree('C'))
	{
		State.ChangeState("Idle");
		return;
	}

	if (true == IsFree(VK_UP))
	{
		State.ChangeState("Aim_Straight");
		return;
	}

	if ((true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		State.ChangeState("Aim_DiagonalUp");
		return;
	}

	if (true == IsPress('X'))
	{
		ShootStyle = EShootDir::UpShoot;
		BulletStart->SetActive(true);
		State.ChangeState("Shoot_UpCB");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_StraightCB(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Aim_Straight");
		return;
	}

	if (true == IsPress(VK_DOWN) && (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		ShootStyle = EShootDir::DiagonalDownShoot;
		State.ChangeState("Shoot_DiagonalDown");
		return;
	}

	if (true == IsPress(VK_UP) && (true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		ShootStyle = EShootDir::DiagonalUpShootCB;
		State.ChangeState("Shoot_DiagonalUp");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_Down(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsFree(VK_DOWN))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_StraightCB");
		return;
	}

	if ((true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		ShootStyle = EShootDir::DiagonalDownShoot;
		State.ChangeState("Shoot_DiagonalDown");
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Aim_Down");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_DiagonalUp(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		int a = 0;
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Aim_DiagonalUp");
		return;
	}

	if (true == IsFree(VK_UP))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_StraightCB");
		return;
	}

	if (true == IsFree(VK_RIGHT) && true == IsFree(VK_LEFT))
	{
		ShootStyle = EShootDir::UpShoot;
		State.ChangeState("Shoot_UpCB");
		return;
	}
	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_DiagonalDown(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		int a = 0;
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Aim_DiagonalDown");
		return;
	}

	if (true == IsFree(VK_DOWN))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_StraightCB");
		return;
	}

	if (true == IsFree(VK_RIGHT) && true == IsFree(VK_LEFT))
	{
		ShootStyle = EShootDir::DownShoot;
		State.ChangeState("Shoot_Down");
		return;
	}
	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::Shoot_UpCB(float _DeltaTime)
{
	DirCheck();
	skillCoolTime -= _DeltaTime;
	if (true == IsPress('X') && skillCoolTime < 0.0f)
	{
		BaseBulletSound.On();
		createBullet();
		skillCoolTime = SaveSkilltime;
		return;
	}

	if (true == IsFree(VK_UP))
	{
		ShootStyle = EShootDir::IdleShoot;
		State.ChangeState("Shoot_StraightCB");
		return;
	}

	if ((true == IsPress(VK_RIGHT) || true == IsPress(VK_LEFT)))
	{
		ShootStyle = EShootDir::DiagonalUpShootCB;
		State.ChangeState("Shoot_DiagonalUp");
		return;
	}

	if (true == IsFree('X'))
	{
		BaseBulletSound.Off();
		BulletStart->SetActive(false);
		State.ChangeState("Aim_Up2");
		return;
	}

	MoveUpDate(_DeltaTime);
}

void APlay_Cuphead::SSGround_Straight(float _DeltaTime)
{
	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		NewSSDust->SetActorRotation(FVector::Zero);
		createSSBullet();
		PowerShoot = true;
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		PowerShoot = false;
		State.ChangeState("Idle");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::SSGround_Down(float _DeltaTime)
{

	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		NewSSDust->SetActorRotation({ 0.0f,0.0f,270.0f });
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		PowerShoot = false;
		PlayerCollision->SetScale(FVector(70.0f, 50.0f, 100.0f));
		PlayerCollision->SetPosition(FVector(0.0f, 30.0f, 0.0f));
		State.ChangeState("Duck");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::SSGround_DiagonalUp(float _DeltaTime)
{

	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);

		if (BulletDir.iX() == 1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,45.0f });
		}
		else if (BulletDir.iX() == -1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,-45.0f });
		}
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		PowerShoot = false;
		BulletStart->SetActive(true);
		State.ChangeState("Run_Shoot_DiagonalUp");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::SSGround_DiagonalDown(float _DeltaTime)
{

	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		if (BulletDir.iX() == 1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,315.0f });
		}
		else if (BulletDir.iX() == -1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,-315.0f });
		}
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		PowerShoot = false;
		PlayerCollision->SetScale(FVector(70.0f, 50.0f, 100.0f));
		PlayerCollision->SetPosition(FVector(0.0f, 30.0f, 0.0f));
		State.ChangeState("Duck");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::SSGround_Up(float _DeltaTime)
{

	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		NewSSDust->SetActorRotation({ 0.0f,0.0f,90.0f });
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		PowerShoot = false;
		State.ChangeState("Aim_Up");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::Air_SSGround_Straight(float _DeltaTime)
{
	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		NewSSDust->SetActorRotation(FVector::Zero);
		createSSBullet();
		PowerShoot = true;
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		NoGravity = false;
		PowerShoot = false;
		State.ChangeState("DashAfterJump");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::Air_SSGround_Down(float _DeltaTime)
{
	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		NewSSDust->SetActorRotation({ 0.0f,0.0f,270.0f });
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		PlayerCollision->SetScale(FVector(70.0f, 50.0f, 100.0f));
		PlayerCollision->SetPosition(FVector(0.0f, 30.0f, 0.0f));
		NoGravity = false;
		PowerShoot = false;
		State.ChangeState("DashAfterJump");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::Air_SSGround_DiagonalUp(float _DeltaTime)
{
	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);

		if (BulletDir.iX() == 1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,45.0f });
		}
		else if (BulletDir.iX() == -1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,-45.0f });
		}
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		NoGravity = false;
		PowerShoot = false;
		BulletStart->SetActive(true);
		State.ChangeState("DashAfterJump");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::Air_SSGround_DiagonalDown(float _DeltaTime)
{
	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		if (BulletDir.iX() == 1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,315.0f });
		}
		else if (BulletDir.iX() == -1)
		{
			NewSSDust->SetActorRotation({ 0.0f,0.0f,-315.0f });
		}
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		NoGravity = false;
		PowerShoot = false;
		PlayerCollision->SetScale(FVector(70.0f, 50.0f, 100.0f));
		PlayerCollision->SetPosition(FVector(0.0f, 30.0f, 0.0f));
		State.ChangeState("DashAfterJump");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::Air_SSGround_Up(float _DeltaTime)
{
	if (false == PowerShoot)
	{
		DirCheck();
		std::shared_ptr<ASSDust> NewSSDust = GetWorld()->SpawnActor<ASSDust>("SSDust");
		NewSSDust->SetDushDir(BulletDir);
		NewSSDust->SetActorRotation({ 0.0f,0.0f,90.0f });
		PowerShoot = true;
		createSSBullet();
	}

	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		NoGravity = false;
		PowerShoot = false;
		State.ChangeState("DashAfterJump");
		return;
	}

	MoveUpDate(_DeltaTime); // 최종 움직임
}

void APlay_Cuphead::Boss2PhaseChange(float _DeltaTime)
{
	AddActorLocation(FVector::Down * 200.0f * _DeltaTime);

	if (GetActorLocation().iY() <= -320)
	{
		PlayCuphead->SetActive(false);
	}

	if (GetActorLocation().iY() <= -1200)
	{
		UEngineSound::SoundPlay("sfx_player_intro_scared.wav");
		PlayCuphead->SetActive(true);
		PlayCuphead->SetDir(EEngineDir::Right);
		SetActorLocation(FVector(-200.0f, -130.0f, 0.0f));
		State.ChangeState("Scared");
		return;
	}
}

void APlay_Cuphead::Scared(float _DeltaTime)
{
	if (true == PlayCuphead->IsCurAnimationEnd())
	{
		State.ChangeState("Idle");
		return;
	}
	GroundObject();
}
