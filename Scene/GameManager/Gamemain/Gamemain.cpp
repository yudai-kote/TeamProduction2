#include "Gamemain.h"

void Gamemain::Update(){

}

void Gamemain::Draw(){
	map_.Draw();
}

Scenename Gamemain::Shift(){
	if (env.isPushKey('A')){
		return Scenename::UNITSELECT;
	}
	return Scenename::GAMEMAIN;
}