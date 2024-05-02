#pragma once
class USpriteRenderer;

class APokerChip : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	APokerChip(); // ����Ʈ ������
	~APokerChip(); // ����Ʈ �Ҹ���

	// delete Function
	APokerChip(const APokerChip& _Other) = delete; // ����Ʈ ���� ������
	APokerChip(APokerChip&& _Other) noexcept = delete; 
	APokerChip& operator=(const APokerChip& _Other) = delete; // ����Ʈ ���� ������
	APokerChip& operator=(APokerChip&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	USpriteRenderer* PokerChip = nullptr;
	USpriteRenderer* Effect = nullptr;

	USpriteRenderer* picec1 = nullptr;
	USpriteRenderer* picec2 = nullptr;
	USpriteRenderer* picec3 = nullptr;
	USpriteRenderer* picec4 = nullptr;
	USpriteRenderer* picec5 = nullptr;
	USpriteRenderer* picec6 = nullptr;
	USpriteRenderer* picec7 = nullptr;

	UCollision* PokerChipCollision = nullptr;

	

	FVector GravityVector = FVector::Zero;

	float Speed = 200.0f;

	bool DestoryCheck = false;

	void GroundCheck(float _DeltaTime);

	void CollisionCheck();
};

