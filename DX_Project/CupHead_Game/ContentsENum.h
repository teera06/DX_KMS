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
	Monster1,
	Monster2,
	skilleffect,
	Bullet,
	Cuphead,
	Object1,
	Object2,
	HPBar,
	HPgauge,
	FilterEffect,
	Filter
};

enum class ECollisionOrder
{
	Player,
	Monster, 
	Bullet,
	MonsterSkill
};