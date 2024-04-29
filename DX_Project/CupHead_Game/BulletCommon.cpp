#include "PreCompile.h"
#include "BulletCommon.h"

#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/Collision.h>

#include "ContentsENum.h"

ABulletCommon::ABulletCommon()
{
}

ABulletCommon::~ABulletCommon()
{
}

void ABulletCommon::SkillDir()
{
	if (BulletDir.iX() == 1)
	{
		BulletRender->SetDir(EEngineDir::Right);
	}
	else if (BulletDir.iX() == -1)
	{
		BulletRender->SetDir(EEngineDir::Left);
	}
}

void ABulletCommon::Collisiongather()
{
	
}
