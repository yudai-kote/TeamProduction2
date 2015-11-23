#include "Gamemanager.h"

Gamemanager::Gamemanager(){
	gamechange = Scenename::UNITSELECT;
	Setup();
}


void Gamemanager::Setup(){
	
	ui_.SetUnitNum(1);
	
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
		for (auto itr = l_player.begin(); itr != l_player.end(); ++itr)
		{
			if ((*itr)->GetNum() == ui_.GetUnitNum()){
				std::cout << (*itr)->GetNum() << std::endl;
				(*itr)->SetCanMove(!map_.Isunitmoving(ui_.GetUnitNum(), ui_.GetDir()));
				(*itr)->SetDirection(ui_.GetDir());


				if (ui_.IsAttacked()){
					if (map_.Isattackhit(ui_.GetUnitNum(), ui_.GetDir())){
						//プレイヤーの攻撃力を見て、エネミーのHPを減らす
					}
				}

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
		map_.Draw();
		for (auto itr = l_player.begin(); itr != l_player.end(); ++itr)
		{
			//std::cout << ui_.GetUnitNum() << std::endl;
			if ((*itr)->GetNum() == ui_.GetUnitNum()){
				ui_.Draw((*itr)->GetStatus());
			}
			(*itr)->Draw();
		}
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

