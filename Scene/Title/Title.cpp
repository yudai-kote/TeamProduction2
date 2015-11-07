#include "Title.h"

Title::Title(){



}


void Title::Setup(){




}

void Title::Update(){



}

void Title::Draw(){



}


Scenename Title::Shift(){

	if (env.isPushKey(GLFW_KEY_ENTER))
		return Scenename::GAMEMANAGER;
}