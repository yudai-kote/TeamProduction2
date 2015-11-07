#include "Scenemanager.h"

Scenemanager::Scenemanager(){


}

void Scenemanager::Setup(){
	scenechange = Scenename::TITLE;
}


void Scenemanager::Update(){

	switch (scenechange)
	{
	case Scenename::TITLE:


		break;
	case Scenename::GAMEMANAGER:

		break;
	}
}

void Scenemanager::Draw(){


	switch (scenechange){
	case Scenename::TITLE:


		break;

	case Scenename::GAMEMANAGER:

		break;
	}
}


void Scenemanager::Shift(){

	switch (scenechange){
	case Scenename::TITLE:
		scenechange = title_.Shift();

		break;
	case Scenename::GAMEMANAGER:
		scenechange = gamemanager_.TitleShift();

		break;
	}
}