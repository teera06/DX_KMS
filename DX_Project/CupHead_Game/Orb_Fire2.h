#pragma once

#include <EngineCore/Actor.h>
#include <EngineCore/StateManager.h>

class USpriteRenderer;

class AOrb_Fire2 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AOrb_Fire2(); // ����Ʈ ������
	~AOrb_Fire2(); // ����Ʈ �Ҹ���

	// delete Function
	AOrb_Fire2(const AOrb_Fire2& _Other) = delete; // ����Ʈ ���� ������
	AOrb_Fire2(AOrb_Fire2&& _Other) noexcept = delete; 
	AOrb_Fire2& operator=(const AOrb_Fire2& _Other) = delete; // ����Ʈ ���� ������
	AOrb_Fire2& operator=(AOrb_Fire2&& _Other) noexcept = delete;

	USpriteRenderer* GetMainRender()
	{
		return MainRender;
	}

	UCollision* GetMainCollision()
	{
		return Orb_Fire2Col;
	}

	UStateManager pattern;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:

	UEngineSoundPlayer FireSound;
	USpriteRenderer* MainRender = nullptr;
	USpriteRenderer* Orb_Fire2Render = nullptr;
	USpriteRenderer* Orb_Fire2Render2 = nullptr;
	USpriteRenderer* Orb_Fire2Render3 = nullptr;
	USpriteRenderer* Orb_Fire2Render4 = nullptr;

	UCollision* Orb_Fire2Col = nullptr;

	std::vector<UCollision*> subCols;

	float RotSpeed = 6000.0f;
	float MoveSpeed = 200.0f;
	float MoveLR = 300.0f;

	bool EndAni = false;

	void RotMove(float _DeltaTime);

	// ���� �Լ�
	void patternInit();
	void MoveR(float _DeltaTime);
	void MoveL(float _DeltaTime);
	
};

