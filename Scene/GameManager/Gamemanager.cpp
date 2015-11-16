#include "Gamemanager.h"

Gamemanager::Gamemanager(){
	gamechange = Scenename::UNITSELECT;
}


void Gamemanager::Setup(){
	gamechange = Scenename::UNITSELECT;

	
}

void Gamemanager::Update(){
	switch (gamechange)
	{
	case Scenename::UNITSELECT:
		unitselect_->Update();
		break;
	case Scenename::GAMEMAIN:
		ui_.Update();
		ui_.Move();
		if (!map_.Isunitmoving(ui_.GetUnitNum(),ui_.GetDir())){
			
		}
		if (ui_.IsAttacked()){
			if (map_.Isattackhit(ui_.GetUnitNum(), ui_.GetDir())){

			}
		}
		break;
	case Scenename::RESULT:

		break;
	}
}

void Gamemanager::Draw(){

	switch (gamechange)
	{
	case Scenename::UNITSELECT:

		unitselect_->Draw();
		break;
	case Scenename::GAMEMAIN:

		for (auto itr = l_player.begin(); itr != l_player.end(); ++itr)
		{
			(*itr)->Draw();
		}
		map_.Draw();
		ui_.Draw();
		break;
	case Scenename::RESULT:
		
		break;
	}


}


void Gamemanager::Shift(){
	switch (gamechange)
	{
	case Scenename::UNITSELECT:
		gamechange = unitselect_->Shift();
		break;
	case Scenename::GAMEMAIN:
		if (env.isPushKey('A')){
			gamechange = Scenename::UNITSELECT;
		}
		gamechange = Scenename::GAMEMAIN;
		break;
	case Scenename::RESULT:

		break;
	}
}

Scenename Gamemanager::Titleshift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		//return Scenename::TITLE;
	}
	return Scenename::GAMEMANAGER;
	env.flushInput();
}

