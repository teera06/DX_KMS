#pragma once

#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;

class AOrb_Fire2 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AOrb_Fire2(); // 디폴트 생성자
	~AOrb_Fire2(); // 디폴트 소멸자

	// delete Function
	AOrb_Fire2(const AOrb_Fire2& _Other) = delete; // 디폴트 복사 생성자
	AOrb_Fire2(AOrb_Fire2&& _Other) noexcept = delete; 
	AOrb_Fire2& operator=(const AOrb_Fire2& _Other) = delete; // 디폴트 대입 연산자
	AOrb_Fire2& operator=(AOrb_Fire2&& _Other) noexcept = delete;


	UStateManager pattern;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* MainRender = nullptr;
	USpriteRenderer* Orb_Fire2Render = nullptr;
	USpriteRenderer* Orb_Fire2Render2 = nullptr;
	USpriteRenderer* Orb_Fire2Render3 = nullptr;
	USpriteRenderer* Orb_Fire2Render4 = nullptr;
	UCollision* Orb_Fire2Col = nullptr;

	float RotSpeed = 6000.0f;
	float MoveSpeed = 200.0f;
	float MoveLR = 300.0f;

	bool EndAni = false;

	void RotMove(float _DeltaTime);

	// 상태 함수
	void patternInit();
	void MoveR(float _DeltaTime);
	void MoveL(float _DeltaTime);
	
};

