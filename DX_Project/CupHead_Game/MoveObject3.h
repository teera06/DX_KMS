#pragma once
#include <Enginecore/Actor.h>

class USpriteRenderer;
class AMoveObject3 : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	AMoveObject3(); // ����Ʈ ������
	~AMoveObject3(); // ����Ʈ �Ҹ���

	// delete Function
	AMoveObject3(const AMoveObject3& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject3(AMoveObject3&& _Other) noexcept = delete; 
	AMoveObject3& operator=(const AMoveObject3& _Other) = delete; // ����Ʈ ���� ������
	AMoveObject3& operator=(AMoveObject3&& _Other) noexcept = delete;

protected:

private:
};

