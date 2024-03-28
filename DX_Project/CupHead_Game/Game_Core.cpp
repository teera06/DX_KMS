#include "PreCompile.h"
#include "Game_Core.h"
#include "PlayGameMode.h"
UGame_Core::UGame_Core()
{
}

UGame_Core::~UGame_Core()
{
}

void UGame_Core::Initialize()
{
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->ChangeLevel("PlayLevel");

	//{
	//	UEngineDirectory Dir;
	//	Dir.MoveToSearchChild("ContentsResources");
	//	Dir.Move("Sound");
	//	std::list<UEngineFile> Files = Dir.AllFile({ ".wav" });
	//	for (UEngineFile& File : Files)
	//	{
	//		UEngineSound::Load(File.GetFullPath());
	//	}
	//	UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	//}
}
