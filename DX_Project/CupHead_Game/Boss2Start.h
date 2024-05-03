#pragma once

#include "CommonStart.h"

class ABoss2Start : public ACommonStart
{
	GENERATED_BODY(ACommonStart)
public:
	// constrcuter destructer
	ABoss2Start(); // 디폴트 생성자
	~ABoss2Start(); // 디폴트 소멸자

	// delete Function
	ABoss2Start(const ABoss2Start& _Other) = delete; // 디폴트 복사 생성자
	ABoss2Start(ABoss2Start&& _Other) noexcept = delete; 
	ABoss2Start& operator=(const ABoss2Start& _Other) = delete; // 디폴트 대입 연산자
	ABoss2Start& operator=(ABoss2Start&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	
};

