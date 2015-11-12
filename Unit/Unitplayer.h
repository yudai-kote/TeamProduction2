#pragma once
#include "../Share/Share.h"
#include "../Unit/Player/Player.h"

class Unitplayer : public Player{
private:

	void Move(Direction ui_direction);
	void Animation();


public:

	Unitplayer(Unitlist player_unit);

	void Setup();
	void Update();
	void Draw();

	void SetCanMove(bool can_move_);
	void SetIsAttack(bool is_attack_);
	void SetDirection(Direction ui_direction);


};

