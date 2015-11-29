#pragma once
#include "../Share/Share.h"
struct UI{
	Vec2f pos;
	Vec2f size;
};
class Ui{
private:
	Font font = Font("res/meiryo.ttc");
	int font_size = 40;
	UI command_board;
	UI command;
	UI status_board;
	float angle;
	float animation;
	int instruction;
	bool action;
	bool dir;
	

	//GetèÓïÒ
	int number;
	bool attack;
	bool skill;
	Vec2i player_pos;
	float cost;
	Direction direction;
	Direction p_direction;
	Direction s_direction;
public:
	Ui();
	void Update();
	void Draw(Status status);
	void BoardDraw();
	void OperatePlayer();
	void AttakPlayer();
	void SkillPlayer();
	void Move();
	void Animation();
	void OperateCursor();
	void Select();
	void False();

	void SetDir(Direction set);
	void SetPDir(Direction set);
	void SetUnitNum(int set);
	void SetUnitPos(Vec2i pos);
	void SetPlayerCost(int cost);
	
	int GetUnitNum();
	bool IsAttacked();
	bool IsSkilled();
	bool GetDirection();
	Vec2i GetUnitPos();
	int GetPlayerCost();
	Direction GetDir();
	Direction GetPDir();
};