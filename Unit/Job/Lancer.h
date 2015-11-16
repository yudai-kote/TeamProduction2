#pragma once 
#include "../../Share/Share.h"
#include "../Unitplayer.h"

class Lancer : public Unitplayer{
private:


public:
	

	Lancer(int number = 0){
		status = new Status(70,70,0,10,0);
		unitlist = new Unitlist(number);
		color = Color::blue;
	};

	Status GetLancerStatus(){
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
