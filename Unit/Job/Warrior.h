#pragma once 
#include "../../Share/Share.h"
#include "../Unitplayer.h"

class Warrior : public Unitplayer{
private:


public:

	Warrior(){
		status = new Status(100, 10, 0, 10, 0);
	}

	//Status WarriorStatus(Status warrior){
	//	warrior.hp = 100;
	//	warrior.power = 10;
	//	warrior.magic_power = 0;
	//	warrior.defense = 10;
	//	warrior.magic_defense = 0;

	//	return Status{
	//		warrior.hp,
	//		warrior.power,
	//		warrior.magic_power,
	//		warrior.defense,
	//		warrior.magic_defense,
	//	};
	//}



};
