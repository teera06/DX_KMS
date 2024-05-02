#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;

class ADevilPlatform : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevilPlatform(); // 디폴트 생성자
	~ADevilPlatform(); // 디폴트 소멸자

	// delete Function
	ADevilPlatform(const ADevilPlatform& _Other) = delete; // 디폴트 복사 생성자
	ADevilPlatform(ADevilPlatform&& _Other) noexcept = delete; 
	ADevilPlatform& operator=(const ADevilPlatform& _Other) = delete; // 디폴트 대입 연산자
	ADevilPlatform& operator=(ADevilPlatform&& _Other) noexcept = delete;

	inline void SetGroundOrder(const int& _GroundOrder)
	{
		GroundOrder = _GroundOrder;
	}

	static int GetPhaseCount()
	{
		return PhaseCount;
	}


	UStateManager pattern1;
	UStateManager pattern2;
	UStateManager pattern3;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* DevilPlatform = nullptr;
	UCollision* GroundCollision = nullptr;
	UCollision* LRCollision = nullptr;

	static std::vector<int> num;

	static int PhaseCount;
	static int count;
	static bool Groundpattern;

	int CheckYUP = 0;
	int CheckYDown = 0;

	int GroundOrder = 0;
	

	float Speed = 250.0f;

	bool OneCheck = false;

	

	void PlayerCollision();

	// 상태
	void patternInit();
	void patternInit2();
	void patternInit3();
	void UP(float _DeltaTime);
	void Down(float _DeltaTime);
	void DownDie(float _DeltaTime);

};

