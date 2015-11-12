#pragma once
#include "../../Share/Share.h"
#include "Unitselect/Unitselect.h"
#include "../../Classbase.h"
#include "../../Map/Map.h"
//#include "../../Unit/Unitplayer.h"
//#include "../../Unit/Unitenemy.h"

#include "../../Unit/Job/Lancer.h"
#include "../../Unit/Job/Warrior.h"


class Gamemanager : public Classbase{

private:

	//std::vector<Unitplayer> memo;

	Unitselect* unitselect_ = new Unitselect(l_player);

	Map map_;

	std::list<Unitplayer*> l_player;

	Scenename gamechange;

public:
	Gamemanager();

	void Setup();
	void Update();
	void Draw();
	void Shift();
	Scenename Titleshift();


};