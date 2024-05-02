#include "PreCompile.h"
#include "ContentsDebugWindow.h"

#include <EngineCore/EngineCore.h>


#include "ContentsHelper.h"
#include "Boss1Common.h"
#include "Boss2Common.h"

UContentsDebugWindow::UContentsDebugWindow()
{
}

UContentsDebugWindow::~UContentsDebugWindow()
{
}

void UContentsDebugWindow::Init()
{
}

void UContentsDebugWindow::OnGui(ULevel* Level, float _Delta)
{
	if (true == ImGui::Button("PlayeLevel"))
	{
		UContentsHelper::StageCount = 2;
		GEngine->ChangeLevel("Loading");
	}

	if (true == ImGui::Button("PlayeLevel2"))
	{
		UContentsHelper::StageCount = 3;
		GEngine->ChangeLevel("Loading");
	}

	if (true == ImGui::Button("WorldLevel"))
	{
		UContentsHelper::StageCount = 1;
		GEngine->ChangeLevel("Loading");
	}

	if (UContentsHelper::StageCount == 2)
	{
		if (true == ImGui::Button("Phase2Change"))
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
	}

	if (UContentsHelper::StageCount == 3)
	{
		if (true == ImGui::Button("Phase3Change"))
		{
			if (100 == ABoss2Common::GetHp())
			{
				ABoss2Common::SetHp(75);
			}
			else if (75 == ABoss2Common::GetHp())
			{
				ABoss2Common::SetHp(50);
			}
			else if (50 == ABoss2Common::GetHp())
			{
				ABoss2Common::SetHp(25);
			}
			else if (25 == ABoss2Common::GetHp())
			{
				ABoss2Common::SetHp(0);
			}
			return;
		}
	}
}
