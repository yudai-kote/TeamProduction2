#include "../GameManager/Gamemanager.h"

Gamemanager::Gamemanager(){



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

		break;
	case Scenename::RESULT:

		break;
	}


}


Scenename Gamemanager::TitleShift(){
	if (env.isPushKey(GLFW_KEY_ENTER))
		return Scenename::TITLE;
}