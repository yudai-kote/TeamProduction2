#pragma once 
#include "../../Share/Share.h"
#include "../Unitplayer.h"

class Warrior : public Unitplayer{
private:


public:

	Warrior(int number = 0){
		status = new Status(100, 50, 0, 10, 0);
		unitlist = new Unitlist(number);
		color = Color::red;
	}

	Status GetWarriorStatus(){
		return Status{
			status->hp,
			status->power,
			status->magic_power,
			status->defense,
			status->magic_defense,
		};
	}

	Color GetColor(){
		return color;
	}
};
