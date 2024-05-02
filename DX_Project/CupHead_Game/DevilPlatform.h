#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;

class ADevilPlatform : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevilPlatform(); // ����Ʈ ������
	~ADevilPlatform(); // ����Ʈ �Ҹ���

	// delete Function
	ADevilPlatform(const ADevilPlatform& _Other) = delete; // ����Ʈ ���� ������
	ADevilPlatform(ADevilPlatform&& _Other) noexcept = delete; 
	ADevilPlatform& operator=(const ADevilPlatform& _Other) = delete; // ����Ʈ ���� ������
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

	// ����
	void patternInit();
	void patternInit2();
	void patternInit3();
	void UP(float _DeltaTime);
	void Down(float _DeltaTime);
	void DownDie(float _DeltaTime);

};

