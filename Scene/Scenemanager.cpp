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
		gamemanager_.Shift();
		gamemanager_.Update();
		break;
	}
}

void Scenemanager::Draw(){


	switch (scenechange){
	case Scenename::TITLE:


		break;

	case Scenename::GAMEMANAGER:
		
		gamemanager_.Draw();
		break;
	}
}


void Scenemanager::Shift(){

	switch (scenechange){
	case Scenename::TITLE:
		scenechange = title_.Shift();

		break;
	case Scenename::GAMEMANAGER:
		
		scenechange = gamemanager_.Titleshift();
		break;
	}
}