#pragma once
#include "../../Share/Share.h"
#include "../Chara/Chara.h"
#include "Command/Command.h"

class Player : public Chara{
private:
protected:
	Command command;



public:

	Player();
	void Setup();
	void Update();
	void Draw();

};


