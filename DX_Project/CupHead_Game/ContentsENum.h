#pragma once

enum class EPlayerState
{
	None,
	Idle,
	Move,
	Jump,
	Dash,
	IdleAtt,
	MoveAtt,
	JumpAtt,
	hit,
	HeadDown,
	MaxAtt
};

enum class EDir
{
	None,
	Left,
	Right,
	Up,
	Down
};

enum class EShootDir
{
	None,
	IdleShoot,
	RunShoot,
	UpShoot,
	DownShoot,
	DuckShoot,
	DiagonalUpShoot
};

enum class ERenderOrder
{
	background,
	WorldCol,
	CupheadDence,
	Log,
	WorldMap,
	Boss1_back1,
	Boss1_back2,
	Boss1_crowd2,
	Boss1_Waiter,
	Boss1_Back3,
	Boss1_crowd3,
	SlotImage,
	Monster1,
	Monster2,
	SlotMouse,
	skilleffect,
	Bullet,
	Cuphead,
	Object1,
	Fire,
	Object2,
	Object3,
	Object3Ball,
	ObjectFront,
	HPBar,
	HPgauge,
	FilterEffect,
	Filter
};

enum class ECollisionOrder
{
	Player,
	Boss1SkillMonster,
	Boss1Monster1,
	Boss1Monster2,
	Boss1Monster2Hand,
	Boss1Top,
	Boss1LR,
	Boss1Object3,
	Boss1Ball,
	Bullet,
	Coin,
	ball,
	MonsterSkill
};