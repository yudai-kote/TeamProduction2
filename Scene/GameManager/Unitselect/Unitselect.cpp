#include "Unitselect.h"

Unitselect::Unitselect(std::list<Unitplayer*>& p_list) :
p_list_(p_list)
{
	select_job = 0;
}


void Unitselect::Setup(){




}

void Unitselect::Update(){
	SelectJob();
	ShiftJob();


}

void Unitselect::Draw(){
	for (auto itr = p_list_.begin(); itr != p_list_.end(); ++itr)
	{
		(*itr)->Draw();
	}
}

Scenename Unitselect::Shift(){
	if (env.isPushKey('A')){
		return Scenename::GAMEMAIN;
	}
	return Scenename::UNITSELECT;
	env.flushInput();
}


void Unitselect::SelectJob(){

	switch (select_job)
	{
	case static_cast<int> (Job::WARRIOR) :
		if (env.isPushKey(GLFW_KEY_ENTER))
		{
			p_list_.push_back(new Warrior);
			for (auto itr = p_list_.begin(); itr != --p_list_.end(); ++itr)
			{
				(*itr)->SetSelectPos(Vec2f(200, 0));
			}
		}
										 break;
	case static_cast<int> (Job::LANCER) :
		if (env.isPushKey(GLFW_KEY_ENTER))
		{
			p_list_.push_back(new Lancer);
			for (auto itr = p_list_.begin(); itr != --p_list_.end(); ++itr)
			{
				(*itr)->SetSelectPos(Vec2f(200, 0));
			}
		}
										break;
	}
}


void Unitselect::ShiftJob(){
	if (env.isPushKey(GLFW_KEY_RIGHT))
	{
		if (select_job < static_cast<int>(Job::JOB_MAX))
		{
			select_job++;
		}
		std::cout << select_job << std::endl;
	}
	if (env.isPushKey(GLFW_KEY_LEFT))
	{
		if (select_job > 0)
		{
			select_job--;
		}
		std::cout << select_job << std::endl;
	}
}