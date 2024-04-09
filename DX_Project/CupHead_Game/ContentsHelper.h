#pragma once

class UContentsHelper
{
public:
	// constrcuter destructer
	UContentsHelper(); // 디폴트 생성자
	~UContentsHelper(); // 디폴트 소멸자

	// delete Function
	UContentsHelper(const UContentsHelper& _Other) = delete; // 디폴트 복사 생성자
	UContentsHelper(UContentsHelper&& _Other) noexcept = delete; 
	UContentsHelper& operator=(const UContentsHelper& _Other) = delete; // 디폴트 대입 연산자
	UContentsHelper& operator=(UContentsHelper&& _Other) noexcept = delete;

	static int StageCount;
	// Stage 0 타이틀
	// Stage 1 월드맵
	// Stage 2 보스 맵 1
	// Stage 3 보스 맵 2
protected:
private:
};

