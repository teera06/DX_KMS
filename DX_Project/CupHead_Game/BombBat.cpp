#include "PreCompile.h"
#include "BombBat.h"

#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ABombBat::ABombBat()
{
}

ABombBat::~ABombBat()
{
}

void ABombBat::BeginPlay()
{
	Super::BeginPlay();
}

void ABombBat::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
