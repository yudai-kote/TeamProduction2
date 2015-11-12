#pragma once
#include "../../Share/Share.h"
#include "Unitselect/Unitselect.h"
#include "../../Classbase.h"
#include "../../Map/Map.h"
#include "../../Unit/Unitplayer.h"
#include "../../Unit/Unitenemy.h"


class Gamemanager : public Classbase{

private:

	Unitselect unitselect_;
	//Gamemain gamemain_;

	Map map_;

	std::list<Unitplayer> player;
	std::list<Unitenemy> enemy;

	Scenename gamechange;

public:
	Gamemanager();

	void Setup();
	void Update();
	void Draw();
	void Shift();
	Scenename Titleshift();


};