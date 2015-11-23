#pragma once
#include "../Share/Share.h"
struct UI{
	Vec2f pos;
	Vec2f size;
};
class Ui{
private:
	Font font = Font("res/meiryo.ttc");
	int font_size = 50;
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
	void Draw(Status status);
	void BoardDraw();
	void OperatePlayer();
	void AttakPlayer(int end);
	void Move();
	void Animation();
	void OperateCursor();
	void Select();

	void SetDir(Direction set);
	void SetUnitNum(int set);

	Direction GetDir();
	int GetUnitNum();
	bool IsAttacked();
};