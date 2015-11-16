#pragma once
#include "../Share/Share.h"
struct UI{
	Vec2f pos;
	Vec2f size;
};
class Ui{
private:
	UI command_board;
	UI command;
	UI status_board;
	float angle;
	float animation;
	int instruction;
	bool action;
	//ƒvƒŒƒCƒ„[‚©‚ç‚à‚ç‚¤î•ñ
	
	Vec2f plyer_pos;

	//Getî•ñ
	Direction direction;
	int number;
	bool attack;
public:
	Ui();
	void Update();
	void Draw();
	void BoardDraw();
	void OperatePlayer();
	void Move();
	void Animation();
	void OperateCursor();
	void Select();

	Direction GetDir();
	int GetUnitNum();
};