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
	Boss1_Back3,
	Boss1_crowd3,
	Monster,
	skill,
	Cuphead,
	Object,
	HPBar,
	HPgauge,
	Filter
};