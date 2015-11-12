#pragma once
#include "../../../Share/Share.h"
#include "../../../Classbase.h"
#include "../../../Unit/Job/Lancer.h"
#include "../../../Unit/Job/Warrior.h"
#include "../../../Unit/Unitplayer.h"

class Unitselect : public Classbase{

private:
	
	//std::vector<Lancer*> v_Lancer;
	//std::vector<Warrior*> v_Warrior;

	std::list<Unitplayer*>& p_list_;

	int select_job;

	void SelectJob();
	void ShiftJob();

	//std::vector<Unitplayer>& memo_;

public:

	Unitselect(std::list<Unitplayer*>& p_list);


	void Setup();
	void Update();
	void Draw();
	Scenename Shift();

	//std::vector<Lancer*> GetLancer(){
	//	return v_Lancer;
	//}
	//std::vector<Warrior*> GetWarrior(){
	//	return v_Warrior;
	//}


};