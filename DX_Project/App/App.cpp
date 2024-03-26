#include <Windows.h>
#include <string_view>

#include <EngineCore/EngineCore.h>
#include <CupHead_Game/Game_Core.h>
// EnginePlatform�� �����ϴ� enginewindow����� �翬�� �̿��ϰ� ���� ���̴�.

#pragma comment (lib, "EngineBase.lib")
#pragma comment (lib, "EnginePlatform.lib")
#pragma comment (lib, "EngineCore.lib")
#pragma comment (lib, "CupHead_Game.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UEngineCore::Start<UGame_Core>(hInstance);
}