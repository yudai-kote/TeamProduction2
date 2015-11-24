#pragma once
#include "../Share/Share.h"
#include "../Unit/Player/Player.h"

class Unitplayer : public Chara{
private:

	void Move(Direction ui_direction);
	void Animation();

	Font font = Font("res/meiryo.ttc");

	

public:


	Unitplayer();

	void Setup(Status status);
	void Update();
	void Draw();

	void SetSelectPos(Vec2f select_pos);
	void SetSelectNum(int selectnumber);

	void SetCanMove(bool can_move_);
	void SetIsAttack(bool is_attack_);
	void SetDirection(Direction ui_direction);
	void SetUnitlistPos(Vec2i getpos);
	void SetDrawPos(Vec2i getpos);

	Unitlist GetUnitlist();
	Vec2i GetPos();
	Status GetStatus();
	int GetNum();
	Job GetJob();
	Vec2f GetSelectPos();

};

