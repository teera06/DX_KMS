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

	{
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("GameResource");
		Dir.Move("Image");
		Dir.Move("Cuphead");
		Dir.Move("Idle");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			//File.Open(EIOOpenMode::Read, EIODataType::Binary);

			//char Arr[100];
			//File.Read(Arr, 100);

			UEngineTexture::Load(File.GetFullPath());
		}
		// UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	}
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
