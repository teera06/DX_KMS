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
		if (UContentsHelper::StageCount == 2)
		{
			return;
		}
		UContentsHelper::StageCount = 2;
		GEngine->ChangeLevel("Loading");
	}

	if (true == ImGui::Button("PlayeLevel2"))
	{
		if (UContentsHelper::StageCount == 3)
		{
			return;
		}
		UContentsHelper::StageCount = 3;
		GEngine->ChangeLevel("Loading");
	}

	if (true == ImGui::Button("WorldLevel"))
	{

		if (UContentsHelper::StageCount == 1)
		{
			return;
		}
		UContentsHelper::StageCount = 1;
		GEngine->ChangeLevel("Loading");
	}

	if (UContentsHelper::StageCount == 2)
	{
		if (true == ImGui::Button("Phase2Change"))
		{
			if (1== ABoss1Common::Getphasecheck())
			{
				ABoss1Common::SetHp(70);
			}
			else if (2 == ABoss1Common::Getphasecheck())
			{
				ABoss1Common::SetHp(40);
			}
			else if (3 == ABoss1Common::Getphasecheck())
			{
				ABoss1Common::SetHp(0);
			}
			return;
		}
		
		int Hp = ABoss1Common::GetHp();
		std::string Msg = std::format("Boss1 : {}\n", std::to_string(Hp));
		
		ImGui::Text(&Msg[0]);
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
		int Hp = ABoss2Common::GetHp();
		std::string Msg = std::format("Boss2 : {}\n", std::to_string(Hp));

		ImGui::Text(&Msg[0]);
	}
}
