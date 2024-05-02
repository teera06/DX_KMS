#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class ABoss2Phase2Map : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	ABoss2Phase2Map(); // 디폴트 생성자
	~ABoss2Phase2Map(); // 디폴트 소멸자

	// delete Function
	ABoss2Phase2Map(const ABoss2Phase2Map& _Other) = delete; // 디폴트 복사 생성자
	ABoss2Phase2Map(ABoss2Phase2Map&& _Other) noexcept = delete; 
	ABoss2Phase2Map& operator=(const ABoss2Phase2Map& _Other) = delete; // 디폴트 대입 연산자
	ABoss2Phase2Map& operator=(ABoss2Phase2Map&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* Boss2Phase2Map = nullptr;

	float Delay = 4.0f;

	int order = 1;
	int Add = 1;

	bool OneCheck1 = false;
	

	void CreateChip1(float _DeltaTime);
	void CreateChip2(float _DeltaTime);
	void CreateChip3(float _DeltaTime);
};

