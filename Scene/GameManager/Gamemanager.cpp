#include "Gamemanager.h"

int CompareCost(Vec2i _enemy_pos, Vec2i _player_pos, int& cost){
	int now_cost = std::abs(_enemy_pos.x() - _player_pos.x()) + std::abs(_enemy_pos.y() - _player_pos.y());

	if (now_cost < cost)
	{
		cost = now_cost;
	}
	return cost;
}

int NowCost(Vec2i _enemy_pos, Vec2i _player_pos){
	return std::abs(_enemy_pos.x() - _player_pos.x()) + std::abs(_enemy_pos.y() - _player_pos.y());
}

Gamemanager::Gamemanager(){
	gamechange = Scenename::UNITSELECT;

}


void Gamemanager::Setup(){


	for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
	{
		switch ((*playeritr)->GetNum()){
		case 1:
			(*playeritr)->SetUnitlistPos(Vec2i(0, 0));
			ui_.SetUnitPos((*playeritr)->GetPos());
			ui_.SetPDir((*playeritr)->GetDirection());
			break;
		case 2:
			(*playeritr)->SetUnitlistPos(Vec2i(0, 2));
			break;
		case 3:
			(*playeritr)->SetUnitlistPos(Vec2i(0, 4));
			break;
		case 4:
			(*playeritr)->SetUnitlistPos(Vec2i(0, 6));
			break;
		case 5:
			(*playeritr)->SetUnitlistPos(Vec2i(0, 8));
			break;
		}

	}
	for (int i = 6; i < 11; i++){
		l_enemy.push_back(new WarriorE(i));

	}
	for (auto enemyitr = l_enemy.begin(); enemyitr != l_enemy.end(); ++enemyitr)
	{
		switch ((*enemyitr)->GetNum()){
		case 6:
			(*enemyitr)->SetUnitlistPos(Vec2i(5, 0));
			break;
		case 7:
			(*enemyitr)->SetUnitlistPos(Vec2i(5, 2));
			break;
		case 8:
			(*enemyitr)->SetUnitlistPos(Vec2i(5, 4));
			break;
		case 9:
			(*enemyitr)->SetUnitlistPos(Vec2i(5, 6));
			break;
		case 10:
			(*enemyitr)->SetUnitlistPos(Vec2i(5, 8));
			break;
		}

		for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
		{
			(*enemyitr)->AstarSetup((*playeritr)->GetPos());
		}
		(*enemyitr)->SetAstarMap(map_.GetChipType());
	}
	for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
	{
		map_.Setplayerlist((*playeritr)->GetUnitlist());
	}
	for (auto enemyitr = l_enemy.begin(); enemyitr != l_enemy.end(); ++enemyitr)
	{
		map_.Setenemylist((*enemyitr)->GetUnitlist());
	}


	ui_.SetPlayerCost(10);
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

					ui_.SetUnitPos((*itr)->GetPos());
					ui_.SetPDir((*itr)->GetDirection());
					ui_.OperatePlayer();
					if (ui_.GetDirection()){
						(*itr)->Move(ui_.GetDir());
					}
					if (map_.Isunitmoving(ui_.GetUnitNum(), ui_.GetPDir())){
						(*itr)->Move(ui_.GetPDir());
						ui_.SetUnitPos((*itr)->GetPos());

					}
					if (ui_.IsAttacked()){
						//if (map_.Isattackhit(ui_.GetUnitNum(), )){
						//�v���C���[�̍U���͂����āA�G�l�~�[��HP�����炷

						//}
					}
					if (ui_.IsSkilled()){

						//if (map_.Ismagichit(ui_.GetUnitNum(), ui_.GetUnitPos())){
						//�v���C���[�̃X�L���͈̔͂�
						//}
					}

				}

			}
			if (cost <= 0){
				turn = false;
				first_move_end = false;
			}
		}
		else if (turn == false){
			cost = 50;



			if (first_move_end == true)
			{
				// �G�l�~�[�ƃv���C���[
				// �߂��ق��𔻒肵�Ēǂ�������
				for (auto enemyitr = l_enemy.begin(); enemyitr != l_enemy.end(); ++enemyitr)
				{
					int min_cost = 100000000;

					// �߂��̃v���C���[�𒲂ׂ�
					for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
					{
						CompareCost((*enemyitr)->GetPos(), (*playeritr)->GetPos(), min_cost);
					}
					for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
					{
						// ��ԏ������R�X�g�̃v���C���[�ɍċA��������
						if (min_cost == NowCost((*enemyitr)->GetPos(), (*playeritr)->GetPos()))
						{
							if ((*enemyitr--)->GetIsMove() == true){
								// �����ŃR�X�g�����炷
								(*enemyitr)->Update();
								(*enemyitr)->SetAstarPlayerPos((*playeritr)->GetPos());
								if (env.isPushKey(GLFW_KEY_SPACE)){
									if (map_.Isunitmoving((*enemyitr)->GetNum(), (*enemyitr)->GetDirection()) == true){
										//Astar�X�V
										(*enemyitr)->Move();
									}
								}
							}
						}
					}

					//�s�����I�����鏈��
					if (enemyitr == l_enemy.end() && (*enemyitr)->GetCost() < 0)
					{
						for (auto enemyitr = l_enemy.begin(); enemyitr != l_enemy.end(); ++enemyitr)
						{
							(*enemyitr)->SetIsMove(true);
							(*enemyitr)->SetCost(10);
						}
						turn = true;
					}
				}
			}

			// 
			if (first_move_end == false)
			{
				//��ԍŏ��ɓ����G�l�~�[
				for (auto enemyitr = l_enemy.begin(); enemyitr != l_enemy.end(); ++enemyitr)
				{
					if ((*enemyitr)->GetNum() == 6)
					{
						int min_cost = 100000000;

						// �߂��̃v���C���[�𒲂ׂ�
  						for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
						{
							CompareCost((*enemyitr)->GetPos(), (*playeritr)->GetPos(), min_cost);
						}
						for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
						{
							// ��ԏ������R�X�g�̃v���C���[�ɍċA��������
							if (min_cost == NowCost((*enemyitr)->GetPos(), (*playeritr)->GetPos()))
							{
								// �����ŃR�X�g�����炷
								(*enemyitr)->Update();
								(*enemyitr)->SetAstarPlayerPos((*playeritr)->GetPos());
								//std::cout << static_cast<int>((*enemyitr)->GetDirection()) << std::endl;
								if (env.isPushKey(GLFW_KEY_SPACE)){
									if (map_.Isunitmoving((*enemyitr)->GetNum(), (*enemyitr)->GetDirection()) == true){
										//Astar�X�V
										(*enemyitr)->Move();
										std::cout << static_cast<int>((*enemyitr)->GetDirection()) << std::endl;
										break;
									}
								}

							}
						}

						if ((*enemyitr)->GetCost() < 0)
						{
							first_move_end = true;
						}
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
		glPushMatrix();
		glTranslated(-(ui_.GetUnitPos().x()*CHIPSIZE_X), -(ui_.GetUnitPos().y()*CHIPSIZE_Y), 0);
		map_.Draw();


		map_.Drawcursolpos(ui_.GetUnitPos());
		for (auto playeritr = l_player.begin(); playeritr != l_player.end(); ++playeritr)
		{
			(*playeritr)->Draw();
		}
		for (auto enemyitr = l_enemy.begin(); enemyitr != l_enemy.end(); ++enemyitr)
		{
			(*enemyitr)->Draw();
		}
		glPopMatrix();
		for (auto itr = l_player.begin(); itr != l_player.end(); ++itr)
		{
			if ((*itr)->GetNum() == ui_.GetUnitNum()){
				ui_.Draw((*itr)->GetStatus());
			}
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
		if (env.isPushKey('A')){
			Setup();
		}
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

