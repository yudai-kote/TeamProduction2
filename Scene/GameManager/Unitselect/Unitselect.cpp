#include "Unitselect.h"

Unitselect::Unitselect(std::list<Unitplayer*>& p_list) :
p_list_(p_list)
{
	
}


void Unitselect::Setup(){




}

void Unitselect::Update(){
	SelectJob();
	ShiftJob();


}

void Unitselect::Draw(){



}

Scenename Unitselect::Shift(){
	if (env.isPushKey('A')){
		return Scenename::GAMEMAIN;
	}
	return Scenename::UNITSELECT;
}


void Unitselect::SelectJob(){

	switch (select_job)
	{
	case static_cast<int> (Job::LANCER) :
		if (env.isPushKey(GLFW_KEY_ENTER))
		{
			p_list_.push_back(new Lancer);
			
			
		}
			break;
	case static_cast<int> (Job::WARRIOR) :
		if (env.isPushKey(GLFW_KEY_ENTER))
		{
			p_list_.push_back(new Warrior);


		}
		break;

	}

}


void Unitselect::ShiftJob(){
	if (env.isPushKey(GLFW_KEY_RIGHT))
	{
		if (select_job <= static_cast<int>(Job::JOB_MAX))
		{
			select_job++;
		}
	}
	if (env.isPushKey(GLFW_KEY_LEFT))
	{
		if (select_job >= 0)
		{
			select_job--;
		}
	}
}