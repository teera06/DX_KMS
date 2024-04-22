#include "PreCompile.h"
#include "ContentsDebugWindow.h"

#include <EngineCore/EngineCore.h>


#include "ContentsHelper.h"

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

	if (true == ImGui::Button("WorldLevel"))
	{
		UContentsHelper::StageCount = 1;
		GEngine->ChangeLevel("Loading");
	}
}
