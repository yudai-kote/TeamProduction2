#pragma once
#include "../../../Share/Share.h"
#include "../../../Classbase.h"
#include "../../../Unit/Job/Lancer.h"
#include "../../../Unit/Job/Warrior.h"
#include "../../../Unit/Unitplayer.h"

class Unitselect : public Classbase{

private:
	Font font = Font("res/meiryo.ttc");
	int font_size = 50;

	std::list<Unitplayer*>& p_list_;

	
	std::list<Vec2f> pos;

	Lancer lancer;
	Warrior warrior;

	int select_job;
	int num;
	int count = 1;
	Color selectjob_color[static_cast<int>(Job::JOB_MAX)];

	void SelectJob();
	void ShiftJob();

	void JobDraw();
	void StatusDraw();
public:

	Unitselect(std::list<Unitplayer*>& p_list);


	void Setup();
	void Update();
	void Draw();
	Scenename Shift();


};