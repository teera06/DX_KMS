#pragma once

#include <EngineCore/Actor.h>

#include "Boss2Common.h"
class USpriteRenderer;
class AHeadAtt;

class ADevil1 : public AActor, public ABoss2Common
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ADevil1(); // ����Ʈ ������
	~ADevil1(); // ����Ʈ �Ҹ���

	// delete Function
	ADevil1(const ADevil1& _Other) = delete; // ����Ʈ ���� ������
	ADevil1(ADevil1&& _Other) noexcept = delete; 
	ADevil1& operator=(const ADevil1& _Other) = delete; // ����Ʈ ���� ������
	ADevil1& operator=(ADevil1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
	void Phase1StateInit() override;

	void AniCreate() override;
private:
	std::shared_ptr<AHeadAtt> NewHeadAtt = nullptr;
	USpriteRenderer* Boss2 = nullptr;
	USpriteRenderer* BossHead = nullptr;
	USpriteRenderer* BossBody = nullptr;


	void CreateHeadAtt();

	// ���⼭���ʹ� ���� �Լ��� 
	void Phase1Intro(float _DeltaTime);
	void Phase1Idle(float _DeltaTime);
	void DragonTransform(float _DeltaTime);
	void DragonIdle(float _DeltaTime);
};

