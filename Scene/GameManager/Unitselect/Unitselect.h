#pragma once
#include "../../../Share/Share.h"
#include "../../../Classbase.h"
#include "../../../Unit/Job/Lancer.h"
#include "../../../Unit/Job/Warrior.h"
#include "../../../Unit/Unitplayer.h"

class Unitselect : public Classbase{

private:
	
	std::list<Unitplayer*>& p_list_;

	int select_job;

	std::list<Vec2f> pos;


	void SelectJob();
	void ShiftJob();


public:

	Unitselect(std::list<Unitplayer*>& p_list);


	void Setup();
	void Update();
	void Draw();
	Scenename Shift();


};