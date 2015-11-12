#pragma once 
#include "../../Share/Share.h"
#include "../Unitplayer.h"

class Lancer : public Unitplayer{
private:



public:

	Lancer(){
		status = new Status(70,20,0,10,0);
	};

	//Status LancerStatus(Status lancer){
	//	lancer.hp = 70;
	//	lancer.power = 20;
	//	lancer.magic_power = 0;
	//	lancer.defense = 10;
	//	lancer.magic_defense = 0;

	//	return Status{
	//		lancer.hp,
	//		lancer.power,
	//		lancer.magic_power,
	//		lancer.defense,
	//		lancer.magic_defense,
	//	};
	//}


};
