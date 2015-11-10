#pragma once
#include "../Share/Share.h"
#include "../Unit/Player/Player.h"

class Unitplayer : public Player{
private:

	void move();



public:

	Unitplayer();

	void Setup();
	void Update();
	void Draw();

	void SetIsMove(bool is_move_);

};

