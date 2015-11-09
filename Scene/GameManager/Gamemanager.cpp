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

		break;
	case Scenename::GAMEMAIN:

		break;
	case Scenename::RESULT:

		break;
	}
}

void Gamemanager::Draw(){
	switch (gamechange)
	{
	case Scenename::UNITSELECT:

		break;
	case Scenename::GAMEMAIN:
		gamemain_.Draw();
		break;
	case Scenename::RESULT:

		break;
	}


}


void Gamemanager::Shift(){
	switch (gamechange)
	{
	case Scenename::UNITSELECT:
		gamechange = unitselect_.Shift();
		break;
	case Scenename::GAMEMAIN:
		gamechange = gamemain_.Shift();
		break;
	case Scenename::RESULT:

		break;
	}
}

Scenename Gamemanager::Titleshift(){
	if (env.isPushKey(GLFW_KEY_ENTER)){
		return Scenename::TITLE;
	}
	return Scenename::GAMEMANAGER;
}
