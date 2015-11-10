#include "Unitselect.h"

Unitselect::Unitselect(){



}


void Unitselect::Setup(){




}

void Unitselect::Update(){



}

void Unitselect::Draw(){



}

Scenename Unitselect::Shift(){
	if (env.isPushKey('A')){
		return Scenename::GAMEMAIN;
	}
	return Scenename::UNITSELECT;
}
