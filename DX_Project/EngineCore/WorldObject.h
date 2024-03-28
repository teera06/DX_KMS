#pragma once
class WorldObject
{
public:
	// constrcuter destructer
	WorldObject(); // 디폴트 생성자
	~WorldObject(); // 디폴트 소멸자

	// delete Function
	WorldObject(const WorldObject& _Other) = delete; // 디폴트 복사 생성자
	WorldObject(WorldObject&& _Other) noexcept = delete; 
	WorldObject& operator=(const WorldObject& _Other) = delete; // 디폴트 대입 연산자
	WorldObject& operator=(WorldObject&& _Other) noexcept = delete;

protected:

private:
};

