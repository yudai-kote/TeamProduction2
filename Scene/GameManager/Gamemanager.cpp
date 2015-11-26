#include "Gamemanager.h"

Gamemanager::Gamemanager(){
	gamechange = Scenename::UNITSELECT;
	
}


void Gamemanager::Setup(){

	for (auto itr = l_player.begin(); itr != l_player.end(); ++itr)
	{
		switch ((*itr)->GetNum()){
		case 1:
			(*itr)->SetUnitlistPos(Vec2i(0, 0));
			break;
		case 2:
			(*itr)->SetUnitlistPos(Vec2i(0, 2));
			break;
		case 3:
			(*itr)->SetUnitlistPos(Vec2i(0, 4));
			break;
		case 4:
			(*itr)->SetUnitlistPos(Vec2i(0, 6));
			break;
		case 5:
			(*itr)->SetUnitlistPos(Vec2i(0, 8));
			break;
		}

	}
	
	ui_.SetPlayerCost(50);
	ui_.SetUnitNum(1);
	turn = true;
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

		if (turn == true){
			
			cost = ui_.GetPlayerCost();
			for (auto itr = l_player.begin(); itr != l_player.end(); ++itr)
			{

				if ((*itr)->GetNum() == ui_.GetUnitNum()){

					if (!map_.Isunitmoving(ui_.GetUnitNum(), ui_.OperatePlayer())){
						(*itr)->Move(ui_.OperatePlayer());
						
						ui_.SetUnitPos((*itr)->GetPos());
					}
					if (ui_.IsAttacked()){
						//if (map_.Isattackhit(ui_.GetUnitNum(), )){
						//プレイヤーの攻撃力を見て、エネミーのHPを減らす

						//}
					}
					if (ui_.IsSkilled()){

						if (map_.Ismagichit(ui_.GetUnitNum(), ui_.GetUnitPos())){
							//プレイヤーのスキルの範囲と
						}
					}

				}

			}
			if (cost <= 0){
				turn = false;
			}
		}
		else if(turn == false){
			cost = 50;
			
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

		map_.DrawMagicrange(3);
		for (auto itr = l_player.begin(); itr != l_player.end(); ++itr)
		{
			map_.Drawcursolpos(ui_.GetUnitPos());
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
		Setup();
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

