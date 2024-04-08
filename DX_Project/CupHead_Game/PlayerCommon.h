#pragma once

class PlayerCommon
{
public:
	// constrcuter destructer
	PlayerCommon(); // 디폴트 생성자
	~PlayerCommon(); // 디폴트 소멸자

	// delete Function
	PlayerCommon(const PlayerCommon& _Other) = delete; // 디폴트 복사 생성자
	PlayerCommon(PlayerCommon&& _Other) noexcept = delete; 
	PlayerCommon& operator=(const PlayerCommon& _Other) = delete; // 디폴트 대입 연산자
	PlayerCommon& operator=(PlayerCommon&& _Other) noexcept = delete;

protected:
	static int StageCount;
private:
};

